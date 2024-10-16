// © 2024, Arcane Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItemBase.h"
#include "Consumable.generated.h"

/**
 * Can be Consumed to Replenish Health, Hunger, Thirst, Mana etc.
 */
UCLASS()
class INVENTORYSYSTEM_API UConsumable : public UInventoryItemBase
{
	GENERATED_BODY()

public:
	EItemType ItemType() override { return EItemType::Consumable; }
};
