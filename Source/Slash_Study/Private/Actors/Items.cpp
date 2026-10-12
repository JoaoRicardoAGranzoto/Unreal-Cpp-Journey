// Fill out your copyright notice in the Description page of Project Settings.

#include "Actors/Items.h"
#include "Characters/SlashCharacter.h"
#include "Components/SphereComponent.h"

AItems::AItems()
{
	PrimaryActorTick.bCanEverTick = true;
	
	ItemMesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	RootComponent = ItemMesh;
	
	Sphere=CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());
}

void AItems::BeginPlay()




{
	Super::BeginPlay();
	
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AItems::OnSphereOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AItems::OnSphereEndOverlap);
}

void AItems::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ASlashCharacter* SlashCharacter=Cast<ASlashCharacter>(OtherActor);
	if (SlashCharacter)
	{
		SlashCharacter->SetOverlappingItem(this);
	}
}

void AItems::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ASlashCharacter* SlashCharacter=Cast<ASlashCharacter>(OtherActor);
	if (SlashCharacter)
	{
		SlashCharacter->SetOverlappingItem(nullptr);
	}
}

void AItems::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}