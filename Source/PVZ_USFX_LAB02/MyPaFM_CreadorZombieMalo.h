// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaFM_CreadorZombie.h"
#include "MyPaFM_CreadorZombieMalo.generated.h"

/**
 * 
 */
UCLASS()
class PVZ_USFX_LAB02_API AMyPaFM_CreadorZombieMalo : public APaFM_CreadorZombie
{
	GENERATED_BODY()
	
public:
	//Preparando la posion seleccionada 
	virtual APaFM_Zombie* ConcoctZombie(FString ZombieSKU, FVector Location) override;


};
