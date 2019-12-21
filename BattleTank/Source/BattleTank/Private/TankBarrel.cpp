// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	//UE_LOG(LogTemp, Warning, TEXT("Barrel Elevate Called at speed: %f"), RelativeSpeed);
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = RelativeSpeed * MaxDegressPersecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewEleveation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = (FMath::Clamp<float>(RawNewEleveation, MinElevationDegress, MaxElevationDegress));
	SetRelativeRotation(FRotator(Elevation, 0.0, 0.0));

}