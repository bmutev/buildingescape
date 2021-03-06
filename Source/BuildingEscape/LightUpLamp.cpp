#include "BuildingEscape.h"
#include "LightUpLamp.h"

#define OUT

// Sets default values for this component's properties
ULightUpLamp::ULightUpLamp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULightUpLamp::BeginPlay()
{
	Super::BeginPlay();
    
    Owner = Cast<AWallLamp>(GetOwner()); 
}


// Called every frame
void ULightUpLamp::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

    // Switch ON/OFF the lamp based on actor presence
    TArray<AActor*> OverlappingActors;
    if (!PressurePlate) { return; }

    PressurePlate->GetOverlappingActors(
        OUT OverlappingActors
    );

    if (OverlappingActors.Num() > 0)
    {
        if (!Owner->GetState())
        {
            Owner->ToggleState();
        }
    }

    // Switch ON/OFF the lamp based on lamp precense   
    if (Owner->GetState())
    {
        LightUp.Broadcast();
    }
    else
    {
        LightDown.Broadcast();     
    }
}