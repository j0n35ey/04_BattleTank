// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.h"
UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	if (!BarrelToSet) { return; }
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret* TurretToSet)
{
	if (!TurretToSet) { return; }
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel)
	{
		UE_LOG(LogTemp, Warning, TEXT("Barrel Not Found"));
		return;
	}
	else if (!Turret)
	{
		UE_LOG(LogTemp, Warning, TEXT("Barrel Not Found"));
		return;
	}
	else UE_LOG(LogTemp, Warning, TEXT("Barrel And Turret Found"));

	FVector OutLaunchVelocity(0);
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, HitLocation, LaunchSpeed,false,0.0f,0.0f,ESuggestProjVelocityTraceOption::DoNotTrace);
	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto TankName = GetOwner()->GetName();

		MoveTurretTowards(AimDirection);
		MoveBarrelTowards(AimDirection);

	}
	else
	{
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: Aim solution not found"), Time);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAtRotator = AimDirection.Rotation(); 
	auto DeltaRotator = AimAtRotator - BarrelRotator;

	Barrel->Elevate(DeltaRotator.Pitch);
}

void UTankAimingComponent::MoveTurretTowards(FVector AimDiretion)
{
	auto TurretRotator = Turret->GetForwardVector().Rotation();
	auto AimAtRotator = AimDiretion.Rotation();
	auto DeltaRotator = AimAtRotator - TurretRotator;

	Turret->RotateTowardsDirection(DeltaRotator.Yaw);
}

