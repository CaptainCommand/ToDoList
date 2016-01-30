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

#include "ToDoList.h"
#include "ToDoListGameMode.h"

AToDoListGameMode::AToDoListGameMode(const class FObjectInitializer &ObjectInit)
	: Super(ObjectInit)
{
	//Set the default player to our Player class
	DefaultPawnClass = APCharacter::StaticClass();
}

void AToDoListGameMode::StartPlay()
{
	Super::StartPlay();
}