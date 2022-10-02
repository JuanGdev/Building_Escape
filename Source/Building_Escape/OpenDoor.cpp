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
	FRotator CurrentRotation = GetOwner()->GetActorRotation();
	targetYaw = CurrentRotation.Yaw + 180.0f;
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// FRotator CurrentRotation = GetOwner()->GetActorRotation();
	// GetOwner()->SetActorRotation(CurrentRotation.Add(0.01f, 90.0f, 0.01f));
	// CurrentRotation.Yaw += 90.0f;
	// GetOwner()->SetActorRotation(CurrentRotation);

	// Printing all the angles and the yaw individual
	// UE_LOG(LogTemp, Warning, TEXT("%s"), *GetOwner()->GetActorRotation().ToString());
	// UE_LOG(LogTemp, Warning, TEXT("Yaw is: %f"), GetOwner()->GetActorRotation().Yaw);
	FRotator CurrentRotation = GetOwner()->GetActorRotation();
	
	for(int32 start = 0; start < targetYaw; start+=1)
	{
		CurrentRotation.Yaw = FMath::Lerp(CurrentRotation.Yaw, float(start), 0.0001f);
		GetOwner()->SetActorRotation(CurrentRotation);
	}
	
	
	
	
}

