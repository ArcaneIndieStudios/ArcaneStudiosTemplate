// © 2024, Arcane Studios. All rights reserved.

#include "Game/ArcaneGameMode.h"

#include "Game/ArcaneGameState.h"
#include "Characters/ArcanePlayerCharacter.h"
#include "Player/ArcanePlayerController.h"
#include "Player/ArcanePlayerState.h"

AArcaneGameModeBase::AArcaneGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	GameStateClass = AArcaneGameStateBase::StaticClass();
	PlayerControllerClass = AArcanePlayerController::StaticClass();
	PlayerStateClass = AArcanePlayerState::StaticClass();
	DefaultPawnClass = AArcanePlayerCharacter::StaticClass();
}

AArcaneGameMode::AArcaneGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	GameStateClass = AArcaneGameState::StaticClass();
	PlayerControllerClass = AArcanePlayerController::StaticClass();
	PlayerStateClass = AArcanePlayerState::StaticClass();
	DefaultPawnClass = AArcanePlayerCharacter::StaticClass();
}
