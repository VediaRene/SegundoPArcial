// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuPa_SemiOrda_Interface.h"
#include "BuPa_SemiOrda.generated.h"

UCLASS()
class PVZ_USFX_LAB02_API ABuPa_SemiOrda : public AActor, public IBuPa_SemiOrda_Interface
{
	GENERATED_BODY()
	

public:	
	// Sets default values for this actor's properties
	ABuPa_SemiOrda();

private:
	//The Swimming Pool's name
	FString OrdaZombie1;
	//The Lobby Area's name
	FString OrdaZombie2;
	//The Rooms's name
	FString OrdaZombie3;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	//Estableciendo nombre a la orda Zombie1
	void SetOrdaZombie1(FString myOrdaZombie1);
	//Estableciendo nombre a la orda Zombie2
	void SetOrdaZombie2(FString myOrdaZombie2);
	//Estableciendo nombre a la orda Zombie3
	void SetOrdaZombie3(FString myOrdaZombie3);
	//
	void SemiOrdaCaracteristicas();
};
