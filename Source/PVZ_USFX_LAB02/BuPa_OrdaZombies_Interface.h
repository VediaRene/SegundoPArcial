// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BuPa_OrdaZombies_Interface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UBuPa_OrdaZombies_Interface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PVZ_USFX_LAB02_API IBuPa_OrdaZombies_Interface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
public:
	//The pure virtual functions of the FloorPlan
	virtual void BuildOrdaZombie1() = 0;
	virtual void BuildOrdaZombie2() = 0;
	virtual void BuildOrdaZombie3() = 0;

	virtual class ABuPa_SemiOrda* GetBuPa_SemiOrda() = 0;
};
