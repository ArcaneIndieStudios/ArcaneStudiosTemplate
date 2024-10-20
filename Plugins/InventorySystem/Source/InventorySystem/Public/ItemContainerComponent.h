// © 2024, Arcane Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryItemBase.h"
#include "ItemContainerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FContainerContentChanged);

UCLASS( ClassGroup=(Container), meta=(BlueprintSpawnableComponent) )
class INVENTORYSYSTEM_API UItemContainerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UItemContainerComponent();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

public:
	UFUNCTION()
	void OnRep_ContainerContentChanged();

	UPROPERTY(BlueprintAssignable)
		FContainerContentChanged ContainerContentChanged;

	// --Core Functions-- //
	UFUNCTION(Category = "Arcane Studios|Inventory")
	FInventoryItem AddItemToSlot(FInventoryItem ItemToAdd, int Index);

	UFUNCTION(Category = "Arcane Studios|Inventory")
	void RemoveQuantityFromSlot(int Index, int QuanityToRemove);

	UFUNCTION(Category = "Arcane Studios|Inventory")
	inline void SetSlot(FInventoryItem NewItem, int Index) { ContainerContent[Index] = NewItem; }

	// --Helper Functions-- //
	UFUNCTION(BlueprintCallable, Category = "Arcane Studios|Inventory|Helper")
	int GetSlotWithSpace(UInventoryItemBase* ItemToFind);

	UFUNCTION(BlueprintCallable, Category = "Arcane Studios|Inventory|Helper")
	int GetEmptySlot();

	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Arcane Studios|Inventory|Helper")
	inline bool HasSpace() { return GetEmptySlot() != -1; }

	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Arcane Studios|Inventory|Helper")
	inline FInventoryItem GetSlotItem(int Index) { return ContainerContent[Index]; }

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Arcane Studios|Inventory", meta = (AllowPrivateAccess="true"))
	int ContainerSize = 36;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Arcane Studios|Inventory", meta = (AllowPrivateAccess = "true"), ReplicatedUsing = OnRep_ContainerContentChanged);
	TArray<FInventoryItem> ContainerContent;

};
