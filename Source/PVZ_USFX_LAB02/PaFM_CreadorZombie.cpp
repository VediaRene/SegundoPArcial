// Fill out your copyright notice in the Description page of Project Settings.


#include "PaFM_CreadorZombie.h"

// Sets default values
APaFM_CreadorZombie::APaFM_CreadorZombie()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APaFM_CreadorZombie::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APaFM_CreadorZombie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

APaFM_Zombie* APaFM_CreadorZombie::OrderZombie(FString Category,FVector Location)
{

	APaFM_Zombie* Zombie = ConcoctZombie(Category, Location);
	
	return Zombie;

}
