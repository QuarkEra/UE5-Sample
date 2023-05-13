// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TreeBase.h"
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
	TSubclassOf<ATreeBase> TreeClass;

	// Set Materials in Level Blueprint 
	UPROPERTY(EditAnywhere)
	UMaterial* Winter;
	
private:
	void SetFoliageForSeason(FName Season);
	
	
};
