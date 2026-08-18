// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spin2.generated.h"

UCLASS()
class EX1_API ASpin2 : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpin2();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<class UStaticMeshComponent> StaticMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector MoveDirection = FVector::UpVector;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (ClampMin = "0.0", UIMin = "0.0"))
	float MoveSpeed = 100.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (ClampMin = "0.0", UIMin = "0.0"))
	float MaxRange = 300.0f;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Movement")
	FVector StartLocation = FVector::ZeroVector;

private:
	float DistanceAlongPath = 0.0f;
	float MovementSign = 1.0f;
};
