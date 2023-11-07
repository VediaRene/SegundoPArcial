// Copyright Epic Games, Inc. All Rights Reserved.

#include "PVZ_USFX_LAB02GameMode.h"
#include "PVZ_USFX_LAB02Pawn.h"
#include "Zombie.h"
#include "Planta.h"

#include "PaFM_Planta.h" 
#include "MyPaFM_CreadorZombieMalo.h"

#include "Girasol.h"
#include "Sol.h"


#include "PlantFenix.h"

#include "BuPa_ConstructorEtapas.h"
#include "BuPa_Etapa1_OrdaZombie.h"
#include "BuPa_SemiOrda.h"

APVZ_USFX_LAB02GameMode::APVZ_USFX_LAB02GameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	// set default pawn class to our character class
	DefaultPawnClass = APVZ_USFX_LAB02Pawn::StaticClass();
	TiempoTranscurrido = 0.0f;
}

void APVZ_USFX_LAB02GameMode::BeginPlay()
{
	Super::BeginPlay();


	////////////////////////////////////// PATRON BUILDER //////////////////////////////////////

	// Spawn Builder and Engineer
	EtapaBuilder = GetWorld()->SpawnActor<ABuPa_Etapa1_OrdaZombie>(ABuPa_Etapa1_OrdaZombie::StaticClass());

	Engineer = GetWorld()->SpawnActor<ABuPa_ConstructorEtapas>(ABuPa_ConstructorEtapas::StaticClass());

	//Set the Builder for the Engineer and create the buildings

	Engineer->SetOrdeZombie(EtapaBuilder);
	Engineer->ConstructorOrdas();

	//Get the Engineer's Lodging and Logs the created buildings
	
	ABuPa_SemiOrda* BuPa_SemiOrda = Engineer->GetBuPa_SemiOrda();
	BuPa_SemiOrda->SemiOrdaCaracteristicas();


	////////////////////////////////////// FIN PATRON  BUILDER //////////////////////////////////////

	
	/////////////////////////// PATRON FACTORY METHOD ////////////////////// 

	APaFM_CreadorZombie* CreadorZombieMalo = GetWorld()->SpawnActor<AMyPaFM_CreadorZombieMalo>(AMyPaFM_CreadorZombieMalo::StaticClass());

	// creando las posiciones y  registrando nombres
	APaFM_Zombie* Zombie;
	Zombie = CreadorZombieMalo->OrderZombie("Normal", FVector(-600.0f, 830.0f, 160.0f));
	Zombie = CreadorZombieMalo->OrderZombie("Cono", FVector(-400.0f, 830.0f, 160.0f));
	Zombie = CreadorZombieMalo->OrderZombie("Balde", FVector(-200.0f, 830.0f, 160.0f));
	Zombie = CreadorZombieMalo->OrderZombie("Pequenio", FVector(0.0f, 830.0f, 160.0f));
	Zombie = CreadorZombieMalo->OrderZombie("Deportista", FVector(200.0f, 830.0f, 160.0f));
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("Funciono")));

	/////////////////////////// PATRON FACTORY METHOD //////////////////////
	
	///Implenementacion al video juego del patron facthory method y builder
	
	// Lugar donde quieras crear la instancia del objeto de planta
	//FVector SpawnLocation1 = FVector(-850.0f, 400.0f, 160.0f); // Cambia las coordenadas según tus necesidades

	//AZombie* NewZombieActor1 = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), SpawnLocation1, FRotator::ZeroRotator);

	//FVector SpawnLocation2 = FVector(-500.0f, 200.0f, 160.0f); // Cambia las coordenadas según tus necesidades

	//AZombie* NewZombieActor2 = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), SpawnLocation2, FRotator::ZeroRotator);


	//// Lugar donde quieras crear la instancia del objeto
	//FVector MinSpawnLocation = FVector(-1000.0f, -1000.0f, 0.0f);
	//FVector MaxSpawnLocation = FVector(1000.0f, 1000.0f, 0.0f);

	//float RandomX = FMath::RandRange(MinSpawnLocation.X, MaxSpawnLocation.X);
	//float RandomY = FMath::RandRange(MinSpawnLocation.Y, MaxSpawnLocation.Y);
	//float Z = 180.0f; // Altura en Z

	//FVector SpawnLocation = FVector(RandomX, RandomY, Z);

	//AZombie* NewZombieActor3 = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), SpawnLocation, FRotator::ZeroRotator);


	//----------------------aki se generan los zombies-----------------------------------------------------------------------
	
	//FVector SpawnLocationZombie = FVector(-800.0f, 400.0f, 160.0f);

	//// Crear objetos y agregarlos al vector
	//// Se crean los Zombies dinamicamente
	//for (int i = 0; i < 5; i++) {

	//	SpawnLocationZombie.X += 200;

	//	AZombie* NuevoZombie = GetWorld()->SpawnActor<AZombie>(AZombie::StaticClass(), SpawnLocationZombie, FRotator::ZeroRotator);

	//	NuevoZombie->MovementSpeed = FMath::FRandRange(0.1, 0.5);

	//	vectorZombies.Add(NuevoZombie);
	//}

	//---------------------------------------------->Fenix<---------------------------------------------------------
	////FTransform SpawnLocation;
	////SpawnLocation.SetLocation(FVector(0, 0, 0));
	//float initialPositionX = -1500.0f;
	//float initialPositionY = 1200.0f;

	//initialPositionX = -900.0f;
	//initialPositionY = -400.0f;
	//for (int i = 0; i < 1; i++)
	//{
	//	APlantFenix* NewFenix = SpawnPlantFenix(FVector(initialPositionX + i * 150.0f, initialPositionY, 200.0f));

	//	if (NewFenix)
	//	{
	//		NewFenix->SetActorEnableCollision(true);     // Habilita las colisiones si es necesario
	//		FPlantas.Add(NewFenix);

	//		//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Energia de %s es: %i"), *NewGirasol->GetName(), NewGirasol->energia));
	//	}



	//	for (int j = 0; j < 1; j++) {
	//		APlanta*NewPlantFenix = SpawnPlant(FVector(initialPositionX + i * 150.0f, initialPositionY + j * 350.0f, 200.0f));
	//		FPlantas.Add(NewPlantFenix);
	//		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Energia de %s es: %i"), *NewLanzaguisantes->GetName(), NewLanzaguisantes->energia));


	//	}
	//}



	////---------------------------------------------->Girasol<---------------------------------------------------------
	//initialPositionX = -1000.0f;
	//initialPositionY = 100.0f;
	//for (int i = 0; i < 2; i++)
	//{
	//	AGirasol* NewGirasol = SpawnPlantGirasol(FVector(initialPositionX + i * 150.0f, initialPositionY, 200.0f));

	//	if (NewGirasol)
	//	{
	//		NewGirasol->SetActorEnableCollision(true);     // Habilita las colisiones si es necesario
	//		aPlantas.Add(NewGirasol);

	//		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Energia de %s es: %i"), *NewGirasol->GetName(), NewGirasol->energia));
	//	}



	//	for (int j = 0; j < 2; j++) {
	//		APlanta* NewGirasoles = SpawnPlant(FVector(initialPositionX + i * 150.0f, initialPositionY + j * 350.0f, 200.0f));
	//		aPlantas.Add(NewGirasoles);
	//		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Energia de %s es: %i"), *NewLanzaguisantes->GetName(), NewLanzaguisantes->energia));


	//	}
	//}


	////Se crean las plantas dinamicamente
	//FVector SpawnLocationPlant = FVector(-800.0f, -600.0f, 160.0f);
	//FVector SpawnLocationPlantTemp = SpawnLocationPlant;

	////Genera 5 plantas
	//for (int i = 0; i < 5; i++) {

	//	//Define una pocision temporal para las plantas en el eje X
	//	SpawnLocationPlantTemp.X += 200;
	//	for (int j = 0; j < 3; j++) {

	//		//Define una pocision temporal para las plantas en el eje Y
	//		SpawnLocationPlantTemp.Y += 120;

	//		//Genera u nombre para la planta
	//		FString NombrePlanta = FString::Printf(TEXT("Planta%d"), i + 1);

	//		//Crea una nueva instancia de Aplat en el mundo
	//		APaFM_Planta* NuevoPlant = GetWorld()->SpawnActor<APaFM_Planta>(APaFM_Planta::StaticClass(), SpawnLocationPlantTemp, FRotator::ZeroRotator);

	//		//Asina un valor aleatorio a la energia de la planta
	//		//->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf( TEXT("Energia de % s: % i"),*NombrePlanta,NuevoPlant->energia));

	//		//Agrega la planta al contenedor de plantas
	//		//MapPlanta.Add(NombrePlanta, NuevoPlant);

	//		//Coloca las plantas en una pocision diferente 
	//		//NuevoPlant->SetActorLocation(FVector(i*100,0,0));

	//	}
	//	SpawnLocationPlantTemp.Y = SpawnLocationPlant.Y;
	//}

	//World->GetTimerManager().SetTimer(Temporizador, this, &APVZ_USFX_LAB01GameMode::aumentarVelocidad, 1, true);
