// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	//Start the tank moving the barrel so that the shot would hit where the crosshair intersects the world
	void AimTowardsCrosshair();

	//return OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333f;

};
