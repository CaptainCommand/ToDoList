/**************************************************************
*	Project: To Do List
*	Date Started: 1/29/2016
*	GlobalGameJam 2016 - Los Angeles
*	--------------------------------
*	ToDoListGameMode.h
*	By: George Wulfers
*	--------------------------------
*	Default Game mode for our game.
*	Here we will set and keep track of our scores
*	And Other player data.
***************************************************************/

#pragma once

#include "GameFramework/GameMode.h"
#include "Public/PCharacter.h"

#include "ToDoListGameMode.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, Meta = (ChildCanTick))
class TODOLIST_API AToDoListGameMode : public AGameMode
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "OurGameMode")
	int32 m_Score;

public:

	AToDoListGameMode();
	
	virtual void StartPlay() override;
	
};
