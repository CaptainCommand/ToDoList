/**************************************************************
*	Project: To Do List
*	Date Started: 1/29/2016
*	GlobalGameJam 2016 - Los Angeles
*	--------------------------------
*	PCharacter.h
*	By: George Wulfers
*	--------------------------------
*	This is the Player Class that the user will be using to
*	play the game
***************************************************************/

#include "ToDoList.h"
#include "PCharacter.h"
#include "Engine.h"


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
	InputComponent->BindAxis("CameraYaw", this, &APCharacter::AddControllerYawInput);
	InputComponent->BindAxis("CameraPitch", this, &APCharacter::AddControllerPitchInput);

	/*****************************
			PLAYER ACTION
	*****************************/
	InputComponent->BindAction("PlayerAction", IE_Pressed, this, &APCharacter::PlayerAction);
}

void APCharacter::PlayerAction()
{
	//TODO(George): Implement this function so that when 
	// the user presses the PlayerAction Button he would
	// interact with what ever object he is touching.
	
	// RayCast to get object for use.
	APUsableObject *UsableObject = GetObjectInView();

#if 1	//Do this only during debugging state

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, TEXT("Action not implemented yet..."));
	}

#endif // DEBUG

}

APUsableObject* APCharacter::GetObjectInView() const
{
	//Camera location and rotation
	FVector CamLoc;
	FRotator CamRot;

	//if our controller is empty return null
	if (Controller == NULL)
		return NULL;

	//Get the camera location and rotation
	Controller->GetPlayerViewPoint(CamLoc, CamRot);

	const FVector RayStart		= CamLoc;								//Ray Trace Start Position
	const FVector RayDirection	= CamRot.Vector();						//Ray Trace Direction
	const FVector RayEnd		= RayStart + (RayDirection * 500.0f);	//Ray Trace End Position

	//Get our Ray trace parameter
	FCollisionQueryParams RayParams(FName(TEXT("TraceActor")), true, this);
	RayParams.bTraceAsyncScene = true;
	RayParams.bReturnPhysicalMaterial = false;
	RayParams.bTraceComplex = false;

	FHitResult Hit(ForceInit);

	//Shoot a ray trace in the direction specified.
	GetWorld()->LineTraceSingleByChannel(Hit, RayStart, RayEnd, ECC_Visibility, RayParams);

#if 1
	DrawDebugLine(GetWorld(), RayStart, RayEnd, FColor::Red, false, 1.0f);
#endif	//DEBUG

	return Cast<APUsableObject>(Hit.GetActor());
}