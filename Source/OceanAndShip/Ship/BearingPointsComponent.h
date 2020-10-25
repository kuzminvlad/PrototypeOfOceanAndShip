// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../Ocean.h"
#include "BearingPointsComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OCEANANDSHIP_API UBearingPointsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UBearingPointsComponent();
	 
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Buoyancy")
	TArray<FVector> Points;

	UFUNCTION(BlueprintCallable, Category = "Buoyancy")
	FRotator GetActorNewRotator(FVector AbsoluteActorLocation, FRotator AbsoluteActorRotator, AOcean* Ocean, float Time);
};
