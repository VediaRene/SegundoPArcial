// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaFM_Zombie.h"
#include "PaFM_ZombieCono.generated.h"

/**
 * 
 */
UCLASS()
class PVZ_USFX_LAB02_API APaFM_ZombieCono : public APaFM_Zombie
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:

	APaFM_ZombieCono();
	
protected:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ConoMesh;

};
