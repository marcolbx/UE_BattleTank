// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h" //TankAimingComponent hereda de ActorComponent
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};

//permite referenciar esta clase
class UTankBarrel; //Forward Declaration permite decirle a este componente que esta clase existe
class UTankTurret; //Forward Declaration permite decirle a este componente que esta clase existe


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);


	//void SetBarrelReference(UTankBarrel* BarrelToSet);
	//void SetTurretReference(UTankTurret* TurretToSet);


protected:
	// Called when the game starts
	void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void AimAt(FVector WorldSpaceAim, float LaunchSpeed);
	void MoveBarrelTowards(FVector AimDirection);


protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")
		EFiringState FiringState = EFiringState::Locked;

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

};
