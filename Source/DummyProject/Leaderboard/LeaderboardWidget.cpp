// Copyright (C) Coconut Lizard Limited. All rights reserved.

#include "LeaderboardWidget.h"
#include "LeaderboardStyle.h"

#define LOCTEXT_NAMESPACE "SLeaderboardWidget"

void SLeaderboardWidget::Construct(const FArguments& InArgs)
{
	EntryTextStyle.SetFont(TEXT("Fonts/gorditas_regular.ttf"), 20);
	EntryTextStyle.SetColorAndOpacity(FLinearColor::White);
	
	TitleTextStyle.SetFont(TEXT("Fonts/njnaruto.ttf"), 60);
	TitleTextStyle.SetColorAndOpacity(FLinearColor::White);

	TSharedPtr<SVerticalBox> RowBox;

	const FText LeaderboardText = LOCTEXT("LeaderboardText", "Leaderboard");

	ChildSlot
		[
			SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.FillHeight(0.15f)
				[
					SNullWidget::NullWidget
				]
				+ SVerticalBox::Slot()
				.FillHeight(0.7f)
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.FillWidth(0.15f)
					[
						SNullWidget::NullWidget
					]
					+ SHorizontalBox::Slot()
					.FillWidth(0.70f)
					[
						SNew(SBorder)
						.Padding(FMargin(25.0f, 20.0f))
						.BorderImage(FLeaderboardStyle::Get()->GetBrush("Leaderboard.BackgroundBrush"))
						[
							SNew(SVerticalBox)
							+ SVerticalBox::Slot()
							.Padding(FMargin(0.0f, 10.0f))
							.AutoHeight()
							[
								SNew(SHorizontalBox)
								+ SHorizontalBox::Slot()
								.FillWidth(0.20f)
								.HAlign(HAlign_Left)
								.VAlign(VAlign_Center)
								[
									SNew(SImage)
									.Image(FLeaderboardStyle::Get()->GetBrush("CL.Logo"))
									.ColorAndOpacity(FLinearColor::White)
								]
								+ SHorizontalBox::Slot()
								.FillWidth(0.60f)
								.HAlign(HAlign_Center)
								.VAlign(VAlign_Center)
								[
									SNew(STextBlock)
									.TextStyle(&TitleTextStyle)
									.ShadowColorAndOpacity(FLinearColor::Black)
									.ColorAndOpacity(FLinearColor::White)
									.ShadowOffset(FIntPoint(-1, 1))
									.Text(LeaderboardText)
								]
								+ SHorizontalBox::Slot()
								.FillWidth(0.20f)
								[
									SNullWidget::NullWidget
								]
							]
							+ SVerticalBox::Slot()
							.FillHeight(1.0f)
							[
								SNew(SBorder)
								.Padding(FMargin(10.0f, 5.0f))
								.BorderImage(FLeaderboardStyle::Get()->GetBrush("Leaderboard.ForegroundBrush"))
								[
									SAssignNew(RowBox, SVerticalBox) // need this?
									+ SVerticalBox::Slot()
									.FillHeight(1.0f)
									[
										SAssignNew(ColumnBox, SHorizontalBox)
									]
								]
							]
						]
					]
					+ SHorizontalBox::Slot()
					.FillWidth(0.15f)
					[
						SNullWidget::NullWidget
					]
				]
				+ SVerticalBox::Slot()
				.FillHeight(0.15f)
				[
					SNullWidget::NullWidget
				]

		];

	Position = SNew(SVerticalBox);
	Country = SNew(SVerticalBox);
	PlayerName = SNew(SVerticalBox);
	TotalScore = SNew(SVerticalBox);
	Round1 = SNew(SVerticalBox);
	Round2 = SNew(SVerticalBox);
	Round3 = SNew(SVerticalBox);
	Round4 = SNew(SVerticalBox);
	TotalStrokes = SNew(SVerticalBox);

	AddHeaderColumns();

	const bool bIsImage = true;

	const FString ContextString = FString(TEXT("Leaderboard Data Table Context"));

	if (InArgs._InLeaderboardDataTable)
	{
		for (const FName& ColumName : InArgs._InLeaderboardDataTable->GetRowNames())
		{
			FLeaderboardItem* Item = InArgs._InLeaderboardDataTable->FindRow<FLeaderboardItem>(ColumName, ContextString);
			if (Item)
			{
				Item->CalculateTotalStrokes();
				AddWidget(Position, Item->Position);
				AddWidget(Country, Item->Country);
				AddWidget(PlayerName, Item->Name);
				AddWidget(TotalScore, Item->TotalScore);
				AddWidget(Round1, Item->Round1);
				AddWidget(Round2, Item->Round2);
				AddWidget(Round3, Item->Round3);
				AddWidget(Round4, Item->Round4);
				AddWidget(TotalStrokes, Item->TotalStrokes);
			}
		}
	}
}

