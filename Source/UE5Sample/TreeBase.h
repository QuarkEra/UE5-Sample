// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Actor.h"
#include "FruitBase.h"
#include "TreeBase.generated.h"

UCLASS()
class UE5SAMPLE_API ATreeBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATreeBase();
	void SpawnFruit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	UCapsuleComponent* Capsule;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* TrunkMesh;
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* FoliageMesh;
	UPROPERTY(EditDefaultsOnly)
	USceneComponent* FruitSpawnPoint;

	UPROPERTY(VisibleAnywhere)
	int32 FruitAvailable = 2;
	
private:
	UPROPERTY(EditDefaultsOnly)
	class TSubclassOf<AFruitBase> FruitClass;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
