// Fill out your copyright notice in the Description page of Project Settings.


#include "PaFM_ZombieNormal.h"

APaFM_ZombieNormal::APaFM_ZombieNormal()
{
	ZombieName = "Normal";

	ZombieNormalMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Balde Mesh"));
	RootComponent = ZombieNormalMesh;
	// Load the static mesh asset
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ZombieMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (ZombieMeshAsset.Succeeded())
	{
		ZombieNormalMesh->SetStaticMesh(ZombieMeshAsset.Object);
	}

	MovementSpeed = 0.2f;
}

void APaFM_ZombieNormal::BeginPlay()
{
	Super::BeginPlay();

}

