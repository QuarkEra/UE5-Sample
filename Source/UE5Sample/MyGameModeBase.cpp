// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"

#include "EngineUtils.h"
#include "TheGameInstance.h"
#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"


FString AMyGameModeBase::InitNewPlayer(APlayerController* NewPlayerController, const FUniqueNetIdRepl& UniqueId,
                                       const FString& Options, const FString& Portal)
{
	CurrentLevel = UGameplayStatics::GetCurrentLevelName(this);
	UE_LOG(LogTemp, Warning, TEXT("Current Level: %s"), *CurrentLevel);
	UTheGameInstance* Instance = Cast<UTheGameInstance>(GetThisGameInstance());
	for (TActorIterator<APlayerStart> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		FName Tag = ActorItr->PlayerStartTag;
		FString StringTag = Tag.ToString();
		UE_LOG(LogTemp, Warning, TEXT("Start Tag: %s"), *StringTag);
		if (Instance == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("Instance is nullptr"));
			return Super::InitNewPlayer(NewPlayerController, UniqueId, Options, Portal);
		}
		FString PreviousLevel = Instance->PreviousLevel;
		if (StringTag == PreviousLevel)
		{
			UE_LOG(LogTemp, Warning, TEXT("Start Tag equal to previous level: %s"), *StringTag);
			return Super::InitNewPlayer(NewPlayerController, UniqueId, Options, StringTag);
		}
	}
	return Super::InitNewPlayer(NewPlayerController, UniqueId, Options, Portal);
}

UGameInstance* AMyGameModeBase::GetThisGameInstance()
{
	UTheGameInstance* Instance = Cast<UTheGameInstance>(GetGameInstance());
	return Instance;
}

AMyGameModeBase::AMyGameModeBase()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_Player"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AMyGameModeBase::LoadTargetLevel(FName LevelName)
{
	UGameplayStatics::OpenLevel(this, LevelName);
}

void AMyGameModeBase::SetPreviousLevel()
{
	UTheGameInstance* Instance = Cast<UTheGameInstance>(GetThisGameInstance());
	if (Instance == nullptr)
	{
		return;
	}
	Instance->PreviousLevel = UGameplayStatics::GetCurrentLevelName(this);
}


