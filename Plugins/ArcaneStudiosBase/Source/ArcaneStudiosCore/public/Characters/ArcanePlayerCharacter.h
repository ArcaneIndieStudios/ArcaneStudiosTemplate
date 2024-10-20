// © 2024, Arcane Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Characters/ArcaneBaseCharacter.h"
#include "ArcanePlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class ARCANESTUDIOSCORE_API AArcanePlayerCharacter : public AArcaneBaseCharacter
{
	GENERATED_BODY()

public:
	AArcanePlayerCharacter();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	// --Components-- //
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<USpringArmComponent> FPSpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UCameraComponent> FPCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<USpringArmComponent> TPSpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	TObjectPtr<UCameraComponent> TPCamera;
	
	// --Setup Variables-- //
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Arcane Studios|Perspective")
	bool StartInFPP = true;

	// The Socket To Which The First Person Camera Will be Attached to
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Arcane Studios|Perspective")
	FName CameraAttachSocket = FName("Camera");

	// First Person Camera Offset From the Attached Socket
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Arcane Studios|Perspective")
	FVector CameraOffset = FVector(0.0f, 0.0f, 0.0f);

	// --Helper Functions-- //
	UFUNCTION(BlueprintPure, Category = "Arcane Studios|Accessors")
	UCameraComponent* GetActiveCamera();

private:
	void InitAbilitySystemComponent();

};
