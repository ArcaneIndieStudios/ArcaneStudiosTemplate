// © 2024, Arcane Studios. All rights reserved.


#include "Player/ArcanePlayerState.h"
#include "ArcaneAbilitySystemComponent.h"
#include "ArcaneAttributeSet.h"
#include "Components/GameFrameworkComponentManager.h"

AArcanePlayerState::AArcanePlayerState()
{
	NetUpdateFrequency = 100.f;

	AbilitySystemComponent = CreateDefaultSubobject<UArcaneAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AttributeSet = CreateDefaultSubobject<UArcaneAttributeSet>("AttributeSet");
}

void AArcanePlayerState::PreInitializeComponents()
{
	Super::PreInitializeComponents();

	UGameFrameworkComponentManager::AddGameFrameworkComponentReceiver(this);
}

void AArcanePlayerState::BeginPlay()
{
	UGameFrameworkComponentManager::SendGameFrameworkComponentExtensionEvent(this, UGameFrameworkComponentManager::NAME_GameActorReady);

	Super::BeginPlay();
}

void AArcanePlayerState::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UGameFrameworkComponentManager::RemoveGameFrameworkComponentReceiver(this);

	Super::EndPlay(EndPlayReason);
}

UAbilitySystemComponent* AArcanePlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UArcaneAttributeSet* AArcanePlayerState::GetAttributeSet() const
{
	return AttributeSet;
}
