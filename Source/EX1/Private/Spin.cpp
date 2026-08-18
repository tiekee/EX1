// Fill out your copyright notice in the Description page of Project Settings.


#include "Spin.h"
#include "Components/StaticMeshComponent.h"

ASpin::ASpin()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	SetRootComponent(StaticMesh);
}

void ASpin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(RotationSpeed * DeltaTime);
}

