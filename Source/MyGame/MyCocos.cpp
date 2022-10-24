// Fill out your copyright notice in the Description page of Project Settings.
//
#include "MyCocos.h"
#include "GameManager.h"

// Sets default values
AMyCocos::AMyCocos()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//UE_LOG(LogTemp, Warning, TEXT("%d-th cocos"), i++);
	auto* gameManagerPtr = GameManager::getObject();
	gameManagerPtr->incrCocosCount();

}

// Called when the game starts or when spawned
void AMyCocos::BeginPlay()
{
	Super::BeginPlay(); // mariam super hero
	
}

// Called every frame
void AMyCocos::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!outOfWorld && 
		!GameManager::getObject()->noCocos() && 
		int(GetActorLocation().Z) <= -100) 
	{
		outOfWorld = true;
		GameManager::getObject()->decrCocosCount();
	}
	if (GameManager::getObject()->noCocos()) {
	  GameManager::getObject()->switchTheLift();
	}
}

