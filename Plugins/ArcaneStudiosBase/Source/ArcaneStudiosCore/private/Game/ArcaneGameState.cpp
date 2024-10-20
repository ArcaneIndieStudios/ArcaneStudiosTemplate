// © 2024, Arcane Studios. All rights reserved.

#include "Game/ArcaneGameState.h"

#include "Components/GameFrameworkComponentManager.h"
#include "Components/GameStateComponent.h"

void AArcaneGameStateBase::PreInitializeComponents()
{
	Super::PreInitializeComponents();

	UGameFrameworkComponentManager::AddGameFrameworkComponentReceiver(this);
}

void AArcaneGameStateBase::BeginPlay()
{
	UGameFrameworkComponentManager::SendGameFrameworkComponentExtensionEvent(this, UGameFrameworkComponentManager::NAME_GameActorReady);

	Super::BeginPlay();
}

void AArcaneGameStateBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UGameFrameworkComponentManager::RemoveGameFrameworkComponentReceiver(this);

	Super::EndPlay(EndPlayReason);
}

void AArcaneGameState::PreInitializeComponents()
{
	Super::PreInitializeComponents();

	UGameFrameworkComponentManager::AddGameFrameworkComponentReceiver(this);
}

void AArcaneGameState::BeginPlay()
{
	UGameFrameworkComponentManager::SendGameFrameworkComponentExtensionEvent(this, UGameFrameworkComponentManager::NAME_GameActorReady);

	Super::BeginPlay();
}

void AArcaneGameState::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UGameFrameworkComponentManager::RemoveGameFrameworkComponentReceiver(this);

	Super::EndPlay(EndPlayReason);
}

void AArcaneGameState::HandleMatchHasStarted()
{
	Super::HandleMatchHasStarted();

	TArray<UGameStateComponent*> ModularComponents;
	GetComponents(ModularComponents);
	for (UGameStateComponent* Component : ModularComponents)
	{
		Component->HandleMatchHasStarted();
	}
}
