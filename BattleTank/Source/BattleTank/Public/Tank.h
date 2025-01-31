// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h" //esta aqui porque ATank hereda de APawn
#include "Tank.generated.h"

//Forward declarations

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	//UFUNCTION(BlueprintCallable, Category = Setup)
	//void SetBarrelReference(UTankBarrel* BarrelToSet);

	//UFUNCTION(BlueprintCallable, Category = Setup)
	//void SetTurretReference(UTankTurret* TurretToSet);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	ATank();

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	

};
