// © 2024, Arcane Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "ArcaneAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)\

// --Gets the Numeric Value using the Attribute Name--
#define NUMERIC_VALUE(AttributeSetName, PropertyName) \
	AttributeSetName->Get##PropertyName##Attribute().GetNumericValue(AttributeSetName)

// --Gets the Numeric Value using Attribute Reference--
#define ATTRIBUTE_NUMERIC_VALUE(Attribute, AttributeSetName) \
	Attribute.GetNumericValue(AttributeSetName)

/**
 * 
 */
UCLASS()
class ARCANESTUDIOSCORE_API UArcaneAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UArcaneAttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Arcane Studios|Gameplay Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UArcaneAttributeSet, Health)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Arcane Studios|Gameplay Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UArcaneAttributeSet, MaxHealth)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Arcane Studios|Gameplay Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UArcaneAttributeSet, Mana)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Arcane Studios|Gameplay Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UArcaneAttributeSet, MaxMana)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Stamina, Category = "Arcane Studios|Gameplay Attributes")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UArcaneAttributeSet, Stamina)

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStamina, Category = "Arcane Studios|Gameplay Attributes")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UArcaneAttributeSet, MaxStamina)

	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
	
	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldStamina) const;

	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina) const;
};
