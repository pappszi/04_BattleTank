// Copyright SysGames Ltd.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//Sets a throttle between -1 and +1
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);
	
	//Max force per track in Newtons
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 400000; //Assume 40 tonne tank and 1g acceleration
private:
	UTankTrack();
	virtual void BeginPlay() override;
	void ApplySidewaysForce();
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponenet, AActor* OtherActor, UPrimitiveComponent* OtherComponenet, FVector NormalImpulse, const FHitResult& Hit);
	void DriveTrack();
	float CurrentThrottle = 0;
};
