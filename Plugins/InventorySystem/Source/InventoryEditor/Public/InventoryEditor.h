// © 2024, Arcane Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Actions/InventoryAssetTypeActions.h"

class FInventoryEditor : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	void StartupModule() override;
	void ShutdownModule() override;
	
private:
	TSharedPtr<FInventoryAssetTypeActions> InventoryAssetTypeActions;

	EAssetTypeCategories::Type InventoryAssetCategory;
};
