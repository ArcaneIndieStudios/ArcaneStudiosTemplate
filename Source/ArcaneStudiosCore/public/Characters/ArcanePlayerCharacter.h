// © 2024, Arcane Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Characters/ArcaneBaseCharacter.h"
#include "ArcanePlayerCharacter.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class ARCANESTUDIOSCORE_API AArcanePlayerCharacter : public AArcaneBaseCharacter
{
	GENERATED_BODY()

public:
	AArcanePlayerCharacter();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
	void InitAbilitySystemComponent();

};
