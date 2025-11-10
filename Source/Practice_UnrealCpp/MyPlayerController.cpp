// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"

AMyPlayerController::AMyPlayerController()
{
	
}

AMyPlayerController::~AMyPlayerController()
{
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//to LocalPlayer 
	if (ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player))
	{
		//Add EnhancedLocalPlayerSubSystem
		if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			InputSystem->AddMappingContext(InputMapping, 0);
		}
	}

}
