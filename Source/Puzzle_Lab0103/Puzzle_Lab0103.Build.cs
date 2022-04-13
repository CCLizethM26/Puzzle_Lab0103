// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Puzzle_Lab0103 : ModuleRules
{
	public Puzzle_Lab0103(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
