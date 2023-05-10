// Fill out your copyright notice in the Description page of Project Settings.


#include "OverWorldLevelScriptActor.h"

#include "Kismet/GameplayStatics.h"


void AOverWorldLevelScriptActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	
	if (!ensure(Sun != nullptr))
	{
		return;
	}
	float Delta = SpeedSun * DeltaSeconds;
	float NewAngle = Delta + AngleSun;
	AngleSun = NewAngle;
	FRotator NewRotation = FRotator::ZeroRotator;
	NewRotation.Pitch = NewAngle;
	Sun->SetActorRotation(NewRotation);
	if (Sun->GetActorRotation().Pitch >= 360.f)
	{
		UE_LOG(LogTemp,Display,TEXT("Sun pitch greater than 360"));
		Sun->SetActorRotation(FRotator::ZeroRotator);
		Day++;
	}
	
}

AOverWorldLevelScriptActor::AOverWorldLevelScriptActor()
{
	
	
}

void AOverWorldLevelScriptActor::BeginPlay()
{
	Super::BeginPlay();

	// This always fails :(
	ASunLight* FoundSun = Cast<ASunLight>(UGameplayStatics::GetActorOfClass(this, SunLightClass));
	if (!ensure(FoundSun != nullptr))
	{
		UE_LOG(LogTemp,Display,TEXT("No Sun found in array"));
		return;
	}
	UE_LOG(LogTemp,Display,TEXT("Found Sun, %s"), *Sun->GetName());
	Sun = FoundSun;

}
