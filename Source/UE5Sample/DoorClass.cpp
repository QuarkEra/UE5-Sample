// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorClass.h"

#include "MyGameModeBase.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ADoorClass::ADoorClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoorClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoorClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoorClass::OpenDoor()
{
	AMyGameModeBase* GM = Cast<AMyGameModeBase>(GetWorld()->GetAuthGameMode());
	GM->LoadTargetLevel(LevelToLoad);
}



