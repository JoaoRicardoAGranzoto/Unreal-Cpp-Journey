// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterTypes.h"
#include "SlashCharacter.generated.h"

class AWeapon;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class UGroomComponent;
class AItems;
struct FInputActionValue;
class UAnimMontage;




UCLASS()
class SLASH_STUDY_API ASlashCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASlashCharacter();
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable)
	void SetWeaponCollision(ECollisionEnabled::Type CollisionEnabled);
	
	FORCEINLINE	void SetOverlappingItem(AItems* Item) {OverlappingItem=Item;}
	FORCEINLINE ECharacterState GetCharacterState() const {return CharacterState;}
	
	UFUNCTION(BlueprintCallable)
	void AttackEnd();
	
	bool CanAttack() const;
	
	bool CanDisarm() const;
	bool CanArm() const;
	
	UFUNCTION(BlueprintCallable)
	void Disarm();
	
	UFUNCTION(BlueprintCallable)
	void Arm();
	
	UFUNCTION(BlueprintCallable)
	void FinishEquippingDesequipping();
	
protected:
	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess="true"))
	ECharacterState CharacterState=ECharacterState::ECS_Unequipped;
	
	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess="true"))
	EActionState ActionState=EActionState::EAS_Unoccupied;
	
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* CameraBoom;
	
	
	
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;
	
	UPROPERTY(VisibleAnywhere, Category="Hair")
	UGroomComponent* Hair;
	
	UPROPERTY(VisibleAnywhere, Category="Hair")
	UGroomComponent* Eyebrows;
	
	UPROPERTY(EditAnywhere, Category=Input)
	UInputMappingContext* SlashContext;
	
	UPROPERTY(EditAnywhere, Category=Input)
	UInputAction* MovementAction;
	
	UPROPERTY(EditAnywhere, Category=Input)
	UInputAction* LookAction;
	
	UPROPERTY(EditAnywhere, Category=Input)
	UInputAction* JumpAction;
	
	UPROPERTY(EditAnywhere, Category=Input)
	UInputAction* SprintAction;
	
	UPROPERTY(EditAnywhere, Category=Input)
	UInputAction* EquipAction;
	
	UPROPERTY(EditAnywhere, Category=Input)
	UInputAction* AttackAction;
	
	UPROPERTY(EditAnywhere, Category=Input)
	UInputAction* CrouchAction;
	
	UPROPERTY(VisibleInstanceOnly)
	AItems* OverlappingItem;
	
	UPROPERTY(VisibleInstanceOnly)
	AWeapon* EquippedWeapon;
	
	/**
	 * Animation Montages
	 */
	
	UPROPERTY(EditDefaultsOnly, Category="Montages")
	UAnimMontage* AttackMontage;
	
	UPROPERTY(EditDefaultsOnly, Category="Montages")
	UAnimMontage* EquipMontage;
	
	/**
	 * Input Functions
	 */
	
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void EKeyPressed();
	void Attack();
	void Sprint();
	void CrouchUnCrouch();

	/**
	 * Play montage functions
	 */
	
	void PlayAttackMontage() const;
	void PlayEquipMontage(FName SectionName) const;
	
	UFUNCTION(BlueprintImplementableEvent)
	void SprintBlueprint();
};