// Fill out your copyright notice in the Description page of Project Settings.


#include "TheGameInstance.h"

UTheGameInstance::UTheGameInstance()
{
	PreviousLevel = "";
	if (Season.IsEmpty())
	{
		Season.Add("Spring");
		Season.Add("Summer");
		Season.Add("Autumn");
		Season.Add("Winter");
	}

	CurrentSeason = Season[0];
}

void UTheGameInstance::IncrementDay()
{
	CurrentDay++;
	if (CurrentDay >= 4)
	{
		CurrentDay = 0;
	}
}

int UTheGameInstance::GetCurrentDay()
{
	return CurrentDay;
}

void UTheGameInstance::IncrementSeason()
{
	CurrentSeason = Season[SeasonIndex];
}

FName UTheGameInstance::GetCurrentSeason()
{
	return CurrentSeason;
}

void UTheGameInstance::IncrementSeasonIndex()
{
	SeasonIndex++;
	if (SeasonIndex > 3)
	{
		SeasonIndex = 0;
	}
}

int UTheGameInstance::GetSeasonIndex()
{
	return SeasonIndex;
}
