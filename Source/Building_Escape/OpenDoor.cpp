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
	FRotator currentRotation = GetOwner()->GetActorRotation();
	targetYaw = currentRotation.Yaw + 90.0f;
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	FRotator OpenDoor(0.f, 0.f, 0.f);
	float currentYaw = GetOwner()->GetActorRotation().Yaw;
	OpenDoor.Yaw = FMath::Lerp(currentYaw, targetYaw, 0.01f);
	GetOwner()->SetActorRotation(OpenDoor);
}

