// Copyright Juan Aguilera (@juan.gdev)

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "OpenDoor.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
private:
	UPROPERTY(EditAnywhere)	float m_targetYaw = 90.f;
	float m_currentYaw, m_initialYaw;
	UPROPERTY(EditAnywhere) ATriggerVolume* pressurePlate;
	UPROPERTY(EditAnywhere) AActor* ActorThatOpens;
};
