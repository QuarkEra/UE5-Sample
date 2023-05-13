// Fill out your copyright notice in the Description page of Project Settings.


#include "SunLight.h"

#include "Components/DirectionalLightComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnitConversion.h"

// Sets default values
ASunLight::ASunLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(RootComp);
	SunLightDirection = CreateDefaultSubobject<UDirectionalLightComponent>(TEXT("Sun Direction"));
	SunLightDirection->SetupAttachment(RootComp);
	
}

// Called when the game starts or when spawned
void ASunLight::BeginPlay()
{
	Super::BeginPlay();

	
	// GI = Cast<UTheGameInstance>(GetGameInstance());
	
}

// Called every frame
void ASunLight::Tick(float DeltaTime)
{
 /*
	float DT = DeltaTime * SpeedSun;
	FRotator NewRotation = FRotator::ZeroRotator;
	NewRotation.Pitch += DT + OldAngle;
	OldAngle = NewRotation.Pitch;
	if (OldAngle >= 360.0f)
	{
		float Remainder;
		Remainder = OldAngle - 360;
		OldAngle = Remainder;
	}
	
	SetActorRotation(NewRotation);
	
	if (GetActorRotation().Pitch >= 360.f)
	{
		UE_LOG(LogTemp,Display,TEXT("New day"));
		SetActorRelativeRotation(FRotator(0.f));
		GI->CurrentDay++;
		if (GI->CurrentDay >= 1)
		{
			GI->ChangeSeason();
		}
	}
	*/

}

