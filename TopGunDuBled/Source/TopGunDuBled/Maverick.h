// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Maverick.generated.h"

UCLASS()
class TOPGUNDUBLED_API AMaverick : public ACharacter
{
	GENERATED_BODY()


public:
	// Sets default values for this character's properties
	AMaverick();

	UPROPERTY(EditAnywhere, Category = "Flight")
	float Acceleration{ 10.f };
	UPROPERTY(EditAnywhere, Category = "Flight")
	float MaxSpeed{ 4000.f };
	UPROPERTY(EditAnywhere, Category = "Flight")
	float MinSpeed{ 500.f };

	UPROPERTY(EditAnywhere, Category = "Flight")
	float RollRateMultiplier{ 200.f };
	UPROPERTY(EditAnywhere, Category = "Flight")
	float PitchRateMultiplier{ 200.f };

	UPROPERTY(VisibleAnywhere, Category = "Flight")
	float CurrentForwardSpeed{ 500.f };

	float CurrentYawSpeed;
	float CurrentPitchSpeed;
	float CurrentRollSpeed;

	bool bIntentionalPitch{ false };
	bool bIntentionalRoll{ false };

protected:

	void ProcessKeyPitch(float Rate);
	void ProcessKeyRoll(float Rate);

	void ProcessMouseYInput(float Value);
	void ProcessMouseXInput(float Value);

	//for calculating rotation
	void ProcessRoll(float Value);
	void ProcessPitch(float Value);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
