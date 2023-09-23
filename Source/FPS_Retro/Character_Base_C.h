// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Character_Base_C.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UChildActorComponent;

UCLASS()
class FPS_RETRO_API ACharacter_Base_C : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacter_Base_C();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Properties
	UPROPERTY(EditAnywhere)
		UCameraComponent* Camera;

	UPROPERTY(EditAnywhere)
		UChildActorComponent* Weapon;


	void MoveForward(float Value);

	void MoveRight(float Value);

	void FIRE();

	void ReleasedFIRE();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
