// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorClass.h"

#include "MyGameModeBase.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ADoorClass::ADoorClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OverlappingVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	RootComponent = OverlappingVolume;
	OverlappingVolume->OnComponentBeginOverlap.AddDynamic(this, &ADoorClass::OverlapBegins);
}

// Called when the game starts or when spawned
void ADoorClass::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADoorClass::OverlapBegins(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APawn* MyCharacter = UGameplayStatics::GetPlayerPawn(this, 0);
	AMyGameModeBase* GameMode = GetWorld()->GetAuthGameMode<AMyGameModeBase>();
	if (GameMode != nullptr )
	{
		if (OtherActor == MyCharacter && LevelToLoad != "")	
		{
			GameMode->LoadTargetLevel(LevelToLoad);
		}
	}
	
}

// Called every frame
void ADoorClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