void SLeaderboardWidget::AddWidget(TSharedPtr<SVerticalBox> VerticalBox, int32 Number)
{
	VerticalBox->AddSlot()
		.FillHeight(0.1f)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			.Padding(FMargin(0.0f, 5.0f))
			[
				SNew(SBorder)
				.BorderImage(FLeaderboardStyle::Get()->GetBrush("Leaderboard.BackgroundBrush"))
			]
			+ SOverlay::Slot()
			.VAlign(VAlign_Center)
			.HAlign(HAlign_Center)
			[
				SNew(STextBlock)
				.TextStyle(&EntryTextStyle)
				.ShadowOffset(FIntPoint(-1, 1))
				.Text(FText::AsNumber(Number))
			]
		];
}

void SLeaderboardWidget::AddWidget(TSharedPtr<SVerticalBox> VerticalBox, const FString& Name)
{
	VerticalBox->AddSlot()
		.FillHeight(0.1f)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			.Padding(FMargin(0.0f, 5.0f))
			[
				SNew(SBorder)
				.BorderImage(FLeaderboardStyle::Get()->GetBrush("Leaderboard.BackgroundBrush"))
			]
			+ SOverlay::Slot()
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.TextStyle(&EntryTextStyle)
				.ShadowOffset(FIntPoint(-1, 1))
				.Text(FText::FromString(Name))
			]
		];
}

void SLeaderboardWidget::AddWidget(TSharedPtr<SVerticalBox> VerticalBox, const FName& IconName)
{
	VerticalBox->AddSlot()
		.FillHeight(0.1f)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			.Padding(FMargin(0.0f, 5.0f))
			[
				SNew(SBorder)
				.BorderImage(FLeaderboardStyle::Get()->GetBrush("Leaderboard.BackgroundBrush"))
			]
			+ SOverlay::Slot()
			.VAlign(VAlign_Center)
			.HAlign(HAlign_Center)
			[
				SNew(SImage)
				.Image(FLeaderboardStyle::Get()->GetBrush(IconName))
			]
		];
}

void SLeaderboardWidget::AddHeaderColumns()
{
	AddHeaderColumn(Position, 0.05f, LOCTEXT("Position", "#"));
	AddHeaderColumn(Country, 0.05f, LOCTEXT("Country", ""));
	AddHeaderColumn(PlayerName, 0.43f, LOCTEXT("PlayerName", "Name"));
	AddHeaderColumn(TotalScore, 0.12f, LOCTEXT("TotalScore", "Total Score"));
	AddHeaderColumn(Round1, 0.05f, LOCTEXT("Round1", "R1"));
	AddHeaderColumn(Round2, 0.05f, LOCTEXT("Round2", "R2"));
	AddHeaderColumn(Round3, 0.05f, LOCTEXT("Round3", "R3"));
	AddHeaderColumn(Round4, 0.05f, LOCTEXT("Round4", "R4"));
	AddHeaderColumn(TotalStrokes, 0.15f, LOCTEXT("TotalStrokes", "Total Strokes"));
}

void SLeaderboardWidget::AddHeaderColumn(TSharedPtr<SVerticalBox> ColumnHeaderBox, float Size, const FText ColumnName)
{
	ColumnBox->AddSlot()
		.FillWidth(Size)
		[
			SAssignNew(ColumnHeaderBox, SVerticalBox)
			+ SVerticalBox::Slot()
			.FillHeight(0.1f)
			.VAlign(VAlign_Center)
			.HAlign(HAlign_Center)
			[
				SNew(STextBlock)
				.TextStyle(&EntryTextStyle)
				.Text(ColumnName)
			]
		];
}

#undef LOCTEXT_NAMESPACE //SLeaderboardWidget