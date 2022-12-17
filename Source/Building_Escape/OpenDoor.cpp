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
	m_initialYaw = GetOwner()->GetActorRotation().Yaw;
	m_targetYaw += m_initialYaw;
	m_currentYaw = m_initialYaw;

	if(!pressurePlate)
	{
		UE_LOG(LogTemp, Error, TEXT("%s has the openDoor component, but no pressure plate set"), *GetOwner()->GetName());
	}
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if(TotalMassOfActors() > 50.f)
	{
		OpenDoor(DeltaTime);
		DoorLastOpened = GetWorld()->GetTimeSeconds();
	}
	else if(GetWorld()->GetTimeSeconds() - DoorLastOpened > CloseDoorDelay)
		{
			CloseDoor(DeltaTime);
		}
}

void UOpenDoor::OpenDoor(float DeltaTime)
{
	m_currentYaw = FMath::FInterpConstantTo(m_currentYaw, m_targetYaw, DeltaTime, DoorOpenSpeed);
	FRotator doorRotation = GetOwner()->GetActorRotation();
	doorRotation.Yaw = m_currentYaw;
	GetOwner()->SetActorRotation(doorRotation);
}

void UOpenDoor::CloseDoor(float DeltaTime)
{
	m_currentYaw = FMath::FInterpConstantTo(m_currentYaw, m_initialYaw, DeltaTime, DoorCloseSpeed);
	FRotator doorRotation = GetOwner()->GetActorRotation();
	doorRotation.Yaw = m_currentYaw;
	GetOwner()->SetActorRotation(doorRotation);
}

float UOpenDoor::TotalMassOfActors() const
{
	float TotalMass = 0.f;
	//	Find All overlapping actors
	TArray<AActor*> OverlappingActors;
	//	Add up their masses
	return TotalMass;
}