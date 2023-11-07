// Fill out your copyright notice in the Description page of Project Settings.


#include "Planta.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "PVZ_USFX_LAB02Projectile.h"
// Sets default values
APlanta::APlanta()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlantMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Plant Mesh"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlantMesh1(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	if (PlantMesh1.Succeeded())
	{
		PlantMeshComponent->SetStaticMesh(PlantMesh1.Object);
	}
	RootComponent = PlantMeshComponent;
	//PlantMesh->AttachTo(Root);

	//PlantMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlantasMesh"));
	////PlantMeshComponent->SetStaticMesh(PlantMesh.Object);
	////PlantMeshComponent->SetCollisionProfileName(TEXT("Ignore"));
	//PlantMeshComponent->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
	//PlantMeshComponent->SetSimulatePhysics(false);
	//PlantMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	//RootComponent = PlantMeshComponent;

	//PlantasBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("PlantasBoxComponent"));
	///*ZombieBoxComponent->SetBoxExtent(FVector(100.0f, 100.0f, 100.0f));*/
	//PlantasBoxComponent->SetHiddenInGame(false);


	//PlantMeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	//PlantasBoxComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	//ZombieMeshComponent->OnComponentBeginOverlap.AddDynamic(this, &AZombiess::OnOverlapBeginFunction);		// set up a notification for when this component hits something




	bCanFire = true;
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 1.0f;
	TiempoTranscurrido = 0.0f;
	TiempoEntreDisparos = 1.0f;

	disparar = true;
}

void APlanta::eliminarZombie(APVZ_USFX_LAB01GameMode* GameModeBasePVZ)
{
}

void APlanta::DispararPlantas(FVector FireDirection)
{
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		if (FireDirection.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				World->SpawnActor<APVZ_USFX_LAB02Projectile>(SpawnLocation, FireRotation);
			}

			//bCanFire = false;
			//World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &APlantas::ShotTimerExpired, FireRate);

			//// try and play the sound if specified
			//if (FireSound != nullptr)
			//{
			//	UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
			//}

			//bCanFire = false;
			// 
			//-------------------------------------------------------------------

			bCanFire = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &APlanta::ShotTimerExpired, FireRate);
			//----------------------------------------------------------------------
		}
	}
}

// Called when the game starts or when spawned
void APlanta::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlanta::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (disparar)
	{
		TiempoTranscurrido += DeltaTime;
		if (TiempoTranscurrido >= TiempoEntreDisparos)
		{
			DispararPlantas(FVector(0.f, 1.f, 0.f));
			TiempoTranscurrido = 0.0f;
		}
	}


}



void APlanta::ShotTimerExpired()
{
	bCanFire = true;
}

//float APlanta::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
//{
//	// Aquí puedes manejar el daño como desees, por ejemplo, actualizando la salud del actor.
//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Health Zombie: %f"), this->Health));
//
//	Health -= Damage;
//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Health Zombie: %f"), this->Health));
//
//	// Devuelve la cantidad de daño que se aplicó realmente.
//	return Health;
//}



