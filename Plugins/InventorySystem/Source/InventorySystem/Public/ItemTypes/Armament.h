// © 2024, Arcane Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItemBase.h"
#include "Armament.generated.h"

/**
 * Tools or Weapons which can be used to Gather Resources or Attack Things
 */
UCLASS()
class INVENTORYSYSTEM_API UArmament : public UInventoryItemBase
{
	GENERATED_BODY()
	
public:
	EItemType ItemType() override { return EItemType::Armament; }
};
