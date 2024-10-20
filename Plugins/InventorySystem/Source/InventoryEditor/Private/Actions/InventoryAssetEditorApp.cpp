// © 2024, Arcane Studios. All rights reserved.

#include "Actions/InventoryAssetEditorApp.h"
#include "Factories/InventoryAssetAppMode.h"
#include "InventoryItemBase.h"

void InventoryAssetEditorApp::RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	FWorkflowCentricApplication::RegisterTabSpawners(InTabManager);
}

void InventoryAssetEditorApp::InitEditor(const EToolkitMode::Type Mode, const TSharedPtr<class IToolkitHost>& InitToolkitHost, UObject* InObject)
{
    TArray<UObject*> objectsToEdit;
    objectsToEdit.Add(InObject);

    WorkingAsset = Cast<UInventoryItemBase>(InObject);

    InitAssetEditor(
        Mode,
        InitToolkitHost,
        TEXT("InventoryAssetEditor"),
        FTabManager::FLayout::NullLayout,
        true, // createDefaultStandaloneMenu 
        true,  // createDefaultToolbar
        objectsToEdit);

    // Add our modes (just one for this example)
    AddApplicationMode(TEXT("InventoryAssetAppMode"), MakeShareable(new InventoryAssetAppMode(SharedThis(this))));

    // Set the mode
    SetCurrentMode(TEXT("InventoryAssetAppMode"));
}
