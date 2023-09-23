// Fill out your copyright notice in the Description page of Project Settings.


#include "Explotion_C.h"
#include "DebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "PaperFlipbookComponent.h"
#include "PaperSpriteComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"


// Sets default values
AExplotion_C::AExplotion_C()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(RootComponent);

	Flipbook = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Flipbook"));
	Flipbook->SetupAttachment(RootComponent);

	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	SphereCollision->SetupAttachment(RootComponent);

	SphereCollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

	SphereCollision->OnComponentBeginOverlap.AddDynamic(this, &AExplotion_C::OnOverlapBegin);
	SphereCollision->OnComponentEndOverlap.AddDynamic(this, &AExplotion_C::OnOverlapEnd);


}

// Called when the game starts or when spawned
void AExplotion_C::BeginPlay()
{
	Super::BeginPlay();

	SetLifeSpan(2.5);
	
}

void AExplotion_C::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UGameplayStatics::ApplyDamage(OtherActor, 10.f, GetInstigatorController(), this, DamageType);

}

void AExplotion_C::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

// Called every frame
void AExplotion_C::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), UGameplayStatics::GetPlayerPawn(this, 0)->GetActorLocation())

	SetActorRotation(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), UGameplayStatics::GetPlayerPawn(this, 0)->GetActorLocation()));

}

