// Fill out your copyright notice in the Description page of Project Settings.


#include "Ship.h"
#include "HullComponent.h"
#include "TurretComponent.h"
#include "GunComponent.h"
#include "Components/StaticMeshComponent.h"

AShip::AShip()
{
	HullSceneComponent = CreateDefaultSubobject<UHullComponent>(TEXT("HullComponent"));
	SetRootComponent(HullSceneComponent);

	HullMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HullMesh"));
	HullMeshComponent->SetupAttachment(HullSceneComponent);

	TurretSceneComponent = CreateDefaultSubobject<UTurretComponent>(TEXT("TurretComponent"));
	TurretSceneComponent->SetupAttachment(HullSceneComponent);

	TurretMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
	TurretMeshComponent->SetupAttachment(TurretSceneComponent);

	GunSceneComponent = CreateDefaultSubobject<UGunComponent>(TEXT("GunComponent"));
	GunSceneComponent->SetupAttachment(TurretSceneComponent);

	GunMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GunMesh"));
	GunMeshComponent->SetupAttachment(GunSceneComponent);
}
