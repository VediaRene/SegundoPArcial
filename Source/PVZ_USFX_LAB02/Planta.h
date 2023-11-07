// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Planta.generated.h"

UCLASS()
class PVZ_USFX_LAB02_API APlanta : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlanta();
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* PlantMeshComponent;
	void eliminarZombie(class APVZ_USFX_LAB01GameMode* GameModeBasePVZ);
	/*UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* PlantMeshComponent;*/
protected:
	UPROPERTY(EditAnywhere)
	class UBoxComponent* PlantasBoxComponent;


	void DispararPlantas(FVector FireDirection);

	/* Flag to control firing  */
	uint32 bCanFire : 1;
	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;

	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	FVector GunOffset;

	/* How fast the weapon will fire */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float FireRate;

	//Devuelve el nombre del Plantas
	bool disparar;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//void FireShot(FVector FireDirection);
	//void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);
	UPROPERTY(VisibleAnywhere)
	int energia;


	void ShotTimerExpired();

	float TiempoTranscurrido;
	float TiempoEntreDisparos;
	


};
