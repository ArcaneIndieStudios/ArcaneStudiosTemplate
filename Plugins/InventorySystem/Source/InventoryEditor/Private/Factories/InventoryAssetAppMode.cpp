// © 2024, Arcane Studios. All rights reserved.

#include "Factories/InventoryAssetAppMode.h"
#include "Actions/InventoryAssetEditorApp.h"
#include "Factories/InventoryAssetPrimaryTabFactory.h"

InventoryAssetAppMode::InventoryAssetAppMode(TSharedPtr<class InventoryAssetEditorApp> app) : FApplicationMode("InventoryAssetAppMode"), App(app)
{
	Tabs.RegisterFactory(MakeShareable(new InventoryAssetPrimaryTabFactory(app)));

	TabLayout = FTabManager::NewLayout("InventoryAssetAppMode_Layout_v1")
		->AddArea
		(
		FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
		->Split
		(
		FTabManager::NewStack()
		->AddTab(FName(TEXT("Details")), ETabState::OpenedTab)
		)
		);
}

void InventoryAssetAppMode::RegisterTabFactories(TSharedPtr<class FTabManager> InTabManager)
{
	TSharedPtr<InventoryAssetEditorApp> app = App.Pin();
	app->PushTabFactories(Tabs);
	FApplicationMode::RegisterTabFactories(InTabManager);
}

void InventoryAssetAppMode::PreDeactivateMode()
{
	FApplicationMode::PreDeactivateMode();
}

void InventoryAssetAppMode::PostActivateMode()
{
	FApplicationMode::PostActivateMode();
}
