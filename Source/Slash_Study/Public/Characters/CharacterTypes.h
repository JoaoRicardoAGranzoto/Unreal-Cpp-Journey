// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ECharacterState : uint8
{
	ECS_Unequipped UMETA(DisplayName="Unequipped"),
	ECS_EquippedOneHandedWeapon UMETA(DisplayName="Equipped One Handed Weapon"),
	ECS_EquippedTwoHandedWeapon UMETA(DisplayName="Equipped Two Handed Weapon")
};
UENUM(BlueprintType)
enum class EActionState : uint8 
{
	EAS_Unoccupied UMETA(DisplayName="Unoccupied"),
	EAS_Attacking UMETA(DisplayName="Attacking"),




	EAS_EquippingWeapon UMETA(DisplayName="EquippingWeapon"),
	EAS_DesequippingWeapon UMETA(DisplayName="DesequippingWeapon")
};

UENUM(BlueprintType)
enum class EMovementState : uint8
{
	EMS_Walking UMETA(DisplayName="Walking"),
	EMS_Running UMETA(DisplayName="Running")
};