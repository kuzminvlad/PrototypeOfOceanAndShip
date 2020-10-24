// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ship.generated.h"

UCLASS()
class OCEANANDSHIP_API AShip : public AActor
{
	GENERATED_BODY()
	
public:	
	AShip();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Ship")
	class UHullComponent* HullSceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Ship")
	class UStaticMeshComponent* HullMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Ship")
	class UTurretComponent* TurretSceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Ship")
	class UStaticMeshComponent* TurretMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Ship")
	class UGunComponent* GunSceneComponent;	

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Ship")
	class UStaticMeshComponent* GunMeshComponent;
};
