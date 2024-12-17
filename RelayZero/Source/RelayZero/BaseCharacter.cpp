// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// This comes from https://forums.unrealengine.com/t/how-to-set-the-ai-perception-eyes-location/422794/3
void ABaseCharacter::GetActorEyesViewPoint(FVector& Location, FRotator& Rotation) const
{
	Location = GetMesh()->GetSocketLocation("Head");

	const FRotator HeadRotation = GetMesh()->GetSocketRotation("Head");

	FRotator AdjustedRotation = HeadRotation;
	AdjustedRotation.Yaw += 90.0f; // The robot's head has rotation of 90 degrees when facing forward, so account for this

	Rotation = AdjustedRotation;
}
