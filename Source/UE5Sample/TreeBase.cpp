// Fill out your copyright notice in the Description page of Project Settings.


#include "TreeBase.h"


// Sets default values
ATreeBase::ATreeBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	RootComponent = Capsule;
	TrunkMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Trunk"));
	TrunkMesh->SetupAttachment(Capsule);
	FoliageMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Foliage"));
	FoliageMesh->SetupAttachment(TrunkMesh);
	FruitSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Fruit Spawn Point"));
	FruitSpawnPoint->SetupAttachment(FoliageMesh);

}

// Called when the game starts or when spawned
void ATreeBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ATreeBase::SpawnFruit()
{
	if (FruitAvailable > 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Spawning Fruit"));
		--FruitAvailable;
		FVector Location = FruitSpawnPoint->GetComponentLocation();
		FRotator Rotation = FruitSpawnPoint->GetComponentRotation();
	
		GetWorld()->SpawnActor<AFruitBase>(FruitClass, Location, Rotation);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No available fruit"));
	}
	
}

// Called every frame
void ATreeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

