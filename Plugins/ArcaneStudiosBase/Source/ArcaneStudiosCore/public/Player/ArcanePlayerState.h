// © 2024, Arcane Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "ArcanePlayerState.generated.h"

class UArcaneAbilitySystemComponent;
class UArcaneAttributeSet;

/**
 * 
 */
UCLASS(Blueprintable)
class ARCANESTUDIOSCORE_API AArcanePlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	AArcanePlayerState();
	virtual void PreInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual UArcaneAttributeSet* GetAttributeSet() const;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UPROPERTY()
	TObjectPtr<UArcaneAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UArcaneAttributeSet> AttributeSet;

};
