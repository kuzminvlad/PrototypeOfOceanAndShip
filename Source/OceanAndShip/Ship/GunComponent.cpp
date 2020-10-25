// Fill out your copyright notice in the Description page of Project Settings.


#include "GunComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"
#include "TimerManager.h"


UGunComponent::UGunComponent(){}

void UGunComponent::RotateToTarget(FVector GunLocation, FVector TargetLocation)
{
	PitchTargetRotation = UKismetMathLibrary::FindLookAtRotation(GunLocation, TargetLocation).Pitch;
	GetWorld()->GetTimerManager().SetTimer(RotateToTargetTimer, this, &UGunComponent::ChangeRotation, 0.02f, true);
}

void UGunComponent::ChangeRotation()
{
	float CurrentPitch = GetRelativeRotation().Pitch;
	if (fabs(CurrentPitch - PitchTargetRotation) <= RotationStep)
	{
		GetWorld()->GetTimerManager().ClearTimer(RotateToTargetTimer);
		return;
	}
	(GetRelativeRotation().Yaw < PitchTargetRotation) ? SetRelativeRotation(FRotator(CurrentPitch + RotationStep, 0.f, 0.f)) : SetRelativeRotation(FRotator(CurrentPitch - RotationStep, 0.f, 0.f));
}