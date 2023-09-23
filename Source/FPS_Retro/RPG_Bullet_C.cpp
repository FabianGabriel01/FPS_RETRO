// Fill out your copyright notice in the Description page of Project Settings.


#include "RPG_Bullet_C.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "DebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Explotion_C.h"

// Sets default values
ARPG_Bullet_C::ARPG_Bullet_C()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Projectile"));
	Mesh->SetupAttachment(RootComponent);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
	ProjectileMovementComponent->InitialSpeed = 2000.f;
	ProjectileMovementComponent->MaxSpeed = 2000.f;
	ProjectileMovementComponent->ProjectileGravityScale = 0.2f;
}

// Called when the game starts or when spawned
void ARPG_Bullet_C::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARPG_Bullet_C::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	bool HasHit = 
	UKismetSystemLibrary::CapsuleTraceSingleForObjects
	(
		this,
		Mesh->GetComponentLocation(),
		Mesh->GetComponentLocation(),
		30.f,
		30.f,
		ObjectsToHit,
		false,
		ActorsToIgnore,
		EDrawDebugTrace::ForDuration,
		OutHit,
		true
	);

	if (HasHit) 
	{
		DEBUG::Print("EXPLOTION");

		GetWorld()->SpawnActor<AActor>(ExplotionIMG, Mesh->GetComponentLocation(), FRotator(0, 0, 0));

		Destroy();
	}

}

