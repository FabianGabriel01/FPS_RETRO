// Fill out your copyright notice in the Description page of Project Settings.


#include "ChildWeapon_Base_C.h"
#include "PaperFlipbookComponent.h"
#include "PaperSpriteComponent.h"
#include "DebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Components/ArrowComponent.h"
#include "Components/SceneComponent.h"

void AChildWeapon_Base_C::Attack() 
{
	if (bCanFire) 
	{
		AmmoForPistol--;
		Flipbook->SetFlipbook(FiringFlipbook);
		FIRE();
		bCanFire = false;
		GetWorld()->GetTimerManager().SetTimer(Delay, this, &AChildWeapon_Base_C::StopAttacking, FireRate);
	}

	////Add Timer to RATE RIFe
	///Set FLipbook to idle

}

void AChildWeapon_Base_C::StopAttacking() 
{
	DEBUG::Print(TEXT("STOP ATTACKING"));
	Flipbook->SetFlipbook(IdleFlipbook);
	GetWorld()->GetTimerManager().ClearTimer(Delay);
	bCanFire = true;
}