#include "BuildingEscape.h"
#include "WallLamp.h"

// Sets default values
AWallLamp::AWallLamp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWallLamp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWallLamp::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Used to give the lamp state to components of the lamp.
bool AWallLamp::GetState() const
{
    return ATriggerObject::GetState();
}

// Used to set the lamp state through components of the lamp.
void AWallLamp::ToggleState()
{
    ATriggerObject::Toggle();
}