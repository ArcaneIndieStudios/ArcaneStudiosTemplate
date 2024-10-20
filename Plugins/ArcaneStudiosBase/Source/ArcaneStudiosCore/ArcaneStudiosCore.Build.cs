// © 2024, Arcane Studios. All rights reserved.

using UnrealBuildTool;

public class ArcaneStudiosCore: ModuleRules
{
    public ArcaneStudiosCore(ReadOnlyTargetRules Target) : base(Target)
    {
        PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "ModularGameplay",
            "GameplayAbilities",
            "GameplayTasks",
            "EnhancedInput",
            "GameplayTags",
            "UMG",
            "CommonUI",
            "CommonInput",
        });

        PrivateDependencyModuleNames.AddRange(new string[] 
        {
            "CoreUObject",
            "Engine",
            "Slate",
            "SlateCore",
        });
    }
}
