// Fill out your copyright notice in the Description page of Project Settings.


#include "BuPa_SemiOrda.h"

// Sets default values
ABuPa_SemiOrda::ABuPa_SemiOrda()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABuPa_SemiOrda::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABuPa_SemiOrda::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABuPa_SemiOrda::SetOrdaZombie1(FString myOrdaZombie1)
{
	OrdaZombie1= myOrdaZombie1;
}

void ABuPa_SemiOrda::SetOrdaZombie2(FString myOrdaZombie2)
{
	OrdaZombie2 = myOrdaZombie2;
}

void ABuPa_SemiOrda::SetOrdaZombie3(FString myOrdaZombie3)
{
	OrdaZombie3 = myOrdaZombie3;
}

void ABuPa_SemiOrda::SemiOrdaCaracteristicas()
{
	//Registrando cada nombre de las Orda de Zombie
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("%s"),*OrdaZombie1));
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("%s"),*OrdaZombie2));
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("%s"),*OrdaZombie3));

}

