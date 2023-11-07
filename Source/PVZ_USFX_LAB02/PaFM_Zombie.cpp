// Fill out your copyright notice in the Description page of Project Settings.


#include "PaFM_Zombie.h"
#include "MyPaFM_CreadorZombieMalo.h"

// Sets default values
APaFM_Zombie::APaFM_Zombie()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ZombieMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Zombie Mesh"));
	RootComponent = ZombieMesh;
	// Load the static mesh asset
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ZombieMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));
	if (ZombieMeshAsset.Succeeded())
	{
		ZombieMesh->SetStaticMesh(ZombieMeshAsset.Object);
	}
	


	VelocityBrickBoss = 2.0f;
	MovingX = -10;

	MovementSpeed = 0.1f;

}



// Called when the game starts or when spawned
void APaFM_Zombie::BeginPlay()
{
	Super::BeginPlay();



	
}

void APaFM_Zombie::KillZombie()
{
	this->Destroy();
}

// Called every frame
void APaFM_Zombie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FVector MoveDirection = FVector(0.0f, MovingX, 0.0f);//dandole una direccion de movimiento , Calcular movimiento
	const FVector Movement = MoveDirection * VelocityBrickBoss * DeltaTime;// la velocidad en la que se va mover



	//Si no es de tama?o cero, mueve a este actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = FRotator(0.0f, 0.0f, 0.0f);// la rotacion de la capsula

		FHitResult Hit(1.0f);
		RootComponent->MoveComponent(Movement, NewRotation, false, &Hit);

	}

}

FString APaFM_Zombie::GetZombibeName()
{
	return ZombieName;
}






