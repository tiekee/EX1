// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spin.generated.h"

UCLASS()
class EX1_API ASpin : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpin();

	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<class UStaticMeshComponent> StaticMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FRotator RotationSpeed = FRotator(0.0, 90.0, 0.0);
};
