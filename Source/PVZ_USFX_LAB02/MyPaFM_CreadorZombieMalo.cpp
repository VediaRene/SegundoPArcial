// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPaFM_CreadorZombieMalo.h"
#include "PaFM_ZombieBalde.h"
#include "PaFM_ZombieCono.h"
#include "PaFM_ZombieNormal.h"
#include "PaFM_ZombieDepostista.h"
#include "PaFM_ZombiePequenio.h"

APaFM_Zombie* AMyPaFM_CreadorZombieMalo::ConcoctZombie(FString ZombieSKU,FVector Location)
{


	//Select which potion to spawn depending on the passed string
	if (ZombieSKU.Equals("Balde")) {
		return GetWorld()->SpawnActor<APaFM_ZombieBalde>(APaFM_ZombieBalde::StaticClass(), Location, FRotator::ZeroRotator);
	}
	else if (ZombieSKU.Equals("Cono")) {
		return GetWorld()->SpawnActor<APaFM_ZombieCono>(APaFM_ZombieCono::StaticClass(), Location, FRotator::ZeroRotator);
	}
	else if (ZombieSKU.Equals("Normal")) {
		return GetWorld()->SpawnActor<APaFM_ZombieNormal>(APaFM_ZombieNormal::StaticClass(), Location, FRotator::ZeroRotator);
	}
	else if (ZombieSKU.Equals("Pequenio")) {
		return GetWorld()->SpawnActor<APaFM_ZombiePequenio>(APaFM_ZombiePequenio::StaticClass(), Location, FRotator::ZeroRotator);
	}	
	else if (ZombieSKU.Equals("Deportista")) {
		return GetWorld()->SpawnActor<APaFM_ZombieDepostista>(APaFM_ZombieDepostista::StaticClass(), Location, FRotator::ZeroRotator);
	}
	else return nullptr; //Return null if the string isn't valid
	
}
