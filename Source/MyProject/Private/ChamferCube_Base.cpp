// Fill out your copyright notice in the Description page of Project Settings.


#include "ChamferCube_Base.h"
#include "Components/StaticMeshComponent.h"

int AChamferCube_Base::Hit()
{
	HitCount++;
	if (HitCount > 1)
	{
		Destroy();
		return 0;
	}
	FVector OldScale = GetMeshComp()->GetComponentScale();
	GetMeshComp()->SetWorldScale3D(OldScale * ScaleMultiplier);
	return BaseScore * ScoreMultiplier;
}

void AChamferCube_Base::SetBonus()
{
	ScoreMultiplier = 2;
	GetMeshComp()->SetMaterial(0, BonusMaterial);
}

UStaticMeshComponent* AChamferCube_Base::GetMeshComp()
{
	if (MeshComp != nullptr)
	{
		return MeshComp;
	}
	MeshComp = FindComponentByClass<UStaticMeshComponent>();
	return MeshComp;
}

// Sets default values
AChamferCube_Base::AChamferCube_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AChamferCube_Base::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("%s"), *GetName());
}

// Called every frame
void AChamferCube_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

