// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

namespace UnrealBuildTool.Rules
{
	public class CLLeaderboardTutorialPlugin : ModuleRules
	{
		public CLLeaderboardTutorialPlugin(ReadOnlyTargetRules Target) : base(Target)
		{
			PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

			PrivateDependencyModuleNames.AddRange(
				new string[] {
					"Core",
					"CoreUObject",
					"Engine",
					"InputCore"
				});

			PublicDependencyModuleNames.AddRange(
				new string[] {
					"Slate",
					"SlateCore"
				});

			PrivateIncludePaths.AddRange(
				new string[] {
					 "CLLeaderboardTutorialPlugin/Private"
				});

			PublicIncludePaths.AddRange(
				new string[]
				{
				});
		}
	}
}
