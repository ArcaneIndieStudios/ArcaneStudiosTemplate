// © 2024, Arcane Studios. All rights reserved.


#include "Characters/ArcanePlayerCharacter.h"

#include "ArcaneAbilitySystemComponent.h"
#include "ArcaneAttributeSet.h"
#include "Player/ArcanePlayerState.h"

// --Components-- //
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

AArcanePlayerCharacter::AArcanePlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	GetMesh()->SetTickGroup(ETickingGroup::TG_PostUpdateWork);
	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
	GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	FPSpringArm = CreateDefaultSubobject<USpringArmComponent>("FPSpringArm");
	FPSpringArm->SetupAttachment(GetMesh(), CameraAttachSocket);
	FPSpringArm->TargetArmLength = 0.0f;
	FPSpringArm->SetRelativeLocation(CameraOffset);
	FPSpringArm->bUsePawnControlRotation = true;

	FPCamera = CreateDefaultSubobject<UCameraComponent>("FPCamera");
	FPCamera->SetupAttachment(FPSpringArm);
	FPCamera->bAutoActivate = StartInFPP;
	FPCamera->bUsePawnControlRotation = true;

	TPSpringArm = CreateDefaultSubobject<USpringArmComponent>("TPSpringArm");
	TPSpringArm->SetupAttachment(GetRootComponent());
	TPSpringArm->TargetArmLength = 250.0f;
	TPSpringArm->bUsePawnControlRotation = true;
	TPSpringArm->SocketOffset = FVector(0.0f, 50.0f, 0.0f);
	TPSpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f));

	TPCamera = CreateDefaultSubobject<UCameraComponent>("TPCamera");
	TPCamera->SetupAttachment(TPSpringArm);
	TPCamera->bUsePawnControlRotation = true;
	TPCamera->bAutoActivate = !StartInFPP;
}

UCameraComponent* AArcanePlayerCharacter::GetActiveCamera()
{
	return FPCamera->IsActive() ? FPCamera : TPCamera;
}

void AArcanePlayerCharacter::InitAbilitySystemComponent()
{
	AArcanePlayerState* ArcanePlayerState = GetPlayerState<AArcanePlayerState>();
	check(ArcanePlayerState);
	AbilitySystemComponent = CastChecked<UArcaneAbilitySystemComponent>(ArcanePlayerState->GetAbilitySystemComponent());
	AbilitySystemComponent->InitAbilityActorInfo(ArcanePlayerState, this);
	AttributeSet = ArcanePlayerState->GetAttributeSet();
}

void AArcanePlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitAbilitySystemComponent();
	GiveDefaultAbilities();
	InitDefaultAttributes();
	AttributesInitialized.Broadcast();
}

void AArcanePlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitAbilitySystemComponent();
	InitDefaultAttributes();
	AttributesInitialized.Broadcast();
}
