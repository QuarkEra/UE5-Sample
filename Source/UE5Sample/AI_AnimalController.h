// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AI_AnimalController.generated.h"

/**
 * 
 */
UCLASS()
class UE5SAMPLE_API AAI_AnimalController : public AAIController
{
	GENERATED_BODY()
public:
	AAI_AnimalController();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaSeconds) override;
	
};
