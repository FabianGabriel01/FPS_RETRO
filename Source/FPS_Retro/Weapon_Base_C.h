// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon_Base_C.generated.h"

class UPaperFlipbookComponent;
class UArrowComponent;
class USceneComponent;
class ARPG_Bullet_C;

UCLASS()
class FPS_RETRO_API AWeapon_Base_C : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon_Base_C();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(EditAnywhere)
		UArrowComponent* Arrow;

	UPROPERTY(EditAnywhere)
		USceneComponent* TraceStart;

	UPROPERTY(EditAnywhere)
		UPaperFlipbookComponent* Flipbook;

	UPROPERTY(EditAnywhere)
		float DamageWeapon;

	UPROPERTY(EditAnywhere)
		float AmmoForPistol = 100;

	UPROPERTY(EditAnywhere)
		float AmmoForShotgun = 10;

	UPROPERTY(EditAnywhere)
		float AmmoForRPG = 10;

	UPROPERTY(EditAnywhere)
		bool bCanFire;

	UPROPERTY(EditAnywhere)
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectsToHit;


	FHitResult DoLineTraceSingleByObject(const FVector& Start, const FVector& End, bool bShowDebugSphere = false, bool bDrawPersistantShaper = false);


	TArray<AActor*> ActorsToIgnore;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ARPG_Bullet_C> RPG_Bullet;

	FActorSpawnParameters SpawnInfo;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void FIRE();

	void FIRE_RPG();



	virtual void Attack();

	virtual void StopAttacking();



};
