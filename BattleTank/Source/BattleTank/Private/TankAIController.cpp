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

	auto GetTankPlayer = GetPlayerTank();

	if (!GetTankPlayer)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find PlayerTank "));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerTank found by AITank: %s"), *(GetTankPlayer->GetName()));
	}

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		//Move Towards the player

		//aim towards the player
		GetAIControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		//fire if ready
	}
	//UE_LOG(LogTemp, Warning,TEXT("AIController Ticking"));
}

ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	else
	{
		return Cast<ATank>(PlayerPawn);
	}
}
