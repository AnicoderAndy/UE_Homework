// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChamferCube_Base.generated.h"

UCLASS()
class MYPROJECT_API AChamferCube_Base : public AActor
{
	GENERATED_BODY()

	int HitCount = 0;
	int ScoreMultiplier = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	int BaseScore = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	float ScaleMultiplier = 0.5f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	UMaterialInstance* BonusMaterial;

	UStaticMeshComponent* MeshComp = nullptr;

public:
	int Hit();
	void SetBonus();
	UStaticMeshComponent* GetMeshComp();

public:	
	// Sets default values for this actor's properties
	AChamferCube_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
