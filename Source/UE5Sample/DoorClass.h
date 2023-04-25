// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyGameModeBase.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "DoorClass.generated.h"

UCLASS()
class UE5SAMPLE_API ADoorClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoorClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="Components")
	FName LevelToLoad;
	UFUNCTION()
	void OverlapBegins(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);	

private:
	UPROPERTY(EditAnywhere, Category="Components")
	UBoxComponent* OverlappingVolume;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	

};
