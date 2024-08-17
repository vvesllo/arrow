#include "Player.h"

unsigned long long PlayerData::count = 0;
unsigned long long PlayerData::max_streak = 0;
ArrowManager::ArrowType PlayerData::current_skin = ArrowManager::ArrowType::ARROW_FINGER;
std::vector<ArrowManager::ArrowType> PlayerData::allowed_skins = { 
	ArrowManager::ArrowType::ARROW_FINGER,
	ArrowManager::ArrowType::ARROW_BOTINOK,
	ArrowManager::ArrowType::ARROW_UMBRELLA,
	ArrowManager::ArrowType::ARROW_PIXELTRONIC,
};


void SaveManager::load()
{
	std::fstream file;
	size_t allowed_size;

	file.open(PATH_SAVE, std::ios::in | std::ios::binary);

	file.read(reinterpret_cast<char*>(&player_data.count), sizeof(player_data.count));
	file.read(reinterpret_cast<char*>(&player_data.max_streak), sizeof(player_data.max_streak));
	file.read(reinterpret_cast<char*>(&player_data.current_skin), sizeof(player_data.current_skin));
	file.read(reinterpret_cast<char*>(&allowed_size), sizeof(allowed_size));

	player_data.allowed_skins.clear();
	for (int i = 0; i < allowed_size; ++i)
	{
		ArrowManager::ArrowType skin;
		file.read(reinterpret_cast<char*>(&skin), sizeof(skin));
		player_data.allowed_skins.push_back(skin);
	}

	file.close();
}

void SaveManager::save()
{
	std::fstream file;
	size_t allowed_size = player_data.allowed_skins.size();

	file.open(PATH_SAVE, std::ios::out | std::ios::binary);

	file.write(reinterpret_cast<char*>(&player_data.count), sizeof(player_data.count));
	file.write(reinterpret_cast<char*>(&player_data.max_streak), sizeof(player_data.max_streak));
	file.write(reinterpret_cast<char*>(&player_data.current_skin), sizeof(player_data.current_skin));
	file.write(reinterpret_cast<char*>(&allowed_size), sizeof(allowed_size));


	for (int i = 0; i < allowed_size; ++i)
	{
		ArrowManager::ArrowType skin = player_data.allowed_skins.at(i);
		file.write(reinterpret_cast<char*>(&skin), sizeof(skin));
	}


	file.close();
}
