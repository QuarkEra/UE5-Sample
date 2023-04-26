// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class UE5SAMPLE_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	virtual FString InitNewPlayer(APlayerController* NewPlayerController, const FUniqueNetIdRepl& UniqueId, const FString& Options, const FString& Portal) override;

public:
	AMyGameModeBase();

	void LoadTargetLevel(FName LevelName);

	void SetPreviousLevel();
	FString CurrentLevel;
};