////////////////////////////////////////////////////////////////////////////////////////////////

//Se crean las plantas dinamicamente
	FVector SpawnLocationPlant = FVector(-800.0f, -600.0f, 160.0f);
	FVector SpawnLocationPlantTemp = SpawnLocationPlant;

	//Genera 5 plantas
	for (int i = 0; i < 5; i++) {

		//Define una pocision temporal para las plantas en el eje X
		SpawnLocationPlantTemp.X += 200;
		for (int j = 0; j < 3; j++) {

			//Define una pocision temporal para las plantas en el eje Y
			SpawnLocationPlantTemp.Y += 120;

			//Genera u nombre para la planta
			FString NombrePlanta = FString::Printf(TEXT("Planta%d"), i + 1);

			//Crea una nueva instancia de Aplat en el mundo
			APlanta* NuevoPlant = GetWorld()->SpawnActor<APlanta>(APlanta::StaticClass(), SpawnLocationPlantTemp, FRotator::ZeroRotator);

			//Asina un valor aleatorio a la energia de la planta
			//->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, FString::Printf( TEXT("Energia de % s: % i"),*NombrePlanta,NuevoPlant->energia));

			//Agrega la planta al contenedor de plantas
			//MapPlanta.Add(NombrePlanta, NuevoPlant);

			//Coloca las plantas en una pocision diferente 
			//NuevoPlant->SetActorLocation(FVector(i*100,0,0));

		}
		SpawnLocationPlantTemp.Y = SpawnLocationPlant.Y;
	}

