// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_AnimalController.h"

#include "Kismet/GameplayStatics.h"


AAI_AnimalController::AAI_AnimalController()
{
}

void AAI_AnimalController::BeginPlay()
{
	Super::BeginPlay();
	
	
}

void AAI_AnimalController::Tick(float DeltaSeconds)	
{
	Super::Tick(DeltaSeconds);
	
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	if (PlayerPawn != nullptr)
	{
		SetFocus(PlayerPawn);
		MoveToActor(PlayerPawn, 100);
	}
}
