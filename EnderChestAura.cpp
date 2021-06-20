#include "EnderChestAura.h"

EnderChestAura::EnderChestAura() : IModule(0, Category::PLAYER, "Aura for opening ender chests") {
	registerIntSetting("Range", &this->range, this->range, 1, 10);
}

EnderChestAura::~EnderChestAura() {
}

const char* EnderChestAura::getModuleName() {
	return ("EnderChestAura");
}

void EnderChestAura::onTick(C_GameMode* gm) {
	if (g_Data.getLocalPlayer()->getSupplies()->inventory->isFull())
		return;

	vec3_t* pos = gm->player->getPos();
	for (int x = (int)pos->x - range; x < pos->x + range; x++) {
		for (int z = (int)pos->z - range; z < pos->z + range; z++) {
			for (int y = (int)pos->y - range; y < pos->y + range; y++) {
				vec3_ti pos = vec3_ti(x, y, z);
				C_Block* block = gm->player->region->getBlock(pos);
				if (block != nullptr && g_Data.canUseMoveKeys()) {
					if (block->toLegacy()->blockId == 130) {
						if (!(std::find(chestlist.begin(), chestlist.end(), pos) != chestlist.end())) {
							gm->buildBlock(&pos, 0);
							chestlist.push_back(pos);
							return;
						}
					}
				}
			}
		}
	}
}

void EnderChestAura::onDisable() {
	this->chestlist.clear();  // this code should be changed later, the chestlist has to be cleared when loading into a new world
}
