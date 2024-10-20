// © 2024, Arcane Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "WorkflowOrientedApp/ApplicationMode.h"
#include "WorkflowOrientedApp/WorkflowTabManager.h"

/**
 * 
 */
class INVENTORYEDITOR_API InventoryAssetAppMode : public FApplicationMode
{
public:
	InventoryAssetAppMode(TSharedPtr<class InventoryAssetEditorApp> app);

	virtual void RegisterTabFactories(TSharedPtr<class FTabManager> InTabManager) override;
	virtual void PreDeactivateMode() override;
	virtual void PostActivateMode() override;

protected:
	TWeakPtr<class InventoryAssetEditorApp> App;
	FWorkflowAllowedTabSet Tabs;
};
