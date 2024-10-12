// © 2024, Arcane Studios. All rights reserved.


#include "Characters/ArcanePlayerCharacter.h"
#include "ArcaneAbilitySystemComponent.h"
#include "ArcaneAttributeSet.h"
#include "Player/ArcanePlayerState.h"

AArcanePlayerCharacter::AArcanePlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AArcanePlayerCharacter::InitAbilitySystemComponent()
{
	AArcanePlayerState* ArcanePlayerState = GetPlayerState<AArcanePlayerState>();
	check(ArcanePlayerState);
	AbilitySystemComponent = CastChecked<UArcaneAbilitySystemComponent>(ArcanePlayerState->GetAbilitySystemComponent());
	AbilitySystemComponent->InitAbilityActorInfo(ArcanePlayerState, this);
}

void AArcanePlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitAbilitySystemComponent();
	GiveDefaultAbilities();
	InitDefaultAttributes();
}

void AArcanePlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitAbilitySystemComponent();
	InitDefaultAttributes();
}
