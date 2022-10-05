// Copyright Juan Aguilera (@juan.gdev)


#include "OpenDoor.h"
#include "GameFramework/Actor.h"
// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	initialYaw = GetOwner()->GetActorRotation().Yaw;
	targetYaw = initialYaw + 90.f;
	currentYaw = initialYaw;
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	currentYaw = FMath::FInterpConstantTo(currentYaw, targetYaw, DeltaTime, 45);
	FRotator doorRotation = GetOwner()->GetActorRotation();
	doorRotation.Yaw = currentYaw;
	GetOwner()->SetActorRotation(doorRotation);
}

