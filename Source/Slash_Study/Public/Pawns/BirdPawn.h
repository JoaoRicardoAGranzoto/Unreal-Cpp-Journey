// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BirdPawn.generated.h"

UCLASS()
class SLASH_STUDY_API ABirdPawn : public APawn
{
	GENERATED_BODY()

public:
	ABirdPawn();
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	



protected:
	virtual void BeginPlay() override;
};