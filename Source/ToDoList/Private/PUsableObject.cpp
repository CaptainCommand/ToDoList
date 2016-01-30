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

#include "ToDoList.h"
#include "PUsableObject.h"


// Sets default values
APUsableObject::APUsableObject(const class FObjectInitializer &ObjectInit)
	: Super(ObjectInit)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Setup components for use
	//Collision Sphere used for Ray Cast
	m_CollisionSphere = ObjectInit.CreateDefaultSubobject<USphereComponent>(this, TEXT("Collision Sphere"));
	m_CollisionSphere->InitSphereRadius(15.0f);
	RootComponent = m_CollisionSphere;

	//Setup the Mesh component
	m_Mesh = ObjectInit.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
	m_Mesh->AttachTo(RootComponent);

	//Particle System used for when object is used.
	m_Particles = ObjectInit.CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("Particle System"));
	m_Particles->AttachTo(RootComponent);

	//Sound effect to be played when this object is used.
	m_Sound = ObjectInit.CreateDefaultSubobject<USoundCue>(this, TEXT("Sound Effect"));

}

// Called when the game starts or when spawned
void APUsableObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APUsableObject::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void APUsableObject::OnUse()
{

}