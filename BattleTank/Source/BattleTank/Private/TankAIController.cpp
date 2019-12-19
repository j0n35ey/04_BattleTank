// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Tank AI Controller Begin Play"));
	
	if (!GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank not found"));
	}
	else if (GetControlledTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank found %s"), *(GetControlledTank()->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
