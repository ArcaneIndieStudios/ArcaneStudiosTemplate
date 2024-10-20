// © 2024, Arcane Studios. All rights reserved.


#include "PlayerInventoryComponent.h"

UPlayerInventoryComponent::UPlayerInventoryComponent()
{
	ContainerSize = 48;
}

void UPlayerInventoryComponent::AddItemToContainer_Implementation(UItemContainerComponent* TargetContainer, FInventoryItem ItemToAdd, int Index)
{
	FInventoryItem ItemLeft = ItemToAdd;

	while ((TargetContainer->HasSpace() || TargetContainer->GetSlotWithSpace(ItemLeft.ItemData) != -1) && (ItemLeft.Quantity > 0 || ItemLeft.ItemData != nullptr))
	{
		ItemLeft = TargetContainer->AddItemToSlot(ItemLeft, Index);

		if (ItemLeft.Quantity <= 0)
			break;
	}

	if (ItemLeft.Quantity > 0)
		DropItem(ItemLeft);

	if (TargetContainer == this)
		CallItemAddedorRemovedDelegate(FInventoryItem(ItemToAdd.ItemData, ItemToAdd.Quantity - ItemLeft.Quantity), true);
}

void UPlayerInventoryComponent::RemoveQuanityFromContainerSlot_Implementation(UItemContainerComponent* TargetContainer, int Index, int QuanityToRemove)
{
	TargetContainer->RemoveQuantityFromSlot(Index, QuanityToRemove);

	if (TargetContainer == this)
		CallItemAddedorRemovedDelegate(FInventoryItem(TargetContainer->GetSlotItem(Index).ItemData, QuanityToRemove), false);
}

void UPlayerInventoryComponent::RemoveSlot_Implementation(UItemContainerComponent* TargetContainer, int Index)
{
	FInventoryItem RemovedItem = TargetContainer->GetSlotItem(Index);

	TargetContainer->SetSlot(FInventoryItem(), Index);

	if (TargetContainer == this)
		CallItemAddedorRemovedDelegate(RemovedItem, false);
}

void UPlayerInventoryComponent::OverrideSlot_Implementation(UItemContainerComponent* TargetContainer, FInventoryItem Item, int Index)
{
	TargetContainer->SetSlot(Item, Index);

	if (TargetContainer == this)
		CallItemAddedorRemovedDelegate(Item, true);

}

void UPlayerInventoryComponent::DropItem_Implementation(FInventoryItem ItemToDrop)
{
	UE_LOG(LogTemp, Warning, TEXT("Drop Item : Not Implemented!"));
}

void UPlayerInventoryComponent::CallItemAddedorRemovedDelegate_Implementation(FInventoryItem Item, bool Added)
{
	if (Added)
		ItemAdded.Broadcast(Item);
	else
		ItemRemoved.Broadcast(Item);
}
