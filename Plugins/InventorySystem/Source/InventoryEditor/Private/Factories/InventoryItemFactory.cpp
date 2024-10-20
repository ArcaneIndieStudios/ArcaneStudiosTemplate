// © 2024, Arcane Studios. All rights reserved.


#include "Factories/InventoryItemFactory.h"
#include "UnrealEd.h"
#include "ClassViewerModule.h"
#include <Kismet2/SClassPickerDialog.h>

// Item Classes
#include "ItemTypes/Resource.h"
#include "ItemTypes/Consumable.h"
#include "ItemTypes/Armament.h"
#include "ItemTypes/Garment.h"

UInventoryItemFactory::UInventoryItemFactory()
{
	SupportedClass = UInventoryItemBase::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UInventoryItemFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	if(IsValid(InventoryItemClass))
		return NewObject<UInventoryItemBase>(InParent, InventoryItemClass, InName, Flags);

	checkf(InClass->IsChildOf(UInventoryItemBase::StaticClass()), TEXT("Invalid Class Type, Must be a Child of UInventoryItemBase."));

	return NewObject<UInventoryItemBase>(InParent, InClass, InName, Flags);
}

bool UInventoryItemFactory::ConfigureProperties()
{
	InventoryItemClass = nullptr;
	FClassViewerModule& ClassViewerModule = FModuleManager::LoadModuleChecked<FClassViewerModule>("ClassViewer");
	FClassViewerInitializationOptions Options;
	Options.Mode = EClassViewerMode::ClassPicker;
	Options.DisplayMode = EClassViewerDisplayMode::ListView;
	Options.ExtraPickerCommonClasses = { UResource::StaticClass(), UConsumable::StaticClass(), UArmament::StaticClass(), UGarment::StaticClass() };

	const TSharedRef<IItemObjectViewerFilter> Filter = MakeShared<IItemObjectViewerFilter>();
	Options.ClassFilters.AddUnique(Filter);

	Filter->DisallowedClassFlags = CLASS_Abstract | CLASS_Deprecated | CLASS_NewerVersionExists;

	const FText Title = FText::FromString("Pick Inventory Item Class");
	UClass* ChosenClass = nullptr;
	const bool bPressedOk = SClassPickerDialog::PickClass(Title, Options, ChosenClass, UInventoryItemBase::StaticClass());

	if (bPressedOk)
		InventoryItemClass = ChosenClass;

	return bPressedOk;
}