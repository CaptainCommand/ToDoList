// Fill out your copyright notice in the Description page of Project Settings.

#include "ToDoList.h"
#include "PCharacter.h"


// Sets default values
APCharacter::APCharacter(const class FObjectInitializer &ObjectInit)
	: Super(ObjectInit.SetDefaultSubobjectClass<UCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Setup our character movement component
	UCharacterMovementComponent* MovementComponent = GetCharacterMovement();
	MovementComponent->GravityScale = 1.5f;

	//Initialize out CameraComponent
	m_Camera = ObjectInit.CreateDefaultSubobject<UCameraComponent>(this, TEXT("FirstPersonCamera"));

	//Disable Crouching
	MovementComponent->GetNavAgentPropertiesRef().bCanCrouch = false;

}

// Called when the game starts or when spawned
void APCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void APCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	/*****************************
		  CAMERA ROTATION
	*****************************/
	InputComponent->BindAxis("CameraYaw", this, &APCharacter::CameraYaw);
	InputComponent->BindAxis("CameraPitch", this, &APCharacter::CameraPitch);

	/*****************************
			PLAYER ACTION
	*****************************/
	//InputComponent->BindAction)
}

//Mapped to X-Axis
// This function rotates the camera along the X-Axis 
// so that the player can look left and right
// you will be able to call this function via the blueprint system
void APCharacter::CameraYaw(float _value)
{
	if (_value != 0.0f)
	{
		AddControllerYawInput(_value);
	}
}

//Mapped to Y-Axis
// This function rotates the camera along the Y-Axis 
// so that the player can look up and down
// you will be able to call this function via the blueprint system
void APCharacter::CameraPitch(float _value)
{
	if (_value != 0.0f)
	{
		AddControllerPitchInput(_value);
	}
}

void APCharacter::PlayerAction()
{
	//TODO(George): Implement this function so that when 
	// the user presses the PlayerAction Button he would
	// interact with what ever object he is touching.
}