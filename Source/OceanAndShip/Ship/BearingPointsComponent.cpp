// Fill out your copyright notice in the Description page of Project Settings.


#include "BearingPointsComponent.h"
#include "Kismet/KismetMathLibrary.h"

UBearingPointsComponent::UBearingPointsComponent()
{
}

FRotator UBearingPointsComponent::GetActorNewRotator(FVector AbsoluteActorLocation, FRotator AbsoluteActorRotator, AOcean* Ocean, float Time)
{
	if (Points.Num() <= 1) return AbsoluteActorRotator;

	FVector PointMaxX = Points[0];
	FVector PointMaxY = Points[0];
	for (FVector& Point : Points)
	{
		if (Point.X > PointMaxX.X)
		{
			PointMaxX = Point;
		}
		if (Point.Y > PointMaxY.Y)
		{
			PointMaxY = Point;
		}
	}
	PointMaxX.Z = AbsoluteActorLocation.Z;
	PointMaxY.Z = AbsoluteActorLocation.Z;
	PointMaxX = AbsoluteActorRotator.RotateVector(PointMaxX);
	PointMaxY = AbsoluteActorRotator.RotateVector(PointMaxY);

	float HeightOfWaveForPointMaxX = Ocean->GetHeightOfWave(PointMaxX + AbsoluteActorLocation, Time);
	float HeightOfWaveForPointMaxY = Ocean->GetHeightOfWave(PointMaxY + AbsoluteActorLocation, Time);

	float Pitch = UKismetMathLibrary::DegAcos(UKismetMathLibrary::Dot_VectorVector(PointMaxX, FVector(PointMaxX.X, PointMaxX.Y, HeightOfWaveForPointMaxX)) /
		(UKismetMathLibrary::VSize(PointMaxX) * UKismetMathLibrary::VSize(FVector(PointMaxX.X, PointMaxX.Y, HeightOfWaveForPointMaxX))));
	float Roll = UKismetMathLibrary::DegAcos(UKismetMathLibrary::Dot_VectorVector(PointMaxY, FVector(PointMaxY.X, PointMaxY.Y, HeightOfWaveForPointMaxY)) /
		(UKismetMathLibrary::VSize(PointMaxY) * UKismetMathLibrary::VSize(FVector(PointMaxY.X, PointMaxY.Y, HeightOfWaveForPointMaxY))));

	if (PointMaxX.Z > HeightOfWaveForPointMaxX)
		Pitch = -Pitch;
	if (PointMaxY.Z < HeightOfWaveForPointMaxY)
		Roll = -Roll;

	return FRotator(AbsoluteActorRotator.Pitch + Pitch, AbsoluteActorRotator.Yaw, AbsoluteActorRotator.Roll + Roll);
}
