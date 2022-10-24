// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Lift.generated.h"

UCLASS()
class MYGAME_API ALift : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALift();
	void setGoingUp() {	m_goUp = true; }
	void unsetGoingUp() { m_goUp = false; }


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	bool m_goUp{ false };
};
