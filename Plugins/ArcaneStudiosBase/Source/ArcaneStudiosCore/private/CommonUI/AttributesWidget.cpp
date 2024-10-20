// © 2024, Arcane Studios. All rights reserved.


#include "CommonUI/AttributesWidget.h"
#include "Characters/ArcaneBaseCharacter.h"

void UAttributesWidget::NativeConstruct()
{
	Super::NativeConstruct();

	BindToAttributes();

	AArcaneBaseCharacter* OwningCharacter = Cast<AArcaneBaseCharacter>(GetOwningPlayerPawn());
	if (IsValid(OwningCharacter)) OwningCharacter->AttributesInitialized.AddLambda([ this ](){ BindToAttributes(); });

}

void UAttributesWidget::BindToAttributes()
{
	AArcaneBaseCharacter* OwningCharacter = Cast<AArcaneBaseCharacter>(GetOwningPlayerPawn());

	UAbilitySystemComponent* ASC = OwningCharacter->GetAbilitySystemComponent();
	const UArcaneAttributeSet* ArcaneAS = OwningCharacter->GetAttributeSet();

	if (!IsValid(ASC) || !IsValid(ArcaneAS)) return;

	AttributePercent = ATTRIBUTE_NUMERIC_VALUE(Attribute, ArcaneAS) / ATTRIBUTE_NUMERIC_VALUE(MaxAttribute, ArcaneAS);

	ASC->GetGameplayAttributeValueChangeDelegate(Attribute).AddLambda([ this, ArcaneAS ](const FOnAttributeChangeData& Data)
	{
		AttributePercent = Data.NewValue / ATTRIBUTE_NUMERIC_VALUE(MaxAttribute, ArcaneAS);
	});

}
