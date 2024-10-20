// © 2024, Arcane Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InventoryItemBase.generated.h"

UENUM(BlueprintType)
enum class EItemType : uint8
{
	None UMETA(DisplayName = "None"),
	Armament UMETA(DisplayName = "Armament"),
	Consumable UMETA(DisplayName = "Consumable"),
	Garment UMETA(DisplayName = "Garment"),
	Resource UMETA(DisplayName = "Resource")
};

USTRUCT(BlueprintType)
struct FInventoryItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInventoryItemBase* ItemData = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Quantity = 0;

	FInventoryItem()
	{
		ItemData = nullptr;
		Quantity = 0;
	}

	FInventoryItem(UInventoryItemBase* ItemData, int ItemQuantity)
	{
		ItemData = ItemData;
		Quantity = ItemQuantity;
	}
};

/**
 * 
 */
UCLASS(ClassGroup = (Inventory), Abstract, NotBlueprintable)
class INVENTORYSYSTEM_API UInventoryItemBase : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Arcane Studios|Inventory")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Arcane Studios|Inventory")
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Arcane Studios|Inventory")
	TSoftObjectPtr<UTexture2D> Icon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Arcane Studios|Inventory")
	int32 StackSize;

	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Arcane Studios|Inventory|Item")
	virtual EItemType ItemType() { return EItemType::None; }
};
