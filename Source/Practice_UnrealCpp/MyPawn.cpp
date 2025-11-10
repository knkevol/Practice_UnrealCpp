// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/ArrowComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Kismet/GameplayStatics.h" // GetWorldDeltaSeconds(GetWorld())
#include "MyActorRocket.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "InputActionValue.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(Box);
	Left = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Left"));
	Left->SetupAttachment(Body);
	Right = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Right"));
	Right->SetupAttachment(Body);

	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingMovement"));
	
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(RootComponent);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddMovementInput(GetActorForwardVector());

	Left->SetRelativeRotation(FRotator(0, 0, DeltaTime * 3600.0f * 60.0f));
	Right->SetRelativeRotation(FRotator(0, 0, DeltaTime * 3600.0f * 60.0f));

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* UIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (UIC)
	{
		UIC->BindAction(IA_Fire, ETriggerEvent::Completed, this, &AMyPawn::EnhancedFire);
		UIC->BindAction(IA_Movement, ETriggerEvent::Triggered, this, &AMyPawn::EnhancedMovement);
	}

}

void AMyPawn::Fire()
{
	GetWorld()->SpawnActor<AMyActorRocket>(AMyActorRocket::StaticClass(), Arrow->K2_GetComponentToWorld());
}

void AMyPawn::Pitch(float Value)
{
	AddActorLocalRotation(FRotator(Value * 60.0f * UGameplayStatics::GetWorldDeltaSeconds(GetWorld()), 0, 0));
}

void AMyPawn::Roll(float Value)
{
	AddActorLocalRotation(FRotator(0, 0, Value * 60.0f * UGameplayStatics::GetWorldDeltaSeconds(GetWorld())));
}

void AMyPawn::EnhancedFire(const FInputActionValue& Value)
{
	Fire();
}

void AMyPawn::EnhancedMovement(const FInputActionValue& Value)
{
	FVector2D WantedRotation = Value.Get<FVector2D>();

	Pitch(WantedRotation.Y);
	Roll(WantedRotation.X);
}

