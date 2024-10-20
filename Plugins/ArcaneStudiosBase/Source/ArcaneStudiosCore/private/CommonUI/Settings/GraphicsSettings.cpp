// © 2024, Arcane Studios. All rights reserved.

#include "CommonUI/Settings/GraphicsSettings.h"

#include "GameFramework/GameUserSettings.h"
#include "Kismet/KismetSystemLibrary.h"

// --Components-- //
#include "Components/ComboBoxString.h"
#include "CommonUI/SelectionBase.h"

namespace
{
	class FFramerateUtils
	{
	public:
		static int EnumToValue(const EFramerate& InFramerate)
		{
			switch (InFramerate)
			{
				case EFramerate::FPS_30: return 30;
				case EFramerate::FPS_60: return 60;
				case EFramerate::FPS_120: return 120;
				case EFramerate::FPS_144: return 144;
				case EFramerate::FPS_240: return 240;
				case EFramerate::FPS_360: return 360;
				case EFramerate::FPS_Uncapped: return 0;
				default: return 0;
			}
		}

		static FString EnumToString(const EFramerate& InFramerate)
		{
			switch (InFramerate)
			{
				case EFramerate::FPS_30: return "30";
				case EFramerate::FPS_60: return "60";
				case EFramerate::FPS_120: return "120";
				case EFramerate::FPS_144: return "144";
				case EFramerate::FPS_240: return "240";
				case EFramerate::FPS_360: return "360";
				case EFramerate::FPS_Uncapped: return "Uncapped";
				default: return "Uncapped";
			}
		}
	};

	constexpr EFramerate FramerateOptions[] =
	{
		EFramerate::FPS_30,
		EFramerate::FPS_60,
		EFramerate::FPS_120,
		EFramerate::FPS_144,
		EFramerate::FPS_240,
		EFramerate::FPS_360,
		EFramerate::FPS_Uncapped
	};

	typedef int32(UGameUserSettings::*GetFunc)() const;
	typedef void(UGameUserSettings::*SetFunc)(int);
	struct FSelectionElement
	{
		USelectionBase* Widget;
		GetFunc GetFunc;
		SetFunc SetFunc;
	};
}

void UGraphicsSettings::NativeConstruct()
{
	Super::NativeConstruct();

	GameUserSettings = UGameUserSettings::GetGameUserSettings();

	InitializeResolutionComboBox();
	InitializeVSync();
	InitializeFramerate();

	const FSelectionElement SelectionElements[] = {
		{ ShadingQualitySelection, &UGameUserSettings::GetShadingQuality, &UGameUserSettings::SetShadingQuality },
		{ GlobalIlluminationQualitySelection, &UGameUserSettings::GetGlobalIlluminationQuality, &UGameUserSettings::SetGlobalIlluminationQuality },
		{ PostProcessingQualitySelection, &UGameUserSettings::GetPostProcessingQuality, &UGameUserSettings::SetPostProcessingQuality },
		{ VisualEffectsQualitySelection, &UGameUserSettings::GetVisualEffectQuality, &UGameUserSettings::SetVisualEffectQuality },
		{ ShadowQualitySelection, &UGameUserSettings::GetShadowQuality, &UGameUserSettings::SetShadowQuality },
	};

	for (const auto& [Widget, GetFunc, SetFunc] : SelectionElements)
	{
		const auto CurrentSelection = std::invoke(GetFunc, GameUserSettings);
		Widget->SetCurrentSelection(CurrentSelection);
		Widget->OnSelectionChange.BindLambda([ this, SetFunc ](int InSelection)
		{
			std::invoke(SetFunc, GameUserSettings, InSelection);
			GameUserSettings->ApplySettings(false);
		});
	}
}

UWidget* UGraphicsSettings::NativeGetDesiredFocusTarget() const
{
	return ResolutionComboBox;
}

void UGraphicsSettings::InitializeResolutionComboBox()
{
	Resolutions.Empty();
	UKismetSystemLibrary::GetSupportedFullscreenResolutions(Resolutions);

	ResolutionComboBox->OnSelectionChanged.Clear();
	ResolutionComboBox->ClearOptions();

	for (const FIntPoint& Resolution : Resolutions)
	{
		const auto ResolutionString = FString::Printf(TEXT("%dx%d"), Resolution.X, Resolution.Y);
		ResolutionComboBox->AddOption(ResolutionString);
	}

	const auto CurrentResolution = GameUserSettings->GetScreenResolution();
	const auto SelectedIndex = Resolutions.IndexOfByPredicate([ &CurrentResolution ](const FIntPoint& InResolution)
	{
		return InResolution == CurrentResolution;
	});

	if (SelectedIndex < 0) return;
	ResolutionComboBox->SetSelectedIndex(SelectedIndex);

	ResolutionComboBox->OnSelectionChanged.AddDynamic(this, &UGraphicsSettings::OnResolutionChanged);
}

void UGraphicsSettings::InitializeVSync()
{
	VSyncSelection->SetCurrentSelection(GameUserSettings->IsVSyncEnabled());
	VSyncSelection->OnSelectionChange.BindLambda([ this ](const int InNewValue)
	{
		GameUserSettings->SetVSyncEnabled(bool(InNewValue));
		GameUserSettings->ApplySettings(false);
	});
}

void UGraphicsSettings::InitializeFramerate()
{
	FramerateSelection->Clear();

	int FramerateOptionIndex = 0;

	const auto CurrentFramerate = GameUserSettings->GetFrameRateLimit();
	for (const auto& Framerate : FramerateOptions)
	{
		FramerateSelection->AddOption(
			{ 
				FText::FromString(FFramerateUtils::EnumToString(Framerate)) 
			});

		if (CurrentFramerate == FFramerateUtils::EnumToValue(Framerate))
			FramerateSelection->SetCurrentSelection(FramerateOptionIndex);

		FramerateOptionIndex++;
	}

	FramerateSelection->OnSelectionChange.BindLambda([ this ](const int InSelection)
	{
		GameUserSettings->SetFrameRateLimit(FFramerateUtils::EnumToValue(
			FramerateOptions[InSelection]
		));

		GameUserSettings->ApplySettings(false);
	});
}

void UGraphicsSettings::OnResolutionChanged(FString InSelectedItem, ESelectInfo::Type InSelectionType)
{
	const auto SelectedResolution = Resolutions[ResolutionComboBox->GetSelectedIndex()];
	GameUserSettings->SetScreenResolution(SelectedResolution);
	GameUserSettings->ApplySettings(false);
}
