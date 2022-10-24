// Fill out your copyright notice in the Description page of Project Settings.


#include "Lift.h"
#include "GameManager.h"

// Sets default values
ALift::ALift()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GameManager::getObject()->setLiftPtr(this);
}

// Called when the game starts or when spawned
void ALift::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALift::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (m_goUp) {
		FVector currentLoc = GetActorLocation();
		if (currentLoc.Z < 4000) {
			currentLoc.Z += (DeltaTime * 50);
			SetActorLocation(currentLoc);
		}
		else {
			currentLoc.Z = 0;
			SetActorLocation(currentLoc);
		}
	}
}

