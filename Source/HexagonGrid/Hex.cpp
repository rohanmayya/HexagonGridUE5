// Fill out your copyright notice in the Description page of Project Settings.


#include "Hex.h"


// Sets default values
AHex::AHex()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHex::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHex::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHex::InitializeHex(int32 q, int32 r, int32 s)
{
	Q = q;
	R = r;
	S = s;
}

FString AHex::PrintHexCoordinates() const
{
	return FString::Printf(TEXT("(%d, %d, %d)"), Q, R, S);
}


