// Copyright (C) Coconut Lizard Limited. All rights reserved.

#include "LeaderboardStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Styling/SlateTypes.h"
#include "Styling/CoreStyle.h"

TSharedPtr<FSlateStyleSet> FLeaderboardStyle::StyleSet = nullptr;
TSharedPtr<ISlateStyle> FLeaderboardStyle::Get() { return StyleSet; }

void FLeaderboardStyle::Initialize()
{
	static FString ContentDir = FPaths::ProjectContentDir();

	// Only register once
	if (StyleSet.IsValid())
	{
		return;
	}

	StyleSet = MakeShared<FSlateStyleSet>("LeaderboardStyle");

	StyleSet->Set("Leaderboard.Icon.AUS", new FSlateImageBrush(ContentDir / "Flags" / "AUS.png", FVector2D(32, 32)));
	StyleSet->Set("Leaderboard.Icon.ESP", new FSlateImageBrush(ContentDir / "Flags" / "ESP.png", FVector2D(32, 32)));
	StyleSet->Set("Leaderboard.Icon.ITA", new FSlateImageBrush(ContentDir / "Flags" / "ITA.png", FVector2D(32, 32)));
	StyleSet->Set("Leaderboard.Icon.USA", new FSlateImageBrush(ContentDir / "Flags" / "USA.png", FVector2D(32, 32)));

	StyleSet->Set("CL.Logo", new FSlateImageBrush(ContentDir / "Logo" / "CoconutLizard_148px_white.png", FVector2D(148, 148)));
	
	FSlateBrush BackgroundBrush;
	BackgroundBrush.TintColor = FLinearColor(0.042f, 0.01f, 0.06f);
	StyleSet->Set("Leaderboard.BackgroundBrush", new FSlateBrush(BackgroundBrush));

	FSlateBrush ForegroundBrush;
	ForegroundBrush.TintColor = FLinearColor(1.0f, 1.0f, 1.0f, 0.4f);
	StyleSet->Set("Leaderboard.ForegroundBrush", new FSlateBrush(ForegroundBrush));

	FSlateStyleRegistry::RegisterSlateStyle(*StyleSet.Get());
};

void FLeaderboardStyle::Shutdown()
{
	if (StyleSet.IsValid())
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(*StyleSet.Get());
		ensure(StyleSet.IsUnique());
		StyleSet.Reset();
	}
}
