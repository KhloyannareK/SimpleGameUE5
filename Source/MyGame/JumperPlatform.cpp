// Fill out your copyright notice in the Description page of Project Settings.


#include "JumperPlatform.h"

// Sets default values
AJumperPlatform::AJumperPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AJumperPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJumperPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	const auto& pawnLoc = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	FVector origin, extent;
	GetActorBounds(false, origin, extent, true);
	if (pawnLoc.X > origin.X - extent.X &&
		pawnLoc.X < origin.X + extent.X &&
		pawnLoc.Y > origin.Y - extent.Y &&
		pawnLoc.Y < origin.Y + extent.Y) {
		FVector currentLoc = GetActorLocation();
		currentLoc.Z  += (DeltaTime * m_velocity);

		SetActorLocation(currentLoc);
		float dist = FVector::Dist(currentLoc, m_startLocation);
		if (dist > 4000 || dist < 0) {
			currentLoc.Z -= (DeltaTime * m_velocity);
			SetActorLocation(currentLoc);
			m_velocity *= -1;
		}
	}
	else {
		SetActorLocation(m_startLocation);
		if (m_velocity < 0)
			m_velocity *= -1;
	}

}

