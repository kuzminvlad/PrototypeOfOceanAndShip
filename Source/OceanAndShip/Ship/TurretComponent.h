// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "TurretComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OCEANANDSHIP_API UTurretComponent : public USceneComponent
{
	GENERATED_BODY()

protected:
	FTimerHandle RotateToTargetTimer;
	float RotationStep = 0.5f;
	float YawTargetRotation = 0.f;
	void ChangeRotation();

public:	
	UTurretComponent();

	UFUNCTION(BlueprintCallable, Category = "Turret")
	void RotateToTarget(FVector TurretLocation, FVector TargetLocation);
};
