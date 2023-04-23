// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Components/InputComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerCharacter::MoveUpDown(const FInputActionValue& Value)
{
	FVector Delta = FVector::ZeroVector;
	Delta.X = -Value.GetMagnitude();
	AddMovementInput(Delta);
}

void APlayerCharacter::MoveLeftRight(const FInputActionValue& Value)
{
	FVector Delta = FVector::ZeroVector;
	Delta.Y = -Value.GetMagnitude();
	AddMovementInput(Delta);
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	UEnhancedInputLocalPlayerSubsystem* eiSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
	eiSubsystem->AddMappingContext(InputMappingContext, 0);
	UEnhancedInputComponent* eiInput = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	eiInput->BindAction(InputMoveUp, ETriggerEvent::Triggered, this, &APlayerCharacter::MoveUpDown);
	eiInput->BindAction(InputMoveLeftRight,ETriggerEvent::Triggered, this, &APlayerCharacter::MoveLeftRight);
}

