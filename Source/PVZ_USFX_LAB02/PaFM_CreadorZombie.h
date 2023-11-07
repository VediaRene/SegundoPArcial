// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaFM_Zombie.h"
#include "PaFM_CreadorZombie.generated.h"
UCLASS()
class PVZ_USFX_LAB02_API APaFM_CreadorZombie : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APaFM_CreadorZombie();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Crea una posion y la devuelve y es vitual pura
		virtual APaFM_Zombie* ConcoctZombie(FString ZombieSKU, FVector Location) PURE_VIRTUAL(APaFM_CreadorZombie::ConcoctZombie, return nullptr;);

	//Order, concoct and returns a Potion of a specific Category
	APaFM_Zombie* OrderZombie(FString Category, FVector Location);
};
