// Fill out your copyright notice in the Description page of Project Settings.


#include "PaFM_Planta.h"
//#include "Proyectil.h"
#include "PVZ_USFX_LAB02Projectile.h"

// Sets default values
APaFM_Planta::APaFM_Planta()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlantaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Planta Mesh"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlantMesh1(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	if (PlantMesh1.Succeeded())
	{
		PlantaMesh->SetStaticMesh(PlantMesh1.Object);
	}
	RootComponent = PlantaMesh;

	// Inicializando valores de Disparar

	GunOffset = FVector(10.0f, 0.0f, 0.0f);
	FireRate = 0.25f;
	ProjectileShoot = true;

	GunOffset = FVector(20.f, 0.f, 0.f);
	//FireRate  = 0.5f;
}


// Called when the game starts or when spawned
void APaFM_Planta::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APaFM_Planta::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

}

void APaFM_Planta::Disparar()
{
	FVector FireDirection(0.f, 0.f, 400.f);
	const FVector Spawn = GetActorLocation() + FVector(-30.0f, 0.0f, 0.0f);
	const FVector Spawn2 = GetActorLocation() + FVector(30.0f, 0.0f, 0.0f);
	const FRotator FireRotation = FireDirection.Rotation();

	// Spawn projectile at an offset from this pawn
	const FVector SpawnLocation = Spawn + FireRotation.RotateVector(GunOffset);

	// Spawn projectile at an offset from this pawn
	const FVector SpawnLocation2 = Spawn2 + FireRotation.RotateVector(GunOffset);

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		// spawn the projectile
		World->SpawnActor<APVZ_USFX_LAB02Projectile>(SpawnLocation, FireRotation);
		World->SpawnActor<APVZ_USFX_LAB02Projectile>(SpawnLocation2, FireRotation);
	}

}

