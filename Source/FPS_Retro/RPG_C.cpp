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
	if (bCanFire)
	{
		bCanFire = false;
		AmmoForRPG--;
		Flipbook->SetFlipbook(FiringFlipbook);
		FIRE_RPG();
		GetWorld()->GetTimerManager().SetTimer(Delay, this, &ARPG_C::StopAttacking, FireRate);
	}

}

void ARPG_C::StopAttacking()
{
	DEBUG::Print(TEXT("STOP ATTACKING"));
	Flipbook->SetFlipbook(IdleFlipbook);
	GetWorld()->GetTimerManager().ClearTimer(Delay);

	GetWorld()->GetTimerManager().SetTimer(Delay, this, &ARPG_C::DoOnce, NDelay);

}

void ARPG_C::DoOnce()
{
	bCanFire = true;
}
