// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuPa_OrdaZombies_Interface.h"
#include "BuPa_ConstructorEtapas.generated.h"

UCLASS()
class PVZ_USFX_LAB02_API ABuPa_ConstructorEtapas : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuPa_ConstructorEtapas();
private:
	//The Builder Actor, that must be a LodgingBuilder
	IBuPa_OrdaZombies_Interface* BuPa_OrdaZombies_Interface;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	//Creates the buildings
	void ConstructorOrdas();
	//Set the Builder Actor
	void SetOrdeZombie(AActor* Builder);
	//Get the Lodging of the Builder
	class ABuPa_SemiOrda* GetBuPa_SemiOrda();
};
