// Copyright (C) Coconut Lizard Limited. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/ISlateStyle.h"
#include "Styling/SlateStyle.h"

class FLeaderboardStyle
{
public:
	static void Initialize();
	static void Shutdown();
	static TSharedPtr<ISlateStyle> Get();

private:
	static TSharedPtr<FSlateStyleSet> StyleSet;
};
