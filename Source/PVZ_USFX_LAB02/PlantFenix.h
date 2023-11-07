// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Planta.h"
#include "PlantFenix.generated.h"

/**
 * 
 */
UCLASS()
class PVZ_USFX_LAB02_API APlantFenix : public APlanta
{
	GENERATED_BODY()
	APlantFenix();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// Timer handles
	//Abministrar controlar los temporizadores
	FTimerHandle DisappearTimerHandle;
	FTimerHandle ReappearTimerHandle;

	// Track if the plant is currently visible
	//Resgristrar si esta visible el objeto
	bool bIsVisible;

	// Function to toggle visibility
	//Cambiar visibilidad
	void ToggleVisibility();
};
