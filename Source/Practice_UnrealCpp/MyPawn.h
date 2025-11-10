// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class UArrowComponent;
class USpringArmComponent;
class UCameraComponent;
class UFloatingPawnMovement;
class UInputAction;
struct FInputActionValue;

UCLASS()
class PRACTICE_UNREALCPP_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Practice")
	TObjectPtr<UBoxComponent> Box;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Practice")
	TObjectPtr<UStaticMeshComponent> Body;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Practice")
	TObjectPtr<UStaticMeshComponent> Left;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Practice")
	TObjectPtr<UStaticMeshComponent> Right;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Practice")
	TObjectPtr<UArrowComponent> Arrow;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Practice")
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Practice")
	TObjectPtr<UCameraComponent> Camera;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Practice")
	TObjectPtr<UFloatingPawnMovement> FloatingMovement;

	void Fire();
	void Pitch(float Value);
	void Roll(float Value);
	void EnhancedFire(const FInputActionValue& Value);
	void EnhancedMovement(const FInputActionValue& Value);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Input")
	TObjectPtr<class UInputAction> IA_Fire;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Input")
	TObjectPtr<class UInputAction> IA_Movement;

};
