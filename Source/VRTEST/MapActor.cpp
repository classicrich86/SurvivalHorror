// Fill out your copyright notice in the Description page of Project Settings.

#include "VRTEST.h"
#include "MapActor.h"
#include "EngineUtils.h"
#include <string>

// Sets default values
AMapActor::AMapActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMapActor::BeginPlay() {
	Super::BeginPlay();
	// Iterate over all Actors in the world.
	for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
		AActor *Mesh = *ActorItr;
	// If Actor is a “PathNode”, display location on screen.
	if (ActorItr->GetName().Contains("PathNode"))
		if (GEngine){
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow,
				TEXT("" + ActorItr->GetName() + " location " + ActorItr->GetActorLocation().ToString()));
	}
}
// Called every frame
void AMapActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

