// © 2024, Arcane Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "ArcaneBaseCharacter.generated.h"

class UGameplayAbility;
class UArcaneAbilitySystemComponent;
class UArcaneAttributeSet;
class UGameplayEffect;

UCLASS(Abstract, NotBlueprintable)
class ARCANESTUDIOSCORE_API AArcaneBaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AArcaneBaseCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual UArcaneAttributeSet* GetAttributeSet() const;

protected:
	void GiveDefaultAbilities();
	void InitDefaultAttributes() const;

	UPROPERTY()
	TObjectPtr<UArcaneAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UArcaneAttributeSet> AttributeSet;

	UPROPERTY(EditDefaultsOnly, Category = "Arcane Studios|Ability System")
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "Arcane Studios|Ability System")
	TSubclassOf<UGameplayEffect> DefaultAttributeEffect;

public:	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
};
