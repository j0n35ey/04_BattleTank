// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin Play"));

	if (!GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank not found"));
	}
	else if (GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank found %s"), *(GetControlledTank()->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("Player Controller is Ticking"));
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


