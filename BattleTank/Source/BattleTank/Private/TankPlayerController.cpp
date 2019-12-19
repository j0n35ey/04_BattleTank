// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Engine/World.h"
#include "Camera/PlayerCameraManager.h"
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
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // out parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OUT_HitLocation) const
{
	OUT_HitLocation = FVector(0, 1, 0);

	//Find Crosshair pixel coordinates
	int32 ViewPortSizeX, ViewPortSizeY;
	GetViewportSize(ViewPortSizeX, ViewPortSizeY);
	FVector2D ScreenLocation(ViewPortSizeX * CrossHairXLocation, ViewPortSizeY * CrossHairYLocation);

	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		GetLookVectorHitLocation(LookDirection, OUT_HitLocation);
	}

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // to be discarded
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation ) const
{
	FHitResult hit;
	auto StartLocation = PlayerCameraManager->GetCameraLocation(); 
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	
	if(GetWorld()->LineTraceSingleByChannel
	(
		hit,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility,
		FCollisionQueryParams::DefaultQueryParam,
		FCollisionResponseParams::DefaultResponseParam
	))
	{
		HitLocation = hit.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}



