// Fill out your copyright notice in the Description page of Project Settings.


#include "PaFM_ZombieCono.h"

void APaFM_ZombieCono::BeginPlay()
{
	Super::BeginPlay();
}



APaFM_ZombieCono::APaFM_ZombieCono()
{
	ZombieName = "Cono";
	
	ConoMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Balde Mesh"));
	RootComponent = ConoMesh;
	// Load the static mesh asset
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ZombieMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	if (ZombieMeshAsset.Succeeded())
	{
		ConoMesh->SetStaticMesh(ZombieMeshAsset.Object);
	}
	MovementSpeed = 1.0f;
}
