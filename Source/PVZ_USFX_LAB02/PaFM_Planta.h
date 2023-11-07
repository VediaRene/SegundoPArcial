// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaFM_Planta.generated.h"

UCLASS()
class PVZ_USFX_LAB02_API APaFM_Planta : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APaFM_Planta();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	////Mango para una gestión eficiente del temporizador ShotTimerExpire
	//FTimerHandle TimerHandle_ShotTimerExpired;

	////Desplazarse desde la ubicación del barco para generar proyectiles.
	//UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	//FVector GunOffset;

	///* Qué tan rápido disparará el arma */
	//UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	//float FireRate;

	bool ProjectileShoot;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* PlantaMesh;

	void Disparar();

	/** Handle for efficient management of ShotTimerExpired timer */
	FTimerHandle TimerHandle_ShotTimerExpired;

	/** Offset from the ships location to spawn projectiles */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	FVector GunOffset;

	/* How fast the weapon will fire */
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	float FireRate;

	float TiempoTranscurrido;
	float TiempoEntreDisparos;
	//float TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser);
	float Health = 20.0f;
	float MovementSpeed = 6.1f;
	void Defender() PURE_VIRTUAL(APlant::Defender, );

};
