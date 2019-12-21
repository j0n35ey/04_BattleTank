// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = "Physics | Rendering | Lighting | Collision")
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DegressPerSecond);

private	:
	UPROPERTY(EditAnywhere, Category = "Setup")
		float MaxDegressPersecond = 20.0f;
	UPROPERTY(EditAnywhere, Category = "Setup")
		float MaxElevationDegress = 30.0f;;
	UPROPERTY(EditAnywhere, Category = "Setup")
		float MinElevationDegress = -0;
};