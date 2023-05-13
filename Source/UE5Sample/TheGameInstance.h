// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TheGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UE5SAMPLE_API UTheGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UTheGameInstance();
	
	FString PreviousLevel;
	int CurrentDay = 0;
	int CurrentYear = 0;
	TArray<FName> Season;
	FName CurrentSeason;
	int SeasonIndex = 0;

	UFUNCTION(BlueprintCallable)
	void IncrementDay();
	UFUNCTION(BlueprintCallable)
	int GetCurrentDay();
	UFUNCTION(BlueprintCallable)
	void IncrementSeason();
	UFUNCTION(BlueprintCallable)
	FName GetCurrentSeason();
	UFUNCTION(BlueprintCallable)
	void IncrementSeasonIndex();
	UFUNCTION(BlueprintCallable)
	int GetSeasonIndex();

private:

};
