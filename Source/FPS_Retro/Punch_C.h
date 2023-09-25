// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon_Base_C.h"
#include "Punch_C.generated.h"

class UPaperFlipbook;

/**
 * 
 */
UCLASS()
class FPS_RETRO_API APunch_C : public AWeapon_Base_C
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		UPaperFlipbook* IdleFlipbook;

	UPROPERTY(EditAnywhere)
		UPaperFlipbook* FiringFlipbook;

	virtual void Attack() override;

	virtual void StopAttacking() override;


	UPROPERTY(EditAnywhere)
		float FireRate = 0.2f;


private: FTimerHandle Delay;
	
};
