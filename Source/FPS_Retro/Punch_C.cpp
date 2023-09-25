// Fill out your copyright notice in the Description page of Project Settings.


#include "Punch_C.h"
#include "PaperFlipbookComponent.h"
#include "PaperSpriteComponent.h"
#include "DebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ArrowComponent.h"
#include "Components/SceneComponent.h"

void APunch_C::Attack()
{
	if (bCanFire)
	{
		AmmoForPistol--;
		Flipbook->SetFlipbook(FiringFlipbook);
		FIRE_Punch();
		bCanFire = false;
		GetWorld()->GetTimerManager().SetTimer(Delay, this, &APunch_C::StopAttacking, FireRate);
	}

}

void APunch_C::StopAttacking()
{
	DEBUG::Print(TEXT("STOP ATTACKING"));
	Flipbook->SetFlipbook(IdleFlipbook);
	GetWorld()->GetTimerManager().ClearTimer(Delay);
	bCanFire = true;
}