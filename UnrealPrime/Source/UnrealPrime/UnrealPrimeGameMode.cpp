// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "UnrealPrimeGameMode.h"
#include "UnrealPrimeHUD.h"
#include "UnrealPrimeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealPrimeGameMode::AUnrealPrimeGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AUnrealPrimeHUD::StaticClass();
}
