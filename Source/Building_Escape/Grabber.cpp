// Copyright Juan Aguilera (@juan.gdev)

#include "GameFramework/PlayerController.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "Math/Color.h"
#include "Grabber.h"

#define OUT //Used for our variables that are output parameters

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	FindPhysicsHandle();
	SetupInputComponent();
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//	If he phyisc handle is attach
		//	Move the object we are holding
	GetFirstPhysicsBodyInReach();
}

void UGrabber::Grab()
{
	UE_LOG(LogTemp, Warning, TEXT("Action: Grab"));

	//	Try and reach any actors with physics body collision channel set

	//	If we hit something then attach the physics hadle
	//	TO DO. Attach physics handle

}

void UGrabber::Release()
{
	UE_LOG(LogTemp, Warning, TEXT("Action: Release"));
	//	TO DO remove/release the physics handle
}

//	Checking for PhysicsHandleComponent
void UGrabber::FindPhysicsHandle()
{
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if(PhysicsHandle){
		UE_LOG(LogTemp, Warning, TEXT("Everything is right!"));
	}
	else{
		UE_LOG(LogTemp, Error, TEXT("%s does not have any PhysicsHandleComponent"), *GetOwner()->GetName());
	}
}

void UGrabber::SetupInputComponent()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	if(InputComponent){
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
}

FHitResult UGrabber::GetFirstPhysicsBodyInReach() const
{
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerViewPointLocation, OUT PlayerViewPointRotation);

	FVector LineTraceEnd = PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;

	//Logging the hit
	FHitResult Hit; //Out parameter
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerViewPointLocation,
		LineTraceEnd,
		FCollisionObjectQueryParams (ECollisionChannel::ECC_PhysicsBody),
		TraceParams
	);
	
	AActor* ActorHit = Hit.GetActor();

	if(ActorHit)
	{
		UE_LOG(LogTemp, Error, TEXT("Line trace has hit: %s"), *(ActorHit->GetName()));
	}

	return Hit;
}