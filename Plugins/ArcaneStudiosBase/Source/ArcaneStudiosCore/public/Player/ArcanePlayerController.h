// © 2024, Arcane Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CommonUserWidget.h"
#include "ArcanePlayerController.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ARCANESTUDIOSCORE_API AArcanePlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void PreInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Arcane Studios|Input")
	class UInputMappingContext* DefaultInputMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Arcane Studios|UI")
	TSubclassOf<UCommonUserWidget> DefaultPlayerMenuClass = NULL;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Arcane Studios|UI")
	UCommonUserWidget* PlayerMenu;
};
