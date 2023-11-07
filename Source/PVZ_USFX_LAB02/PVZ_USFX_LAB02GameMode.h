// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PVZ_USFX_LAB02GameMode.generated.h"

class AZombie;
class APlanta;
UCLASS(MinimalAPI)
class APVZ_USFX_LAB02GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APVZ_USFX_LAB02GameMode();
	//Declarar un vector de objetos
	TArray<class AZombie*> vectorZombies;
	//TArray<class APlant*> vectorPlants;
	TArray<class ASol*> ArraySol;
	int32 NumberPLantGirasol = 2;
	//Declarar un mapa de objetos
	TMap<FString, APlanta*> MapPlanta;
	TArray<APlanta*> aPlantas;
	TArray<APlanta*> FPlantas;

private:
	//The Builder Actor
	UPROPERTY(VisibleAnywhere, Category = "Main")
	class ABuPa_Etapa1_OrdaZombie* EtapaBuilder;
	//The Engineer Actor
	UPROPERTY(VisibleAnywhere, Category = "Main")
	class ABuPa_ConstructorEtapas* Engineer;


protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	class APlantFenix* SpawnPlantFenix(FVector _spawnPosition);
	//Called every frame


	class AGirasol* SpawnPlantGirasol(FVector _spawnPosition);

	class ASol* SpawnPlantSol(FVector _spawnPosition);
	float TiempoTranscurrido = 0.0f;
	float TiempoTranscurridoSiguientePala = 0.0f;
	float TiempoTranscurridoSiguienteAbono = 0.0f;
	float TiempoTrancurridoSiguienteTarjetaGirasol = 0.0f;


	virtual void Tick(float DeltaTime) override;

	class APlanta* SpawnPlant(FVector _spawnPosition);
	FTimerHandle Temporizador;

	//float TiempoTranscurrido;

	void aumentarVelocidad();
};

