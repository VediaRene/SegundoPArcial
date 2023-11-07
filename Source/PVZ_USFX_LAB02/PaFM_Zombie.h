// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Planta.h"
#include "PaFM_Zombie.generated.h"

UCLASS()
class PVZ_USFX_LAB02_API APaFM_Zombie : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APaFM_Zombie();





	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float VelocityBrickBoss;
	FVector DirectionBrickBoss;
	float MovingX;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ZombieMesh;

	void KillZombie();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float MovementSpeed = 6.1f;

	FString GetZombibeName();


protected:

	// Dando nombre al Zombie
	FString ZombieName;
};
