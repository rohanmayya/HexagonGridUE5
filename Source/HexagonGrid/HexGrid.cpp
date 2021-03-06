// Fill out your copyright notice in the Description page of Project Settings.


#include "HexGrid.h"


// Sets default values
AHexGrid::AHexGrid()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHexGrid::BeginPlay()
{
	Super::BeginPlay();

	CreateHexagonMap();

	LogHexData();
}

// Called every frame
void AHexGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHexGrid::CreateHexagonMap()
{
	for (int q = -MapRadius; q <= MapRadius; q++)
	{
		const int32 R1 = std::max(-MapRadius, -q - MapRadius);
		const int32 R2 = std::min(MapRadius, -q + MapRadius);
		
		for (int r = R1; r <= R2; r++)
		{
			const float LocationX = -q*XOffset + static_cast<float>(r * 85);
			const float LocationY = static_cast<float>(q*100) + YOffset*q;
			
			FVector Location = FVector(LocationX, LocationY, 10.f);
			FRotator Rotation = FRotator(0.f, 0.f, 0.f);
			FTransform Transform = FTransform(Rotation, Location);
			
			AHex* hex = GetWorld()->SpawnActorDeferred<AHex>(Hex, Transform);
			hex->InitializeHex(q, r, -q-r);
			Map.Add(hex);

			hex->FinishSpawning(Transform);
		}
	}
}

void AHexGrid::LogHexData()
{
	for (const AHex* HexItem : Map)
	{
		UE_LOG(LogTemp, Display, TEXT("Actor name & Cube co-ordinates: %s %s"), *HexItem->GetName(), *HexItem->PrintHexCoordinates());
	}
}


