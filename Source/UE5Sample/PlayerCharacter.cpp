// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "AIHelpers.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "MyGameModeBase.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	InteractorComponent = CreateDefaultSubobject<UInteractor>(TEXT("Interactor"));
	InteractorComponent->SetupAttachment(RootComponent);
	
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->bIgnoreBaseRotation = true;

	bUseControllerRotationYaw = true;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	AMyGameModeBase* TheGameMode = Cast<AMyGameModeBase>(GetWorld()->GetAuthGameMode());
	if (TheGameMode != nullptr)
	{
		TheGameMode->SetPreviousLevel();			
	}
	
}

void APlayerCharacter::MoveUpDown(const FInputActionInstance& Instance)
{
	const float FloatValue = Instance.GetValue().Get<float>();
	if ((Controller != nullptr) && (FloatValue != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

		AddMovementInput(Direction, FloatValue);
	}
}

void APlayerCharacter::MoveLeftRight(const FInputActionInstance& Instance)
{
	const float FloatValue = Instance.GetValue().Get<float>();
	if ((Controller != nullptr) && (FloatValue != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		AddMovementInput(Direction, FloatValue);
	}
}


void APlayerCharacter::Interact(const FInputActionInstance& Instance)
{
	if (Controller != nullptr)
	{
		InteractorComponent->Interact();
	}
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (APlayerController* LocalPlayer = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* InputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer->GetLocalPlayer()))
		{
			if (!InputMapping.IsNull())
			{
				InputSystem->AddMappingContext(InputMapping.LoadSynchronous(), 1);
	 		}
	 	}
	}	
	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (Input != nullptr)
	{
		Input->BindAction(InputMoveUp, ETriggerEvent::Triggered, this, &APlayerCharacter::MoveUpDown);
		Input->BindAction(InputMoveLeftRight,ETriggerEvent::Triggered, this, &APlayerCharacter::MoveLeftRight);
		Input->BindAction(InputInteract, ETriggerEvent::Triggered, this, &APlayerCharacter::Interact);
	}

	
}

