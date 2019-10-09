// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SlateBasics.h"
#include "SCompoundWidget.h"
#include "LeaderboardItem.h"
#include "Engine/DataTable.h"

class SLeaderboardWidget : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SLeaderboardWidget)
	{}
	SLATE_DEFAULT_SLOT(FArguments, Content)
		SLATE_ARGUMENT(TArray<TSharedPtr<FLeaderboardItem>>*, InLeaderboardItems)
		SLATE_ARGUMENT(UDataTable*, InLeaderboardDataTable)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	void AddWidget(TSharedPtr<SVerticalBox> VerticalBox, int32 Number);

	void AddWidget(TSharedPtr<SVerticalBox> VerticalBox, const FString& Name);

	void AddWidget(TSharedPtr<SVerticalBox> VerticalBox, const FName& IconName);

	void AddHeaderColumns();

	void AddHeaderColumn(TSharedPtr<SVerticalBox> ColumnHeaderBox, float Size, const FText ColumnName);

protected:
	

	TSharedPtr<SHorizontalBox> ColumnBox;

	TSharedPtr<SVerticalBox> Position;
	TSharedPtr<SVerticalBox> Country;
	TSharedPtr<SVerticalBox> PlayerName;
	TSharedPtr<SVerticalBox> TotalScore;
	TSharedPtr<SVerticalBox> Round1;
	TSharedPtr<SVerticalBox> Round2;
	TSharedPtr<SVerticalBox> Round3;
	TSharedPtr<SVerticalBox> Round4;
	TSharedPtr<SVerticalBox> TotalStrokes;

	FTextBlockStyle EntryTextStyle;
	FTextBlockStyle TitleTextStyle;
};
