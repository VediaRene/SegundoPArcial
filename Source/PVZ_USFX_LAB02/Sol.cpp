// Fill out your copyright notice in the Description page of Project Settings.


#include "Sol.h"
#include "RandomMovement.h"

// Sets default values
ASol::ASol()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshSol = CreateDefaultSubobject<UStaticMeshComponent>(TEXT(" Mesh Sol"));
	RootComponent = MeshSol;
	// Load the static mesh asset
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SolMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));
	MeshSol->SetStaticMesh(SolMeshAsset.Object);
}

// Called when the game starts or when spawned
void ASol::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASol::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASol::ManejoClick()
{
	// Check we are not already active
	if (!bIsActive)
	{
		bIsActive = true;
		Destroy();
		// Change material
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Aumento la cantidad de soles")));

	}
}

void ASol::Resaltado(bool bOn)
{
	// Do not highlight if the block has already been activated.
	if (bIsActive)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("1Grilla a usar: %s"), *GetName()));
		return;
	}

	if (bOn)
	{
		//BlockMesh->SetMaterial(0, BaseMaterial);
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Un sol, nosé %s"), *GetName()));

	}
	else
	{
		//BlockMesh->SetMaterial(0, BlueMaterial);
		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Nose xd")));

	}
}

