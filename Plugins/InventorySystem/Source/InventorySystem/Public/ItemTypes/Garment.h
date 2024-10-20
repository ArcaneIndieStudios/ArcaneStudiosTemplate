// © 2024, Arcane Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItemBase.h"
#include "Garment.generated.h"

/**
 * Clothing and Armor used for Protection against Weather and Enemies
 */
UCLASS()
class INVENTORYSYSTEM_API UGarment : public UInventoryItemBase
{
	GENERATED_BODY()

public:
	EItemType ItemType() override { return EItemType::Garment; }
};
