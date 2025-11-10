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
	Box->SetWorldRotation(FRotator(90.0f, 0, 0));

	Rocket = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Rocket"));

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));


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

