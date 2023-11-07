// Fill out your copyright notice in the Description page of Project Settings.


#include "PaFM_ZombieDepostista.h"

void APaFM_ZombieDepostista::BeginPlay()
{
	Super::BeginPlay();
}

APaFM_ZombieDepostista::APaFM_ZombieDepostista()
{
	ZombieName = "Deportista";

	ZombieDeportistaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Balde Mesh"));
	RootComponent = ZombieDeportistaMesh;
	// Load the static mesh asset
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ZombieMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Wedge_A.Shape_Wedge_A'"));
	if (ZombieMeshAsset.Succeeded())
	{
		ZombieDeportistaMesh->SetStaticMesh(ZombieMeshAsset.Object);
	}

	MovementSpeed = 3.0f;
}
