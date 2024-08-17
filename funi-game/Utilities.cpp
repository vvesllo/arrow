#include "Utilities.h"



sf::Vector2f Utilities::normalize(sf::Vector2f source)
{
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if (length == 0)
		return sf::Vector2f();

	return source / length;
}

sf::Vector2f Utilities::lerp(sf::Vector2f a, sf::Vector2f b, float t)
{
	return sf::Vector2f(
		std::lerp(a.x, b.x, t),
		std::lerp(a.y, b.y, t)
	);
}

std::string Utilities::str_to_upper(std::string str)
{
	for (auto& c : str) c = toupper(c);
	return str;
}

std::unique_ptr<sf::Texture> SceneManager::ui_texture = std::make_unique<sf::Texture>();
std::unique_ptr<sf::Font> SceneManager::font_bold = std::make_unique<sf::Font>();
std::unique_ptr<sf::Font> SceneManager::font = std::make_unique<sf::Font>();

bool SceneManager::scene_changed = false;
SceneManager::SCENE_TYPE SceneManager::active_scene = SceneManager::SCENE_TYPE::NONE;


sf::IntRect UIRect::discord = sf::IntRect(1, 1, 70, 70);
sf::IntRect UIRect::skins = sf::IntRect(73, 1, 70, 70);
sf::IntRect UIRect::close = sf::IntRect(145, 1, 70, 70);
sf::IntRect UIRect::scale_1 = sf::IntRect(1, 74, 200, 18);
sf::IntRect UIRect::scale_2 = sf::IntRect(1, 94, 200, 18);
sf::IntRect UIRect::window_close = sf::IntRect(1, 113, 70, 35);
sf::IntRect UIRect::window_collapse = sf::IntRect(73, 113, 70, 35);


void SceneManager::change_scene(SceneManager::SCENE_TYPE scene_type)
{
	SceneManager::active_scene = scene_type;
	SceneManager::scene_changed = true;
}

void SceneManager::load_resources()
{
	ui_texture->loadFromFile(PATH_ASSETS + "/UI/asset.png");
	
	font_bold->loadFromFile(PATH_FONTS + "/bold.ttf");
	font->loadFromFile(PATH_FONTS + "/regular.ttf");
}