// Fill out your copyright notice in the Description page of Project Settings.


#include "BuPa_ConstructorEtapas.h"
#include "BuPa_SemiOrda.h"

// Sets default values
ABuPa_ConstructorEtapas::ABuPa_ConstructorEtapas()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABuPa_ConstructorEtapas::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABuPa_ConstructorEtapas::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuPa_ConstructorEtapas::ConstructorOrdas()
{
	//Log if the Builder is NULL
	if (!BuPa_OrdaZombies_Interface) {
		UE_LOG(LogTemp, Error,TEXT("ConstructLodging(): LodgingBuilder is NULL, make sure it's initialized."));
		return;
	}
	//reates the buildings
	BuPa_OrdaZombies_Interface->BuildOrdaZombie1();
	BuPa_OrdaZombies_Interface->BuildOrdaZombie2();
	BuPa_OrdaZombies_Interface->BuildOrdaZombie3();
	

}

void ABuPa_ConstructorEtapas::SetOrdeZombie(AActor* Builder)
{
	//Cast the passed Actor and set the Builder
	BuPa_OrdaZombies_Interface = Cast<IBuPa_OrdaZombies_Interface>(Builder);
	if (!BuPa_OrdaZombies_Interface) //Log Error if cast fails
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red,TEXT("Invalid Cast! See Output log for more details"));
		UE_LOG(LogTemp, Error, TEXT("SetLodgingBuilder(): The Actor inot a LodgingBuilder!Are you sure that the Actor implements thatinterface ? "));
	}
}

ABuPa_SemiOrda* ABuPa_ConstructorEtapas::GetBuPa_SemiOrda()
{

	if (BuPa_OrdaZombies_Interface)
	{
		//Returns the Lodging of the Builder
		return BuPa_OrdaZombies_Interface->GetBuPa_SemiOrda();
	}
	//Log if the Builder is NULL
	UE_LOG(LogTemp, Error, TEXT("GetLodging(): Return nullptr"));
	return nullptr;

}

