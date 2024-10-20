// © 2024, Arcane Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Characters/ArcaneBaseCharacter.h"
#include "ArcaneNonPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class ARCANESTUDIOSCORE_API AArcaneNonPlayerCharacter : public AArcaneBaseCharacter
{
	GENERATED_BODY()

public:
	AArcaneNonPlayerCharacter();

	virtual void BeginPlay() override;

};
