// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActorTarget.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AMyActorTarget::AMyActorTarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Target = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Target"));

}

// Called when the game starts or when spawned
void AMyActorTarget::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActorTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

