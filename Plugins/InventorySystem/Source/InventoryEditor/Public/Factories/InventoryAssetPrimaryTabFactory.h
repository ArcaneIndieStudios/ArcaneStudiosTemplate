// © 2024, Arcane Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "WorkflowOrientedApp/WorkflowTabFactory.h"

/**
 * 
 */
class INVENTORYEDITOR_API InventoryAssetPrimaryTabFactory : public FWorkflowTabFactory
{
public:
	InventoryAssetPrimaryTabFactory(TSharedPtr<class InventoryAssetEditorApp> app);

	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
	virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;

protected:
	TWeakPtr<class InventoryAssetEditorApp> App;
};
