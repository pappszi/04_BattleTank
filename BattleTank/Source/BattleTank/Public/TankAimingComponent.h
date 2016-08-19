// Copyright SysGames Ltd.

#pragma once

#include "BattleTank.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Enum for aiming state
UENUM()
enum class EFiringState : uint8
{
	Aiming,
	Reloading,
	Locked,
	OutOfAmmo
};

//Forward declaration
class UTankBarrel; 
class UTankturret;
class AProjectile;

//Hold barrel's property and Elevate method 
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankturret* TurretToSet);

	void AimAt(FVector HitLocation);
	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

	EFiringState GetFiringState() const;
	UFUNCTION(BluePrintCallable, Category = "Firing")
	int GetRoundsLeft() const;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;

private:
	// Sets default values for this component's properties
	UTankAimingComponent();
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;
	void MoveBarrelTowards(FVector AimDirection);
	bool IsBarrelMoving();
	UTankBarrel* Barrel = nullptr;
	UTankturret* Turret = nullptr;
	
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSecondes = 3;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;
	double LastFireTime = 0;
	FVector AimDirection;

	int RoundsLeft = 3; 
};
