// © 2024, Arcane Studios. All rights reserved.

#include "Player/ArcanePlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

void AArcanePlayerController::BeginPlay()
{
	if (IsLocalPlayerController())
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
			InputSubsystem->AddMappingContext(DefaultInputMappingContext, 0);
	}
}
