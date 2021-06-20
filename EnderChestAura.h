#pragma once
#include "..\ModuleManager.h"
#include "Module.h"

class EnderChestAura : public IModule {
private:
	int range = 3;

public:
	C_MoveInputHandler* inputHandler = nullptr;
	EnderChestAura();
	~EnderChestAura();

	std::vector<vec3_ti> chestlist;

	// Inherited via IModule
	virtual const char* getModuleName() override;
	virtual void onTick(C_GameMode* gm) override;
	virtual void onDisable() override;
};
