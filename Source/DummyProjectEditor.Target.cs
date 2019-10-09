// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class DummyProjectEditorTarget : TargetRules
{
	public DummyProjectEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("DummyProject");
		ExtraModuleNames.Add("CLLeaderboardTutorialPlugin");
	}
}
