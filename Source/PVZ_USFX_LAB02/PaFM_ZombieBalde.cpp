// Fill out your copyright notice in the Description page of Project Settings.


#include "PaFM_ZombieBalde.h"

APaFM_ZombieBalde::APaFM_ZombieBalde()
{
	ZombieName = "Balde";


	BaldeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Balde Mesh"));
	RootComponent = BaldeMesh;
	// Load the static mesh asset
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ZombieMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (ZombieMeshAsset.Succeeded())
	{
		BaldeMesh->SetStaticMesh(ZombieMeshAsset.Object);
	}

	MovementSpeed = 0.02f;
}
