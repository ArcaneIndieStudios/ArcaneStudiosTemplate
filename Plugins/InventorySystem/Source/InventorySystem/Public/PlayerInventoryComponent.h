// © 2024, Arcane Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "ItemContainerComponent.h"
#include "PlayerInventoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FItemAddedorRemoved, FInventoryItem, Item);

/**
 * 
 */
UCLASS(ClassGroup = (Inventory), meta = (BlueprintSpawnableComponent))
class INVENTORYSYSTEM_API UPlayerInventoryComponent : public UItemContainerComponent
{
	GENERATED_BODY()

public:
	UPlayerInventoryComponent();

	UPROPERTY(BlueprintAssignable)
	FItemAddedorRemoved ItemAdded;

	UPROPERTY(BlueprintAssignable)
	FItemAddedorRemoved ItemRemoved;

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Arcane Studios|Inventory|Server")
	void AddItemToContainer(UItemContainerComponent* TargetContainer, FInventoryItem ItemToAdd, int Index);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Arcane Studios|Inventory|Server")
	void RemoveQuanityFromContainerSlot(UItemContainerComponent* TargetContainer, int Index, int QuanityToRemove);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Arcane Studios|Inventory|Server")
	void RemoveSlot(UItemContainerComponent* TargetContainer, int Index);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Arcane Studios|Inventory|Server")
	void OverrideSlot(UItemContainerComponent* TargetContainer, FInventoryItem Item, int Index);

	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "Arcane Studios|Inventory|Server")
	void DropItem(FInventoryItem ItemToDrop);

private:
	UFUNCTION(Client, Reliable, Category = "Arcane Studios|Inventory|OwningClient")
	void CallItemAddedorRemovedDelegate(FInventoryItem Item, bool Added);
};
