// © 2024, Arcane Studios. All rights reserved.

using UnrealBuildTool;

public class ArcaneStudiosCore: ModuleRules
{
    public ArcaneStudiosCore(ReadOnlyTargetRules Target) : base(Target)
    {
        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "GameplayAbilities",
            "GameplayTasks",
            "EnhancedInput",
            "GameplayTags"
        });

        PrivateDependencyModuleNames.AddRange(new string[] 
        {
            "CoreUObject",
            "Engine"
        });
    }
}
