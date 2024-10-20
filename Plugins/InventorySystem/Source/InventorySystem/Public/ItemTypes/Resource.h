// © 2024, Arcane Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItemBase.h"
#include "Resource.generated.h"

/**
 * These Items can be Used For Crafting, Building Various Item and Can even use them as Fuel
 */
UCLASS()
class INVENTORYSYSTEM_API UResource : public UInventoryItemBase
{
	GENERATED_BODY()
	
public:
	EItemType ItemType() override { return EItemType::Resource; }
};
