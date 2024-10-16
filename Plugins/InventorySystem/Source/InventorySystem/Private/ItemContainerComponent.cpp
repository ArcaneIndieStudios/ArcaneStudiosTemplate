// © 2024, Arcane Studios. All rights reserved.

#include "ItemContainerComponent.h"
#include "Net/UnrealNetwork.h"

UItemContainerComponent::UItemContainerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	SetIsReplicatedByDefault(true);

	ContainerContent.Reset();
	ContainerContent.Init(FInventoryItem(), ContainerSize);
}

void UItemContainerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UItemContainerComponent, ContainerContent, COND_None, REPNOTIFY_Always);
}

void UItemContainerComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	ContainerContent.Reset();
	ContainerContent.Init(FInventoryItem(), ContainerSize);
}

void UItemContainerComponent::OnRep_ContainerContentChanged()
{
	ContainerContentChanged.Broadcast();
}

FInventoryItem UItemContainerComponent::AddItemToSlot(FInventoryItem ItemToAdd, int Index)
{
	FInventoryItem ItemLeft = ItemToAdd;
	int TargetIndex = Index;

	if (TargetIndex == -1)
	{
		TargetIndex = GetSlotWithSpace(ItemLeft.ItemData);

		if (TargetIndex == -1)
			TargetIndex = GetEmptySlot();

		if (TargetIndex == -1)
			return ItemLeft;
	}
	else
	{
		FInventoryItem& SlotItem = ContainerContent[TargetIndex];

		if (SlotItem.ItemData == nullptr)
			SetSlot(ItemLeft, TargetIndex);

		if (SlotItem.ItemData == ItemLeft.ItemData)
		{
			int NewStackSize = SlotItem.Quantity + ItemLeft.Quantity;

			if (NewStackSize > SlotItem.ItemData->StackSize)
			{
				SlotItem.Quantity = SlotItem.ItemData->StackSize;
				ItemLeft.Quantity = FMath::Clamp(NewStackSize - SlotItem.ItemData->StackSize, 0, SlotItem.ItemData->StackSize);
			}
			else
			{
				SlotItem.Quantity = NewStackSize;
				ItemLeft.Quantity = 0;
			}

			return ItemLeft;
		}
		else
		{
			TargetIndex = GetEmptySlot();

			if (TargetIndex == -1)
				return ItemLeft;
			else
				SetSlot(ItemLeft, TargetIndex);
		}
	}

	return FInventoryItem();
}

void UItemContainerComponent::RemoveQuantityFromSlot(int Index, int QuanityToRemove)
{
	FInventoryItem& SlotItem = ContainerContent[Index];

	SlotItem.Quantity -= FMath::Clamp(SlotItem.Quantity - QuanityToRemove, 0, SlotItem.ItemData->StackSize);

	if (SlotItem.Quantity == 0)
		SetSlot(FInventoryItem(), Index);
}

int UItemContainerComponent::GetSlotWithSpace(UInventoryItemBase* ItemToFind)
{
	int Index = 0;

	for (FInventoryItem ContainerItem : ContainerContent)
	{
		if (ContainerItem.ItemData == nullptr)
		{
			Index++;
			continue;
		}

		if (ContainerItem.ItemData == ItemToFind && ContainerItem.Quantity < ContainerItem.ItemData->StackSize)
			return Index;
	}

	return -1;
}

int UItemContainerComponent::GetEmptySlot()
{
	int Index = 0;

	for (FInventoryItem ContainerItem : ContainerContent)
	{
		if (ContainerItem.ItemData == nullptr)
			return Index;

		Index++;
	}

	return -1;
}
