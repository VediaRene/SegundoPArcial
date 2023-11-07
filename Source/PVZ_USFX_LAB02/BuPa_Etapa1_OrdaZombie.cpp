// Fill out your copyright notice in the Description page of Project Settings.


#include "BuPa_Etapa1_OrdaZombie.h"
#include "BuPa_SemiOrda.h"
#include "MyPaFM_CreadorZombieMalo.h"

// Sets default values
ABuPa_Etapa1_OrdaZombie::ABuPa_Etapa1_OrdaZombie()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



}

// Called when the game starts or when spawned
void ABuPa_Etapa1_OrdaZombie::BeginPlay()
{
	Super::BeginPlay();
	
	//Spawn  semi orda Zombie Actors
	BuPa_SemiOrda = GetWorld()->SpawnActor<ABuPa_SemiOrda>(ABuPa_SemiOrda::StaticClass());
	//Attach it to the Builder (this)
	BuPa_SemiOrda->AttachToActor(this,FAttachmentTransformRules::KeepRelativeTransform);


}

// Called every frame
void ABuPa_Etapa1_OrdaZombie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuPa_Etapa1_OrdaZombie::BuildOrdaZombie1()
{
	if (!BuPa_SemiOrda) {
		UE_LOG(LogTemp, Error, TEXT("BuildSwimmingPool():Lodging is NULL, make sure it's initialized.")); 
		return;
	}

	APaFM_CreadorZombie* CreadorZombieMalo = GetWorld()->SpawnActor<AMyPaFM_CreadorZombieMalo>(AMyPaFM_CreadorZombieMalo::StaticClass());

	// Create an Outer Health Potion and log its name


	APaFM_Zombie* Zombie;

	Zombie = CreadorZombieMalo->OrderZombie("Normal", FVector(-600.0f, 630.0f, 160.0f));
	Zombie = CreadorZombieMalo->OrderZombie("Normal", FVector(-400.0f, 630.0f, 160.0f));  
	Zombie = CreadorZombieMalo->OrderZombie("Normal", FVector(-200.0f, 630.0f, 160.0f));
	Zombie = CreadorZombieMalo->OrderZombie("Normal", FVector(0.0f, 630.0f, 160.0f));
	Zombie = CreadorZombieMalo->OrderZombie("Normal", FVector(200.0f, 630.0f, 160.0f));

	//Generando orda Sombie1
	BuPa_SemiOrda->SetOrdaZombie1("Orda1");
}

void ABuPa_Etapa1_OrdaZombie::BuildOrdaZombie2()
{
	if (!BuPa_SemiOrda) {
		UE_LOG(LogTemp, Error, TEXT("BuildSwimmingPool():Lodging is NULL, make sure it's initialized."));
		return;
	}

	APaFM_CreadorZombie* CreadorZombieMalo = GetWorld()->SpawnActor<AMyPaFM_CreadorZombieMalo>(AMyPaFM_CreadorZombieMalo::StaticClass());
	
	// Create an Outer Health Potion and log its name
	APaFM_Zombie* Zombie;

	Zombie = CreadorZombieMalo->OrderZombie("Balde", FVector(-600.0f, 1050.0f, 160.0f));
	Zombie = CreadorZombieMalo->OrderZombie("Balde", FVector(-400.0f, 1050.0f, 160.0f));
	Zombie = CreadorZombieMalo->OrderZombie("Balde", FVector(-200.0f, 1050.0f, 160.0f));
	Zombie = CreadorZombieMalo->OrderZombie("Balde", FVector(0.0f, 1050.0f, 160.0f));
	Zombie = CreadorZombieMalo->OrderZombie("Deportista", FVector(200.0f, 1050.0f, 160.0f));
	//Generando orda Sombie2
	BuPa_SemiOrda->SetOrdaZombie2("Orda2");
}

void ABuPa_Etapa1_OrdaZombie::BuildOrdaZombie3()
{
	if (!BuPa_SemiOrda) {
		UE_LOG(LogTemp, Error, TEXT("BuildSwimmingPool():Lodging is NULL, make sure it's initialized."));
		return;
	}
	APaFM_CreadorZombie* CreadorZombieMalo = GetWorld()->SpawnActor<AMyPaFM_CreadorZombieMalo>(AMyPaFM_CreadorZombieMalo::StaticClass());

	// Create an Outer Health Potion and log its name
	APaFM_Zombie* Zombie;

	Zombie = CreadorZombieMalo->OrderZombie("Normal", FVector(-600.0f, 1270.0f, 160.0f));
	Zombie = CreadorZombieMalo->OrderZombie("Pequenio", FVector(-400.0f, 1270.0f, 160.0f));
	Zombie = CreadorZombieMalo->OrderZombie("Pequenio", FVector(-200.0f, 1270.0f, 160.0f));
	Zombie = CreadorZombieMalo->OrderZombie("Pequenio", FVector(0.0f, 1270.0f, 160.0f));
	Zombie = CreadorZombieMalo->OrderZombie("Deportista", FVector(200.0f, 1270.0f, 160.0f));
	//Generando orda Sombie3
	BuPa_SemiOrda->SetOrdaZombie3("Orda3");
}

ABuPa_SemiOrda* ABuPa_Etapa1_OrdaZombie::GetBuPa_SemiOrda()
{
	return BuPa_SemiOrda;
}

