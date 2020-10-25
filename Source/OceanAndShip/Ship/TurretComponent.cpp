// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"
#include "TimerManager.h"

UTurretComponent::UTurretComponent(){}

void UTurretComponent::RotateToTarget(FVector TurretLocation, FVector TargetLocation, FRotator ActorRotation)
{
	YawTargetRotation = UKismetMathLibrary::FindLookAtRotation(TurretLocation, TargetLocation).Yaw - ActorRotation.Yaw;
	GetWorld()->GetTimerManager().SetTimer(RotateToTargetTimer, this, &UTurretComponent::ChangeRotation, 0.02f, true);
}

void UTurretComponent::ChangeRotation()
{
	float CurrentYaw = GetRelativeRotation().Yaw;
	if (fabs(CurrentYaw - YawTargetRotation) <= RotationStep)
	{
		GetWorld()->GetTimerManager().ClearTimer(RotateToTargetTimer);
		return;
	}
	(CurrentYaw < YawTargetRotation) ? SetRelativeRotation(FRotator(0.f, CurrentYaw + RotationStep, 0.f)) : SetRelativeRotation(FRotator(0.f, CurrentYaw - RotationStep, 0.f));
}
