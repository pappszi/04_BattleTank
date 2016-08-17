// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"
//Depends on Movement component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (ensure(PlayerTank))
	{
		//Move Towards the player
		MoveToActor(PlayerTank, AcceptanceRadius);

		//aim towards the player

		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		//fire
		ControlledTank->Fire(); //TODO dont fire every frame , limit fire rate

	}
}


