// Fill out your copyright notice in the Description page of Project Settings.

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

	//AToDoListGameMode();
	
	
};
