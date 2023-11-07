// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantFenix.h"

APlantFenix::APlantFenix()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlantMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Pipe.Shape_Pipe'"));
	PlantMeshComponent->SetStaticMesh(PlantMesh.Object);

	//Tags.Add(TEXT("Nuez"));
		// Set this actor to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;

	// Initialize variables
	bIsVisible = true;

}

void APlantFenix::BeginPlay()
{
	Super::BeginPlay();

	// Call ToggleVisibility function after 10 seconds
	//Llamando a la funcion despues de 10 segundos
	GetWorldTimerManager().SetTimer(DisappearTimerHandle, this, &APlantFenix::ToggleVisibility, 10.0f, false);
}

void APlantFenix::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlantFenix::ToggleVisibility()
{
	// Toggle visibility
	bIsVisible = !bIsVisible;
	SetActorHiddenInGame(!bIsVisible);

	// Call ToggleVisibility function again after 5 seconds
	GetWorldTimerManager().SetTimer(ReappearTimerHandle, this, &APlantFenix::ToggleVisibility, 5.0f, false);
}
