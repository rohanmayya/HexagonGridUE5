// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Hex.generated.h"

UCLASS()
class HEXAGONGRID_API AHex : public AActor
{
	GENERATED_BODY()


public:
	UPROPERTY(BlueprintReadWrite)
	int32 Q;
	UPROPERTY(BlueprintReadWrite)
	int32 R;
	UPROPERTY(BlueprintReadWrite)
	int32 S;
	
public:
	// Sets default values for this actor's properties
	AHex();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void InitializeHex(int32 q, int32 r, int32 s);

	virtual FString PrintHexCoordinates() const;
};
