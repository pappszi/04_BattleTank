// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "Tankturret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))//, hidecategories = ("Collision")) //component can be chosen from blueprint
class BATTLETANK_API UTankturret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
		void Rotate(float RelativeSpeed);
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 25;
	
};