//	//World->GetTimerManager().SetTimer(Temporizador, this, &APVZ_USFX_LAB01GameMode::aumentarVelocidad, 1, true);
}

APlantFenix* APVZ_USFX_LAB02GameMode::SpawnPlantFenix(FVector _spawnPosition)
{
	FTransform SpawnLocation;
	SpawnLocation.SetLocation(_spawnPosition);
	return GetWorld()->SpawnActor<APlantFenix>(APlantFenix::StaticClass(), SpawnLocation);
}

AGirasol* APVZ_USFX_LAB02GameMode::SpawnPlantGirasol(FVector _spawnPosition)
{
	FTransform SpawnLocation;
	SpawnLocation.SetLocation(_spawnPosition);
	return GetWorld()->SpawnActor<AGirasol>(AGirasol::StaticClass(), SpawnLocation);
}

ASol* APVZ_USFX_LAB02GameMode::SpawnPlantSol(FVector _spawnPosition)
{
	FTransform SpawnLocation;
	SpawnLocation.SetLocation(_spawnPosition);
	return GetWorld()->SpawnActor<ASol>(ASol::StaticClass(), SpawnLocation);
}

void APVZ_USFX_LAB02GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TiempoTranscurrido += DeltaTime;

	if (TiempoTranscurrido > 2.0f) {
		// Iterar sobre el vector de objetos
		for (int i = 0; i < vectorZombies.Num(); i++) {
			vectorZombies[i]->MovementSpeed = FMath::FRand() * 0.1f;
			//vectorZombies[i]->MovementSpeed += i * 1.0f;
		}
		TiempoTranscurrido = 0.0f;
	}

}

APlanta* APVZ_USFX_LAB02GameMode::SpawnPlant(FVector _spawnPosition)
{
	FTransform SpawnLocation;
	SpawnLocation.SetLocation(_spawnPosition);
	return GetWorld()->SpawnActor<APlanta>(APlanta::StaticClass(), SpawnLocation);
}

void APVZ_USFX_LAB02GameMode::aumentarVelocidad()
{
	for (int i = 0; i < vectorZombies.Num(); i++) {
		vectorZombies[i]->MovementSpeed = +FMath::FRandRange(0, 0.2);
	}

}

