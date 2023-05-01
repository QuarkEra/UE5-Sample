// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactor.h"


// Sets default values for this component's properties
UInteractor::UInteractor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UInteractor::Interact()
{
	FHitResult HitResult;
	FCollisionShape Sphere = FCollisionShape::MakeSphere(InteractRadius);
	FVector Start = GetComponentLocation();
	FVector End = Start + GetForwardVector() * 50.f;
	bool Hit = GetWorld()->SweepSingleByChannel(
		HitResult,
		Start,
		End,
		FQuat::Identity,
		ECC_GameTraceChannel1,
		Sphere
		);
	if (Hit)
	{
		AActor* HitActor = HitResult.GetActor();
		if (HitActor != nullptr)
		{
			ATreeBase* Tree = Cast<ATreeBase>(HitActor);
			if (Tree != nullptr)
			{
				Tree->SpawnFruit();
			}
			AFruitBase* Fruit = Cast<AFruitBase>(HitActor);
			if (Fruit != nullptr)
			{
				Fruit->Destroy();
				UE_LOG(LogTemp, Warning, TEXT("Picking up fruit"));
			}
		}
	}
}


// Called when the game starts
void UInteractor::BeginPlay()
{
	Super::BeginPlay();

	UInteractor* Interactor = GetOwner()->FindComponentByClass<UInteractor>();
	if (Interactor != nullptr)
	{
		UE_LOG(LogTemp,Display,TEXT("Interactor component found"));
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("Interactor component not found"));
	}
	// ...
	
}


// Called every frame
void UInteractor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

