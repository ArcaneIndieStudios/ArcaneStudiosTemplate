// © 2024, Arcane Studios. All rights reserved.

using UnrealBuildTool;

public class InventoryEditor : ModuleRules
{
	public InventoryEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] 
			{ 
				"Core",
				"CoreUObject",
				"Engine",
                "Slate",
                "SlateCore",
                "InventorySystem",
                "UnrealEd",
                "AssetTools",
                "ClassViewer",
                "PropertyEditor",
                
            });
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
                
            });
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				
			});
	}
}
