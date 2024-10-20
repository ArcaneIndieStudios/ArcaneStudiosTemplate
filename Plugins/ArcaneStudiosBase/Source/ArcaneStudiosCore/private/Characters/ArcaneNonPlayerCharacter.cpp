// © 2024, Arcane Studios. All rights reserved.


#include "Characters/ArcaneNonPlayerCharacter.h"
#include "ArcaneAbilitySystemComponent.h"
#include "ArcaneAttributeSet.h"

AArcaneNonPlayerCharacter::AArcaneNonPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UArcaneAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	AttributeSet = CreateDefaultSubobject<UArcaneAttributeSet>("AttributeSet");
}

void AArcaneNonPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	GiveDefaultAbilities();
	InitDefaultAttributes();
	AttributesInitialized.Broadcast();
}
