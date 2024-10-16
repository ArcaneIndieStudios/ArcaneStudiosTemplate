// © 2024, Arcane Studios. All rights reserved.


#include "Actions/InventoryAssetTypeActions.h"
#include "Actions/InventoryAssetEditorApp.h"
#include "InventoryItemBase.h"

FInventoryAssetTypeActions::FInventoryAssetTypeActions(EAssetTypeCategories::Type InAssetCategory)
{
	InventoryAssetCategory = InAssetCategory;
}

FText FInventoryAssetTypeActions::GetName() const
{
	return INVTEXT("Inventory Item");
}

UClass* FInventoryAssetTypeActions::GetSupportedClass() const
{
	return UInventoryItemBase::StaticClass();
}

FColor FInventoryAssetTypeActions::GetTypeColor() const
{
	return FColor::Cyan;
}

void FInventoryAssetTypeActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor)
{
	EToolkitMode::Type mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;
	for (UObject* object : InObjects)
	{
		UInventoryItemBase* inventoryItem = Cast<UInventoryItemBase>(object);
		if (inventoryItem != nullptr)
		{
			TSharedRef<InventoryAssetEditorApp> editor(new InventoryAssetEditorApp());
			editor->InitEditor(mode, EditWithinLevelEditor, inventoryItem);
		}
	}
}

uint32 FInventoryAssetTypeActions::GetCategories()
{
	return InventoryAssetCategory;
}

const TArray<FText>& FInventoryAssetTypeActions::GetSubMenus() const
{
	static const TArray<FText> SubMenus
	{
		INVTEXT("Inventory")
	};

	return SubMenus;
}
