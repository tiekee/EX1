// Fill out your copyright notice in the Description page of Project Settings.


#include "Spin2.h"
#include "Components/StaticMeshComponent.h"

ASpin2::ASpin2()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	SetRootComponent(StaticMesh);
}

void ASpin2::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	DistanceAlongPath = 0.0f;
	MovementSign = 1.0f;
}

void ASpin2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FVector Direction = MoveDirection.GetSafeNormal();
	const float Range = FMath::Max(0.0f, MaxRange);
	if (Direction.IsNearlyZero() || Range <= 0.0f || MoveSpeed <= 0.0f)
	{
		return;
	}

	DistanceAlongPath += MovementSign * MoveSpeed * DeltaTime;

	
	while (DistanceAlongPath > Range || DistanceAlongPath < 0.0f)
	{
		if (DistanceAlongPath > Range)
		{
			DistanceAlongPath = (2.0f * Range) - DistanceAlongPath;
			MovementSign = -1.0f;
		}
		else
		{
			DistanceAlongPath = -DistanceAlongPath;
			MovementSign = 1.0f;
		}
	}

	SetActorLocation(StartLocation + Direction * DistanceAlongPath);
}

