// Fill out your copyright notice in the Description page of Project Settings.


#include "Minigun_C.h"
#include "PaperFlipbookComponent.h"
#include "PaperSpriteComponent.h"
#include "DebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ArrowComponent.h"
#include "Components/SceneComponent.h"

void AMinigun_C::Attack()
{

	bShouldFire = true;
	GetWorld()->GetTimerManager().SetTimer(Delay, this, &AMinigun_C::KeepFiring, FireRate, true);

	////Add Timer to RATE RIFe
	///Set FLipbook to idle
}

void AMinigun_C::StopAttacking()
{
	DEBUG::Print(TEXT("STOP ATTACKING"));
	Flipbook->SetFlipbook(IdleFlipbook);
	GetWorld()->GetTimerManager().ClearTimer(Delay);
	bShouldFire = false;
}

void AMinigun_C::KeepFiring()
{
	if (bShouldFire) 
	{
		AmmoForPistol--;
		Flipbook->SetFlipbook(FiringFlipbook);
		FIRE();
	}
}
