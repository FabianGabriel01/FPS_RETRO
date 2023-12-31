// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon_Base_C.h"
#include "Character_Base_C.h"
#include "DebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "PaperFlipbookComponent.h"
#include "PaperSpriteComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/SceneComponent.h"
#include "RPG_Bullet_C.h"


// Sets default values
AWeapon_Base_C::AWeapon_Base_C()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
    Arrow->SetupAttachment(RootComponent);

    Flipbook = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("FlipBook"));
    Flipbook->SetupAttachment(Arrow);

    TraceStart = CreateDefaultSubobject<USceneComponent>(TEXT("TraceStart"));
    TraceStart->SetupAttachment(Flipbook);


    ActorsToIgnore.Add(UGameplayStatics::GetActorOfClass(this, TSubclassOf<ACharacter_Base_C>()));
}

// Called when the game starts or when spawned
void AWeapon_Base_C::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void AWeapon_Base_C::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeapon_Base_C::FIRE()
{
    if (GetWorld())
    {
        ///Assign to Variable FhitResult Hit

        /*DoLineTraceSingleByObject
        (
            GetActorLocation(),
            GetActorForwardVector() * 400000,
            true,
            true
        );*/

        DoLineTraceSingleByObject
        (
            TraceStart->GetComponentLocation(),
            TraceStart->GetForwardVector() * 400000  + TraceStart->GetComponentLocation(),
            true,
            true
        );

        //ApplyDamage to the HitActor
    }
}

void AWeapon_Base_C::FIRE_RPG()
{
    if (AmmoForRPG > 0) 
    {
        GetWorld()->SpawnActor<ARPG_Bullet_C>(RPG_Bullet, TraceStart->GetComponentLocation(), FRotator::ZeroRotator, SpawnInfo);
    }
}

void AWeapon_Base_C::FIRE_Punch()
{
    if (GetWorld()) 
    {
        FHitResult HitActor = DoLineTraceSingleByObject
        (
            TraceStart->GetComponentLocation(),
            TraceStart->GetForwardVector() * 400 + TraceStart->GetComponentLocation(),
            true,
            true
        );

        /////////FOR ADDING IMPULSE
        if (HitActor.bBlockingHit) 
        {
            UStaticMeshComponent* Comp = Cast<UStaticMeshComponent>(HitActor.GetActor()->GetRootComponent());
            if (Comp && HitActor.GetActor()->IsRootComponentMovable()) 
            {
                Comp->AddImpulse(TraceStart->GetForwardVector() * 1000 * Comp->GetMass());
            }
            
        }
    }
}

void AWeapon_Base_C::Attack()
{
    
}

void AWeapon_Base_C::StopAttacking()
{
}

FHitResult AWeapon_Base_C::DoLineTraceSingleByObject(const FVector& Start, const FVector& End, bool bShowDebugSphere, bool bDrawPersistantShaper)
{
    FHitResult OutHit;
    
    EDrawDebugTrace::Type DebugTraceType = EDrawDebugTrace::None;

    if (bShowDebugSphere)
    {
        DebugTraceType = EDrawDebugTrace::ForOneFrame;
        if (bDrawPersistantShaper)
        {
            DebugTraceType = EDrawDebugTrace::Persistent;

        }
    }

    UKismetSystemLibrary::LineTraceSingleForObjects
    (
        this,
        Start,
        End,
        ObjectsToHit,
        false,
        ActorsToIgnore,
        DebugTraceType,
        OutHit,
        false
    );

    return OutHit;
}

