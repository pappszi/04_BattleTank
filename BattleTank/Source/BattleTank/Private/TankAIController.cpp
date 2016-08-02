// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto GetControlledAITank = GetAIControlledTank();

	if (!GetControlledAITank)
	{
		UE_LOG(LogTemp, Warning,TEXT("AIControlledTank not found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning,TEXT("AIControlled Tank found: %s"), *(GetControlledAITank->GetName()));
	}

}

ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

