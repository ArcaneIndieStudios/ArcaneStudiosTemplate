// © 2024, Arcane Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "ArcaneAttributeSet.h"
#include "AttributesWidget.generated.h"

/**
 * 
 */
UCLASS()
class ARCANESTUDIOSCORE_API UAttributesWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	void BindToAttributes();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Arcane Studios|UI")
	FGameplayAttribute Attribute;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Arcane Studios|UI")
	FGameplayAttribute MaxAttribute;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Arcane Studios|UI")
	float AttributePercent;

};
