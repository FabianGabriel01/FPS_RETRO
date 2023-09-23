// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RPG_Bullet_C.generated.h"

class UStaticMeshComponent;
class UProjectileMovementComponent;
class USceneComponent;
class AExplotion_C;

UCLASS()
class FPS_RETRO_API ARPG_Bullet_C : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARPG_Bullet_C();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
		UProjectileMovementComponent* ProjectileMovementComponent;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectsToHit;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AExplotion_C> ExplotionIMG;

	FActorSpawnParameters SpawnInfo;

	/*UPROPERTY(EditAnywhere)
		float AmmoForShotgun = 10;

	UPROPERTY(EditAnywhere)
		bool bCanFire;

	UPROPERTY(EditAnywhere)
		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectsToHit;


	FHitResult DoLineTraceSingleByObject(const FVector& Start, const FVector& End, bool bShowDebugSphere = false, bool bDrawPersistantShaper = false);
	*/

	FHitResult OutHit;
	TArray<AActor*> ActorsToIgnore;

};
