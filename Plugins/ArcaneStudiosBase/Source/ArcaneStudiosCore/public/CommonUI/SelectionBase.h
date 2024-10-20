// © 2024, Arcane Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "SelectionBase.generated.h"

class UCommonTextBlock;

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class ARCANESTUDIOSCORE_API USelectionBase : public UCommonUserWidget
{
	GENERATED_BODY()
	
public:
	USelectionBase();
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;

	void Clear();
	void AddOption(const FText& InOption);
	void SetCurrentSelection(int InIndex);

	UFUNCTION(BlueprintCallable)
	void SelectPrevious();

	UFUNCTION(BlueprintCallable)
	void SelectNext();

	DECLARE_DELEGATE_OneParam(FOnSelectionChange, int);
	FOnSelectionChange OnSelectionChange;

protected:
	UFUNCTION()
	UWidget* OnNavigation(EUINavigation InNavigation);

	void UpdateCurrentSelection();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FText> Options;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<UCommonTextBlock> Label;

	int CurrentSelection;
};
