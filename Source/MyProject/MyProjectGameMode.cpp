// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyProjectGameMode.h"
#include "MyProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "ChamferCube_Base.h"
#include "Kismet/GameplayStatics.h"

AMyProjectGameMode::AMyProjectGameMode()
	: Super()
{
	UWorld* World = GetWorld();
	SetBonusCube(World);

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	FTimerHandle TimerHandle;
	if (World)
	{
		World->GetTimerManager().SetTimer(TimerHandle, this, &AMyProjectGameMode::EndGame, RoundTime, false);
	}
}

void AMyProjectGameMode::SetBonusCube(UWorld* World)
{
	if (World != nullptr)
	{
		TArray<AActor*> Cubes;
		UGameplayStatics::GetAllActorsOfClass(World, AChamferCube_Base::StaticClass(), Cubes);
		if (Cubes.Num() < NumberBonusCubes)
		{
			for (auto& it : Cubes)
			{
				Cast<AChamferCube_Base>(it)->SetBonus();
			}
		}
		else
		{
			int32 d = Cubes.Num() / NumberBonusCubes;
			int32 c = Cubes.Num() % NumberBonusCubes;
			int32 r = Cubes.Num() / d;
			int32 nowl;
			for (nowl = 0; nowl + c + d < Cubes.Num(); nowl += d)
			{
				int32 index = FMath::RandRange(nowl, nowl + d - 1);
				Cast<AChamferCube_Base>(Cubes[index])->SetBonus();
			}
			int32 index = FMath::RandRange(nowl, Cubes.Num() - 1);
			Cast<AChamferCube_Base>(Cubes[index])->SetBonus();
		}
	}
}

void AMyProjectGameMode::EndGame()
{
	UE_LOG(LogTemp, Warning, TEXT("GameEnded!"));
	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		TArray<AActor*> Players;
		UGameplayStatics::GetAllActorsOfClass(World, AMyProjectCharacter::StaticClass(), Players);
		int Num = 0;
		for (auto& it : Players) {
			auto Player = Cast<AMyProjectCharacter>(it);
			FString Msg = FString::Printf(TEXT("%s Gets %d Points!"), *it->GetName(), Player->GetScore());
			GEngine->AddOnScreenDebugMessage(++Num , 20.f, FColor::Blue, Msg);
			it->Destroy();
		}
	}
}
