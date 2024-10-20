// © 2024, Arcane Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "GraphicsSettings.generated.h"

class UComboBoxString;
class USelectionBase;

UENUM(BlueprintType)
enum class EFramerate : uint8
{
	FPS_30 UMETA(DisplayName = "30"),
	FPS_60 UMETA(DisplayName = "60"),
	FPS_120 UMETA(DisplayName = "120"),
	FPS_144 UMETA(DisplayName = "144"),
	FPS_240 UMETA(DisplayName = "240"),
	FPS_360 UMETA(DisplayName = "360"),
	FPS_Uncapped UMETA(DisplayName = "Uncapped"),
};

/**
 * 
 */
UCLASS()
class ARCANESTUDIOSCORE_API UGraphicsSettings : public UCommonActivatableWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;
	virtual UWidget* NativeGetDesiredFocusTarget() const override;

protected:
	void InitializeResolutionComboBox();
	void InitializeVSync();
	void InitializeFramerate();

	UFUNCTION()
	void OnResolutionChanged(FString InSelectedItem, ESelectInfo::Type InSelectionType);

	UPROPERTY()
	TObjectPtr<UGameUserSettings> GameUserSettings;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	TObjectPtr<UComboBoxString> ResolutionComboBox;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<USelectionBase> VSyncSelection;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<USelectionBase> FramerateSelection;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<USelectionBase> ShadingQualitySelection;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<USelectionBase> GlobalIlluminationQualitySelection;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<USelectionBase> PostProcessingQualitySelection;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<USelectionBase> VisualEffectsQualitySelection;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<USelectionBase> ShadowQualitySelection;

	UPROPERTY()
	TArray<FIntPoint> Resolutions;
};
