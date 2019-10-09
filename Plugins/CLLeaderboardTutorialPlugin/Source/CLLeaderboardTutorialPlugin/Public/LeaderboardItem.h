// Copyright (C) Coconut Lizard Limited. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "LeaderboardItem.generated.h"

USTRUCT()
struct FLeaderboardItem : public FTableRowBase
{
	GENERATED_BODY()

	FLeaderboardItem() = default;

	FLeaderboardItem(int32 InPos, FName InCountry, FString InName, int32 InTotalScore, int32 InRound1, int32 InRound2, int32 InRound3, int32 InRound4)
		: Position(InPos)
		, Country(InCountry)
		, Name(InName)
		, TotalScore(InTotalScore)
		, Round1(InRound1)
		, Round2(InRound2)
		, Round3(InRound3)
		, Round4(InRound4)
	{
		TotalStrokes = InRound1 + InRound2 + InRound3 + InRound4;
	}

	void CalculateTotalStrokes()
	{
		TotalStrokes = Round1 + Round2 + Round3 + Round4;
	}

	UPROPERTY()
		int32 Position;

	UPROPERTY()
		FName Country;

	UPROPERTY()
		FString Name;

	UPROPERTY()
		int32 TotalScore;

	UPROPERTY()
		int32 Round1;

	UPROPERTY()
		int32 Round2;

	UPROPERTY()
		int32 Round3;

	UPROPERTY()
		int32 Round4;

	int32 TotalStrokes;
};