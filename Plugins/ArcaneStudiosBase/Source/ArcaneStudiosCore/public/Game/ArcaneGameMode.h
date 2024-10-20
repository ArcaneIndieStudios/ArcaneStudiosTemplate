// © 2024, Arcane Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"

#include "ArcaneGameMode.generated.h"

/**
 * Pair this with a ArcaneGameStateBase
 */
UCLASS()
class ARCANESTUDIOSCORE_API AArcaneGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AArcaneGameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};

/** Pair this with a ArcaneGameState */
UCLASS(Blueprintable)
class ARCANESTUDIOSCORE_API AArcaneGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AArcaneGameMode(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};