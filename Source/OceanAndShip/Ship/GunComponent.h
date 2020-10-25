// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "GunComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OCEANANDSHIP_API UGunComponent : public USceneComponent
{
	GENERATED_BODY()

protected:
	FTimerHandle RotateToTargetTimer;
	float RotationStep = 0.5f;
	float PitchTargetRotation = 0.f;
	void ChangeRotation();

public:
	UGunComponent();

	UFUNCTION(BlueprintCallable, Category = "Gun")
	void RotateToTarget(FVector GunLocation, FVector TargetLoation, FRotator ActorRotation);
};
