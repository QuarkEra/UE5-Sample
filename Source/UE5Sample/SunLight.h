// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TheGameInstance.h"
#include "Engine/DirectionalLight.h"
#include "GameFramework/Actor.h"
#include "SunLight.generated.h"

UCLASS()
class UE5SAMPLE_API ASunLight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASunLight();
	//UPROPERTY(EditAnywhere)
	//float SpeedSun = 100.0f;
	//float OldAngle;
	
	UPROPERTY(EditAnywhere)
	USceneComponent* RootComp;
	UPROPERTY(EditAnywhere)
	UDirectionalLightComponent* SunLightDirection;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	//UTheGameInstance* GI;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
