// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


class ATank;
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Screen")
		float CrossHairXLocation{ 0.5f };
	UPROPERTY(EditAnywhere, Category = "Screen")
		float CrossHairYLocation{ 0.3333f };
	UPROPERTY(EditAnywhere, Category = "Screen")
		float LineTraceRange = 100000.0f;
private:
	ATank* GetControlledTank() const;

	void AimTowardsCrosshair();
	
	bool GetSightRayHitLocation(FVector& OUT_HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
 