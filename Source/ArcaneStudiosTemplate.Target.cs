// © 2024, Arcane Studios. All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ArcaneStudiosTemplateTarget : TargetRules
{
	public ArcaneStudiosTemplateTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "ArcaneStudiosTemplate" } );
	}
}
