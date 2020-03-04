// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "Components/CapsuleComponent.h"
#include "MainCharacter.generated.h"

UCLASS()
class TAKBO_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintImplementableEvent)
	void TurnRightSnap();

	UPROPERTY(EditDefaultsOnly, Category = "Character Maximum Speed")
	float CharacterMaxMovementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LocalVariables")
	int Slot1Item;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LocalVariables")
	int Slot2Item;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LocalVariables")
	int Slot3Item;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LocalVariables")
	int Slot4Item;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LocalVariables")
	int Slot5Item;

	/** This will allow us to pick a mesh that the character will have*/
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComponent; // This can be changed to a skeletal mesh later

	/** Camera boom positioning the camera behind the player */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleDefaultsOnly)
	UCameraComponent* FollowCamera;

	/** These are just getters for the SpringArm and Camera*/
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void RotateRight(float Value);

	FVector CurrentVelocity;

};
