// © 2024, Arcane Studios. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Characters/ArcanePlayerCharacter.h"

#include "ArcanePlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ARCANESTUDIOSCORE_API UArcanePlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	
protected:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;

	UFUNCTION(BlueprintPure, Category = "Arcane Studios|Accessors")
	AArcanePlayerCharacter* ArcanePlayerCharacter();

	// --IK Variables-- //
	UPROPERTY(BlueprintReadOnly, Category = "Arcane Studios|IK Variables")
	FTransform CameraTransform;

	UPROPERTY(BlueprintReadOnly, Category = "Arcane Studios|IK Variables")
	FTransform RelativeCameraTransform;

private:
	void SetVariables(const float DeltaTime);
};
