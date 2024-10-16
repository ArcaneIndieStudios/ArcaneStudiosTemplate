// © 2024, Arcane Studios. All rights reserved.

#include "InventoryEditor.h"
#include "Logging.h"
#include "AssetToolsModule.h"
#include "IAssetTools.h"
#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "FInventoryEditor"

void FInventoryEditor::StartupModule()
{
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	InventoryAssetCategory = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("Arcane Studios")), LOCTEXT("Inventory", "Arcane Studios"));

	InventoryAssetTypeActions = MakeShared<FInventoryAssetTypeActions>(InventoryAssetCategory);
	FAssetToolsModule::GetModule().Get().RegisterAssetTypeActions(InventoryAssetTypeActions.ToSharedRef());
}

void FInventoryEditor::ShutdownModule()
{
	if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
		FAssetToolsModule::GetModule().Get().UnregisterAssetTypeActions(InventoryAssetTypeActions.ToSharedRef());
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FInventoryEditor, InventoryEditor);