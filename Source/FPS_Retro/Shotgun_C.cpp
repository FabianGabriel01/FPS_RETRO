// Fill out your copyright notice in the Description page of Project Settings.


#include "Shotgun_C.h"
#include "PaperFlipbookComponent.h"
#include "PaperSpriteComponent.h"
#include "DebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ArrowComponent.h"
#include "Components/SceneComponent.h"

void AShotgun_C::Attack()
{
	if (bCanFire) 
	{
		AmmoForShotgun--;
		Flipbook->SetFlipbook(FiringFlipbook);
		FIRE();
		bCanFire = false;
		GetWorld()->GetTimerManager().SetTimer(Delay, this, &AShotgun_C::StopAttacking, FireRate);
	}

	////Add Timer to RATE RIFe
	///Set FLipbook to idle
}

void AShotgun_C::StopAttacking()
{
	DEBUG::Print(TEXT("STOP ATTACKING"));
	Flipbook->SetFlipbook(IdleFlipbook);
	bCanFire = true;
}
