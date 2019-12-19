// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Tank AI Controller Begin Play"));
	
	if (!GetPlayerTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller not found player tank"));
	}
	else if (GetPlayerTank())
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player tank: "), *(GetPlayerTank()->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (PlayerPawn)
		return Cast<ATank>(PlayerPawn);
	else return nullptr;
}