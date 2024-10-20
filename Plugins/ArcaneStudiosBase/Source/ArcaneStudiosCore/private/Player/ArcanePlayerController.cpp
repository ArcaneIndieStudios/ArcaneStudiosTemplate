// © 2024, Arcane Studios. All rights reserved.

#include "Player/ArcanePlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Components/GameFrameworkComponentManager.h"

void AArcanePlayerController::PreInitializeComponents()
{
	Super::PreInitializeComponents();

	UGameFrameworkComponentManager::AddGameFrameworkComponentReceiver(this);
}

void AArcanePlayerController::BeginPlay()
{
	UGameFrameworkComponentManager::SendGameFrameworkComponentExtensionEvent(this, UGameFrameworkComponentManager::NAME_GameActorReady);
	Super::BeginPlay();

	if (IsLocalPlayerController())
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
			InputSubsystem->AddMappingContext(DefaultInputMappingContext, 0);

		if (DefaultPlayerMenuClass != NULL)
		{
			PlayerMenu = Cast<UCommonUserWidget>(CreateWidget(this, DefaultPlayerMenuClass, FName("Player Menu")));

			if (IsValid(PlayerMenu))
				PlayerMenu->AddToViewport();
		}
	}
}

void AArcanePlayerController::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UGameFrameworkComponentManager::RemoveGameFrameworkComponentReceiver(this);

	Super::EndPlay(EndPlayReason);
}
