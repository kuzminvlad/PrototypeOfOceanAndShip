// Fill out your copyright notice in the Description page of Project Settings.

#include "Ocean.h"

AOcean::AOcean(){}

float AOcean::GetHeightOfWave(FVector Position, float Time)
{
	WaveDirection.Normalize();
	Position.Z = 0.f;

	float TempEquation1 = (2.f * PI) / WaveLenghth;
	FVector TempVector = WaveDirection * TempEquation1;
	float TempEquation2 = TempVector.DotProduct(Position, TempVector) - sqrt(TempEquation1 * 980.f) * Time;

	FVector VectorOfWave = cosf(TempEquation2) * FVector(0, 0, 1) * WaveHeight - 
				  (WaveDirection * (sinf(TempEquation2) * (Steapness / (TempEquation1 * WaveHeight) * WaveHeight)));

	return VectorOfWave.Z;
}
