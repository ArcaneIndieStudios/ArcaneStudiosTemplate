// © 2024, Arcane Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "InventoryItemBase.h"
#include "ClassViewerFilter.h"

#include "InventoryItemFactory.generated.h"

class UInventoryItemBase;

/**
 * 
 */
UCLASS()
class INVENTORYEDITOR_API UInventoryItemFactory : public UFactory
{
	GENERATED_BODY()
	
public:
	UInventoryItemFactory();

	// Inherited via UFactory
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext) override;
	virtual bool ConfigureProperties() override;

private:

	UPROPERTY(EditAnywhere, Category = "Inventory Item")
	TSubclassOf<UInventoryItemBase> InventoryItemClass;

};

class IItemObjectViewerFilter : public IClassViewerFilter
{
public:
	TSet<const UClass*> AllowedChildrenOfClasses;
	EClassFlags DisallowedClassFlags = CLASS_Abstract | CLASS_Deprecated | CLASS_NewerVersionExists;

private:
	virtual bool IsClassAllowed(const FClassViewerInitializationOptions& InInitOptions, const UClass* InClass, TSharedRef< class FClassViewerFilterFuncs > InFilterFuncs) override
	{
		if (InClass->IsChildOf(UInventoryItemBase::StaticClass()) && !InClass->HasAnyClassFlags(DisallowedClassFlags))
			return true;

		return InFilterFuncs->IfInChildOfClassesSet(AllowedChildrenOfClasses, InClass) == EFilterReturn::Passed;
	}

	virtual bool IsUnloadedClassAllowed(const FClassViewerInitializationOptions& InInitOptions, const TSharedRef<const class IUnloadedBlueprintData> InUnloadedClassData, TSharedRef<class FClassViewerFilterFuncs> InFilterFuncs) override
	{
		if (InUnloadedClassData->IsChildOf(UInventoryItemBase::StaticClass()) && !InUnloadedClassData->HasAnyClassFlags(DisallowedClassFlags))
			return true;

		return InFilterFuncs->IfInChildOfClassesSet(AllowedChildrenOfClasses, InUnloadedClassData) == EFilterReturn::Passed;
	}

};