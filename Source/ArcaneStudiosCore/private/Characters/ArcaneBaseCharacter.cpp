// © 2024, Arcane Studios. All rights reserved.

#include "ArcaneBaseCharacter.h"
#include "ArcaneAbilitySystemComponent.h"

AArcaneBaseCharacter::AArcaneBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

UAbilitySystemComponent* AArcaneBaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UArcaneAttributeSet* AArcaneBaseCharacter::GetAttributeSet() const
{
	return AttributeSet;
}

void AArcaneBaseCharacter::GiveDefaultAbilities()
{
	check(AbilitySystemComponent);

	if (!HasAuthority()) return;

	for (TSubclassOf<UGameplayAbility> AbilityClass : DefaultAbilities)
	{
		const FGameplayAbilitySpec AbilitySpec(AbilityClass, 1);
		AbilitySystemComponent->GiveAbility(AbilitySpec);
	}
}

void AArcaneBaseCharacter::InitDefaultAttributes() const
{
	if(!AbilitySystemComponent || !DefaultAttributeEffect) return;

	FGameplayEffectContextHandle EffectContext = AbilitySystemComponent->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	const FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributeEffect, 1.f, EffectContext);

	if (SpecHandle.IsValid())
		AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
}

void AArcaneBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
