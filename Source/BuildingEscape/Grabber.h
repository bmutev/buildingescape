// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:
	// How far ahead of the player can we reach in cm
    UPROPERTY(EditAnywhere)
    float Reach = 100.f;

    UPhysicsHandleComponent* PhysicsHandle = nullptr;

    UInputComponent* InputComponent = nullptr;

    // Ray-casst and grab what is in reach
    void Grab();

    // Called when grab is released
    void Release();

    // Find (assumed) attached physics handle
    void FindPhysicsComponent();

    // Setup (assumed) attached input component
    void SetupInputComponent();	

    // Return hit for first physics body in reach
    const FHitResult GetFirstPhysicsBodyInReach();

    // Get current start of reach line
    FVector GetReachLineStart();

    // Get current end of reach line
    FVector GetReachLineEnd();
};
