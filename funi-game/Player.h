#pragma once

#include "Utilities.h"
#include "ArrowManager.h"



using PlayerData = struct PLAYER_DATA
{
	static unsigned long long count;
	static unsigned long long max_streak;
	static ArrowManager::ArrowType current_skin;
	static std::vector<ArrowManager::ArrowType> allowed_skins;
};

static PlayerData player_data;

namespace SaveManager
{
	void load();
	void save();
};

