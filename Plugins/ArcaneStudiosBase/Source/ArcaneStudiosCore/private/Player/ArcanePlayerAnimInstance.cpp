// © 2024, Arcane Studios. All rights reserved.


#include "Player/ArcanePlayerAnimInstance.h"
#include "Kismet/KismetMathLibrary.h"

#include "Camera/CameraComponent.h"

void UArcanePlayerAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
}

void UArcanePlayerAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (!IsValid(ArcanePlayerCharacter())) return;

	SetVariables(DeltaTime);
}

AArcanePlayerCharacter* UArcanePlayerAnimInstance::ArcanePlayerCharacter()
{
	return Cast<AArcanePlayerCharacter>(TryGetPawnOwner());
}

FRotator UArcanePlayerAnimInstance::CalculateAimOffset(float Divisor)
{
	if (!IsValid(TryGetPawnOwner())) return FRotator();

	FRotator AimOffset = FRotator();
	FRotator ControlRotation = TryGetPawnOwner()->GetControlRotation();

	if (TryGetPawnOwner()->IsLocallyControlled())
	{
		AimOffset.Pitch = (ControlRotation.Pitch > 180 ? 360 - ControlRotation.Pitch : ControlRotation.Pitch * -1.0f) / Divisor;
	}
	else
	{
		FRotator BaseAimRotation = TryGetPawnOwner()->GetBaseAimRotation();
		AimOffset.Pitch = (UKismetMathLibrary::NormalizedDeltaRotator(ControlRotation, BaseAimRotation).Pitch) / Divisor;
	}

	return AimOffset;
}

void UArcanePlayerAnimInstance::SetVariables(const float DeltaTime)
{
	CameraTransform = FTransform(
		ArcanePlayerCharacter()->IsLocallyControlled() ? ArcanePlayerCharacter()->GetControlRotation() : ArcanePlayerCharacter()->GetBaseAimRotation(),
		ArcanePlayerCharacter()->FPCamera->GetComponentLocation());

	FTransform RootOffset = ArcanePlayerCharacter()->GetMesh()->GetSocketTransform(FName("root"), RTS_Component).Inverse()
		* ArcanePlayerCharacter()->GetMesh()->GetSocketTransform(FName("ik_hand_root"));

	RelativeCameraTransform = CameraTransform.GetRelativeTransform(RootOffset);
}
