// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	auto Name = GetName();
	if (*Name == NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("throttle: %f"), Throttle);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"), *Name, Throttle);
	}

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent()); //Voy al Tank_BP y luego obtengo el Tank
	TankRoot->AddForceAtLocation(ForceApplied,ForceLocation);
}