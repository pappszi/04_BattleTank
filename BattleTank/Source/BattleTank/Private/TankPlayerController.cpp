// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not posessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController posessing: %s"), *(ControlledTank->GetName()));
	}

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	//UE_LOG(LogTemp, Warning,TEXT("PlayerController Ticking"));
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; //Out Parameter
	if (GetSightRayHitLocation(HitLocation)) //has a sideeffect, going to linetrace
	{
		UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *(HitLocation.ToString()));

		//TODO		 //tell controlled tank to aim at this point
	}
}
// Get world location of linetrace trough crosshair
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	//find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY); //uses OUT parameter
	auto ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);

	//de-project the screen position of the crosshair to a world direction
	// line trace along that look direction and see what we hit up to max range
	return true;
}
