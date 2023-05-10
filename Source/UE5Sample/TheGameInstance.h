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
	int32 Day;
};
