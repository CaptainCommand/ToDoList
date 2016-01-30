/**************************************************************
*	Project: To Do List
*	Date Started: 1/29/2016
*	GlobalGameJam 2016 - Los Angeles
*	--------------------------------
*	PUsableObject.h
*	By: George Wulfers
*	--------------------------------
*	This will be the base class for our usable objects
***************************************************************/

#pragma once

#include "GameFramework/Actor.h"
#include "PUsableObject.generated.h"

UCLASS()
class TODOLIST_API APUsableObject : public AActor
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
	USphereComponent* m_CollisionSphere;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Particles")
	UParticleSystemComponent* m_Particles;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Sound Effect")
	USoundCue* m_Sound;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
	UStaticMeshComponent* m_Mesh;

public:	
	// Sets default values for this actor's properties
	APUsableObject();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	//MUST implement in derrived class
	UFUNCTION(BlueprintCallable, Category = "USE")
	virtual void OnUse();
	
};
