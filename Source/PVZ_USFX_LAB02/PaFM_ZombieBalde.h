// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaFM_Zombie.h"
#include "PaFM_ZombieBalde.generated.h"

/**
 * 
 */
UCLASS()
class PVZ_USFX_LAB02_API APaFM_ZombieBalde : public APaFM_Zombie
{
	GENERATED_BODY()
	
public:
	APaFM_ZombieBalde();

protected:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* BaldeMesh;

};
