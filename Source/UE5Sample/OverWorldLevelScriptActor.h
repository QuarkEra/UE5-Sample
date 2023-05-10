// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SunLight.h"
#include "Engine/LevelScriptActor.h"
#include "OverWorldLevelScriptActor.generated.h"


/**
 * 
 */
UCLASS()
class UE5SAMPLE_API AOverWorldLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()
public:
	virtual void Tick(float DeltaSeconds) override;

	AOverWorldLevelScriptActor();
	virtual void BeginPlay() override;

protected:
	TSubclassOf<ASunLight> SunLightClass;
	ASunLight* Sun;
	
private:
	float SpeedSun = 10.0f;
	float AngleSun = 240.0f;
	int32 Day = 0; // 0-1 Spring/Summer, Autumn/Winter, to make things easy for now
	
};
