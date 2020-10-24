// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ocean.generated.h"

UCLASS()
class OCEANANDSHIP_API AOcean : public AActor
{
	GENERATED_BODY()

protected:
	float Steapness = 1.f;
	
public:	
	AOcean();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waves")
	float WaveHeight = 24.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waves")
	float WaveLenghth = 450.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Waves")
	FVector WaveDirection = FVector(1.f, 0.f, 0.f);

	UFUNCTION(BlueprintCallable, Category = "Waves")
	float GetHeightOfWave(FVector Position, float Time);
};
