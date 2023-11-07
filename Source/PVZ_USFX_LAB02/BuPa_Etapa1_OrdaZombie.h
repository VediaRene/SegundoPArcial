// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuPa_OrdaZombies_Interface.h"
#include "BuPa_Etapa1_OrdaZombie.generated.h"

UCLASS()
class PVZ_USFX_LAB02_API ABuPa_Etapa1_OrdaZombie : public AActor, public IBuPa_OrdaZombies_Interface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuPa_Etapa1_OrdaZombie();
private:
	//The Lodging Actor
	UPROPERTY(VisibleAnywhere, Category = "Orda Zombie")
	class ABuPa_SemiOrda* BuPa_SemiOrda;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Creando Orda Zombi1
	virtual void BuildOrdaZombie1() override;
	//Creando orda Zombie2
	virtual void BuildOrdaZombie2() override;
	//Creando Orda Zombie3
	virtual void BuildOrdaZombie3() override;
	// devolviendo Semi Orda Zombie
	virtual class ABuPa_SemiOrda* GetBuPa_SemiOrda() override;
};
