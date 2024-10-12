// © 2024, Arcane Studios. All rights reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ArcaneStudiosTemplateEditorTarget : TargetRules
{
	public ArcaneStudiosTemplateEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "ArcaneStudiosTemplate" } );
		ExtraModuleNames.AddRange( new string[] { "ArcaneStudiosCore" } );
    }
}
