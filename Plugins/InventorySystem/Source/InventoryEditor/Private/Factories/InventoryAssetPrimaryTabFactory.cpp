// © 2024, Arcane Studios. All rights reserved.

#include "Factories/InventoryAssetPrimaryTabFactory.h"
#include "Actions/InventoryAssetEditorApp.h"
#include "InventoryItemBase.h"
#include "IDetailsView.h"
#include "PropertyEditorModule.h"

InventoryAssetPrimaryTabFactory::InventoryAssetPrimaryTabFactory(TSharedPtr<class InventoryAssetEditorApp> app) : FWorkflowTabFactory(FName("Details"), app), App(app)
{
	TabLabel = FText::FromString(TEXT("Details"));

	ViewMenuDescription = FText::FromString(TEXT("Displays The Details of the Inventory Item Asset."));
	ViewMenuTooltip = FText::FromString(TEXT("Show the Details view."));
}

TSharedRef<SWidget> InventoryAssetPrimaryTabFactory::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
    TSharedPtr<InventoryAssetEditorApp> app = App.Pin();
    FPropertyEditorModule& propertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));

    FDetailsViewArgs detailsViewArgs;
    {
        detailsViewArgs.bAllowSearch = false;
        detailsViewArgs.bHideSelectionTip = true;
        detailsViewArgs.bLockable = false;
        detailsViewArgs.bSearchInitialKeyFocus = true;
        detailsViewArgs.bUpdatesFromSelection = false;
        detailsViewArgs.NotifyHook = nullptr;
        detailsViewArgs.bShowOptions = true;
        detailsViewArgs.bShowModifiedPropertiesOption = true;
        detailsViewArgs.bShowScrollBar = false;
    }

    TSharedPtr<IDetailsView> detailsView = propertyEditorModule.CreateDetailView(detailsViewArgs);
    detailsView->SetObject(app->GetWorkingAsset());

    return SNew(SVerticalBox)
        + SVerticalBox::Slot()
        .FillHeight(1.0f)
        .HAlign(HAlign_Fill)
        [
            detailsView.ToSharedRef()
        ];
}

FText InventoryAssetPrimaryTabFactory::GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const
{
    return FText::FromString(TEXT("A View to Edit the Default Properties of The Inventory Item."));
}
