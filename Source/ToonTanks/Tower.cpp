// Copyright Cindy C.

#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Tank)
	{
		float distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
		if (distance <= FireRange)
		{
			RotateTurret(Tank->GetActorLocation());
		}
	}
}

void ATower::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}
