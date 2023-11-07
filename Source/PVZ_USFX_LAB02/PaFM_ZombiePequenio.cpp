// Fill out your copyright notice in the Description page of Project Settings.


#include "PaFM_ZombiePequenio.h"

APaFM_ZombiePequenio::APaFM_ZombiePequenio()
{
	ZombieName = "Pequenio";

	//ZombieName = "Normal";

	ZombiePequenioMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Balde Mesh"));
	RootComponent = ZombiePequenioMesh;
	// Load the static mesh asset
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ZombieMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));
	if (ZombieMeshAsset.Succeeded())
	{
		ZombiePequenioMesh->SetStaticMesh(ZombieMeshAsset.Object);
	}

	MovementSpeed = 0.1f;
}

void APaFM_ZombiePequenio::BeginPlay()
{
	Super::BeginPlay();

	
}
