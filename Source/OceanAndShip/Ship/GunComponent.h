// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "GunComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OCEANANDSHIP_API UGunComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	UGunComponent();
};
