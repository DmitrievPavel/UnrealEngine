// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBaseActor.h"

// Sets default values
ACppBaseActor::ACppBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	InitialLocation = GetActorLocation();
}

void ACppBaseActor::SinMovement()
{
	float time = GetGameTimeSinceCreation();
	float newZ = Amplitude * FMath::Sin(Frequency * time) + InitialLocation.Z;
	FVector newLocation(InitialLocation.X, InitialLocation.Y, newZ);
	SetActorLocation(newLocation);
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ACppBaseActor::ShowActorInformation()
{
	FString InstanceName = GetName();
	UE_LOG(LogTemp, Display, TEXT("Instance name: %s"), *InstanceName);
	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), IsAlive);
}

