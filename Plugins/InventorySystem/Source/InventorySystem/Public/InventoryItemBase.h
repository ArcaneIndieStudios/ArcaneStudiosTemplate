// © 2024, Arcane Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InventoryItemBase.generated.h"

/**
 * 
 */
UCLASS(Abstract, NotBlueprintable)
class INVENTORYSYSTEM_API UInventoryItemBase : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Information")
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Information")
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Information|Inventory")
	UTexture2D* Icon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Information|Inventory")
	int32 StackSize;
	
};
