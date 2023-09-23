// Fill out your copyright notice in the Description page of Project Settings.


#include "Character_Base_C.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "DebugHelpers.h"
#include "Components/ChildActorComponent.h"
#include "Weapon_Base_C.h"

// Sets default values
ACharacter_Base_C::ACharacter_Base_C()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetRelativeLocation(FVector(0.f, 0.f, 60.f));
	Camera->SetupAttachment(RootComponent);
	Camera->bUsePawnControlRotation = true;

	bUseControllerRotationYaw = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.4f;

	Weapon = CreateDefaultSubobject<UChildActorComponent>(TEXT("WEAPON"));
	Weapon->SetupAttachment(Camera);

}

// Called when the game starts or when spawned
void ACharacter_Base_C::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void ACharacter_Base_C::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacter_Base_C::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (PlayerInputComponent) 
	{
		PlayerInputComponent->BindAxis("MoveForward", this, &ACharacter_Base_C::MoveForward);
		PlayerInputComponent->BindAxis("MoveRight", this, &ACharacter_Base_C::MoveRight);
		//PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
		PlayerInputComponent->BindAxis("LookRight", this, &APawn::AddControllerYawInput);

		PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ACharacter::Jump);
		PlayerInputComponent->BindAction("Fire", EInputEvent::IE_Pressed, this, &ACharacter_Base_C::FIRE);



	}

}

void ACharacter_Base_C::MoveForward(float Value)
{
	if (Controller && Value != 0) 
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ACharacter_Base_C::MoveRight(float Value)
{
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void ACharacter_Base_C::FIRE()
{
	
	AWeapon_Base_C* CastWeapon = Cast<AWeapon_Base_C>(Weapon->GetChildActor());
	if (CastWeapon) 
	{
		CastWeapon->Attack();
	}
					
}

