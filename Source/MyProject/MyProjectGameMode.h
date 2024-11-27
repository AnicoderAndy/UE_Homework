// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyProjectGameMode.generated.h"

UCLASS(minimalapi)
class AMyProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default Value", meta = (AllowPrivateAccess = "true"))
	int NumberBonusCubes = 4;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default Value", meta = (AllowPrivateAccess = "true"))
	float RoundTime = 10.0f;

public:
	AMyProjectGameMode();

	UFUNCTION()
	void EndGame();

private:
	void SetBonusCube(UWorld* World);
};



