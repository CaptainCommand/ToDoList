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

#pragma once

#include "GameFramework/Character.h"
#include "PUsableObject.h"

#include "PCharacter.generated.h"

UCLASS()
class TODOLIST_API APCharacter : public ACharacter
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* m_Camera;

public:
	// Sets default values for this character's properties
	APCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	//used for object interaction
	UFUNCTION(BlueprintCallable, Category = "Action")
	void PlayerAction();

protected:
	// returns an object for use with PlayerAction()
	class APUsableObject* GetObjectInView() const;

};
