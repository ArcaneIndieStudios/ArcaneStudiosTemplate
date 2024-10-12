// © 2024, Arcane Studios. All rights reserved.

#include "ArcaneAbilitySystemComponent.h"

UArcaneAbilitySystemComponent::UArcaneAbilitySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	SetIsReplicated(true);
}
