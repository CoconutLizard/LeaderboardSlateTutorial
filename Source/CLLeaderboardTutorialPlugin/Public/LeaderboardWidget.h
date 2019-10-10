// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SlateBasics.h"
#include "SCompoundWidget.h"
#include "Engine/DataTable.h"

class SLeaderboardWidget : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SLeaderboardWidget)
	{}
	SLATE_DEFAULT_SLOT(FArguments, Content)
		SLATE_ARGUMENT(UDataTable*, InLeaderboardDataTable)
	SLATE_END_ARGS()

	void CLLEADERBOARDTUTORIALPLUGIN_API Construct(const FArguments& InArgs);

	void AddWidget(TSharedPtr<SVerticalBox> VerticalBox, int32 Number);

	void AddWidget(TSharedPtr<SVerticalBox> VerticalBox, const FString& Name);

	void AddWidget(TSharedPtr<SVerticalBox> VerticalBox, const FName& IconName);

	void InitHeaderWidgets();

	void AddHeaderColumns();

	void AddHeaderColumn(TSharedPtr<SVerticalBox> ColumnHeaderBox, float Size, const FText ColumnName);

	void AddRows(UDataTable* LeaderboardDataTable);

protected:
	// Container for all Vertical Columns
	TSharedPtr<SHorizontalBox> ColumnBox;

	// Vertical Columns
	TSharedPtr<SVerticalBox> Position;
	TSharedPtr<SVerticalBox> Country;
	TSharedPtr<SVerticalBox> PlayerName;
	TSharedPtr<SVerticalBox> TotalScore;
	TSharedPtr<SVerticalBox> Round1;
	TSharedPtr<SVerticalBox> Round2;
	TSharedPtr<SVerticalBox> Round3;
	TSharedPtr<SVerticalBox> Round4;
	TSharedPtr<SVerticalBox> TotalStrokes;

	// Leaderboard Title Text Style
	FTextBlockStyle TitleTextStyle;

	// Row/Column Text Style
	FTextBlockStyle EntryTextStyle;
};
