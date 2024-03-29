// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = "Physics | Rendering | Lighting | Collision")
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward speed. +1 is max upward speed
	void Elevate(float RelativeSpeed);

private	:
	UPROPERTY(EditAnywhere, Category = "Setup")
		float MaxDegressPersecond = 10.0f;
	UPROPERTY(EditAnywhere, Category = "Setup")
		float MaxElevationDegress = 30.0f;;
	UPROPERTY(EditAnywhere, Category = "Setup")
		float MinElevationDegress = -0;
};
