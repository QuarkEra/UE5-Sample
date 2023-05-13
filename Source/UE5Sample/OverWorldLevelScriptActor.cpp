// Fill out your copyright notice in the Description page of Project Settings.


#include "OverWorldLevelScriptActor.h"

#include "TheGameInstance.h"
#include "Kismet/GameplayStatics.h"


void AOverWorldLevelScriptActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
}

AOverWorldLevelScriptActor::AOverWorldLevelScriptActor()
{
	
}

void AOverWorldLevelScriptActor::BeginPlay()
{
	Super::BeginPlay();

}

void AOverWorldLevelScriptActor::SetFoliageForSeason(FName Season)
{
	TArray<AActor*> Trees;
	UGameplayStatics::GetAllActorsOfClass(this, TreeClass, Trees);

	UTheGameInstance* GI = Cast<UTheGameInstance>(GetGameInstance());
	TSubclassOf<UStaticMeshComponent> StaticMeshes;
	TSubclassOf<UPrimitiveComponent> PrimClass;
	for (AActor* Tree : Trees)
	{
		if (GI->CurrentSeason == "Winter")
		{
			TArray<UActorComponent*> NewFoliage = Tree->GetComponentsByTag(StaticMeshes, "Seasonal");
			for (auto Foliage : NewFoliage)
			{
				AActor* OwnerActor = Foliage->GetOwner();
				UPrimitiveComponent* PrimitiveComponent = Cast<UPrimitiveComponent>(OwnerActor->GetComponentByClass(PrimClass));
				PrimitiveComponent->SetMaterial(0, Winter);
			}
		}
	}
}
