// Fill out your copyright notice in the Description page of Project Settings.


#include "RPG_C.h"
#include "PaperFlipbookComponent.h"
#include "PaperSpriteComponent.h"
#include "DebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ArrowComponent.h"
#include "Components/SceneComponent.h"

void ARPG_C::Attack()
{
	if (bCanFire && AmmoForRPG > 0)
	{
		bCanFire = false;
		AmmoForRPG--;
		FIRE_RPG();

		if (bShouldFire) 
		{
			Flipbook->SetFlipbook(FiringFlipbook);
			bShouldFire = false;

		}
		GetWorld()->GetTimerManager().SetTimer(Delay, this, &ARPG_C::StopAttacking, FireRate);
	}

}

void ARPG_C::StopAttacking()
{
	Flipbook->SetFlipbook(IdleFlipbook);
	bCanFire = true;
	bShouldFire = true;

}

void ARPG_C::DoOnce()
{
	//GetWorld()->GetTimerManager().ClearTimer(Delay);

}
