#include "ArrowManager.h"

std::map<ArrowManager::ArrowType, std::unique_ptr<sf::Texture>> ArrowManager::arrow_icons = {};

std::map<ArrowManager::ArrowType, std::shared_ptr<Arrow>> ArrowManager::arrow_map = {
	PUSH_ARROW(FINGER, Finger),
	PUSH_ARROW(BOTINOK, Botinok),
	PUSH_ARROW(UMBRELLA, Umbrella),
	PUSH_ARROW(PIXELTRONIC, Pixeltronic),
};

void ArrowManager::load_icons()
{
	for (auto arrow_data : arrow_map)
		ArrowManager::load_icon(arrow_data.first, arrow_data.second->get_path());
}

void ArrowManager::load_icon(ArrowManager::ArrowType type, std::string path)
{
	arrow_icons[type] = std::make_unique<sf::Texture>();
	arrow_icons[type]->loadFromFile(path + "/icon.png");
}