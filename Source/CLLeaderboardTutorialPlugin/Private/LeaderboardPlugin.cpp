// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Modules/ModuleManager.h"
#include "ILeaderboardPlugin.h"
#include "LeaderboardStyle.h"


class FCLLeaderboardTutorialPlugin : public ICLLeaderboardTutorialPlugin
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FCLLeaderboardTutorialPlugin, CLLeaderboardTutorialPlugin )


void FCLLeaderboardTutorialPlugin::StartupModule()
{
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
	FLeaderboardStyle::Initialize();
}


void FCLLeaderboardTutorialPlugin::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FLeaderboardStyle::Shutdown();
}



