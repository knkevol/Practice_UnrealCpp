// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorRocket.h"
#include "Components/StaticMeshComponent.h"
#include "GameFrameWork/ProjectileMovementComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AMyActorRocket::AMyActorRocket()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;
	Box->SetBoxExtent(FVector(27.0f, 12.0f, 10.0f));

	Rocket = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Rocket"));
	Rocket->SetupAttachment(Box);
	Rocket->SetRelativeRotation(FRotator(-90.0f, 0, 0));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Rocket(TEXT("/Script/Engine.StaticMesh'/Game/Meshs/SM_Rocket.SM_Rocket'"));
	if (SM_Rocket.Succeeded())
	{
		Rocket->SetStaticMesh(SM_Rocket.Object);
	}


	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->InitialSpeed = 1000.0f;
	ProjectileMovement->MaxSpeed = 1000.0f;
	ProjectileMovement->ProjectileGravityScale = 0;



}

// Called when the game starts or when spawned
void AMyActorRocket::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActorRocket::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

