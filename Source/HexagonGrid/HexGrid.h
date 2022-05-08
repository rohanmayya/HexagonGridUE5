// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Hex.h"
#include "GameFramework/Actor.h"
#include "HexGrid.generated.h"

class AHex;

UCLASS()
class HEXAGONGRID_API AHexGrid : public AActor
{
	GENERATED_BODY()

	int32 MapRadius = 2;


public:
	UPROPERTY(EditAnywhere, Category="Hex")
	TSubclassOf<AHex> Hex;
	
	// Sets default values for this actor's properties
	TSet<AHex*> Map;

	AHexGrid();


	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category="Creation")
	void CreateHexagonMap();

	void LogHexData();
};

