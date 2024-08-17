#pragma once

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>

#define PRINT_VAR(var)
#ifdef DEBUG
	#include <iostream>
	#define PRINT_VAR(var) std::cout << #var << "=" << var << '\n'
#endif

#include <sstream>
#include <string>
#include <fstream>
#include <filesystem>
#include <map>
#include <algorithm>
#include <memory>
#include <functional>
#include <windows.h>
#include <shellapi.h>

#define MAJOR 3
#define MINOR 3
#define PATCH 0


#define PATH_SAVE		std::string("arrow.save")
#define PATH_ASSETS		std::string("Assets")
#define PATH_FONTS		std::string(PATH_ASSETS+"/Fonts")
#define PATH_ARROWS		std::string(PATH_ASSETS+"/Arrows")


#define AUTHOR_PARTICLE		"Particle"
#define AUTHOR_WSLL			"WSLL"
#define AUTHOR_PROTKAST		"Protkast"
#define AUTHOR_KOATEG		"Koateg"



#define OPEN_WEB(url) ShellExecute(0, 0, url, 0, 0, SW_SHOW)

#define PUSH_ARROW(enum_title, class_title)\
	{ ArrowManager::ArrowType::ARROW_##enum_title, std::make_unique<Arrow__##class_title>() }


namespace UIRect {
	extern sf::IntRect discord;
	extern sf::IntRect skins;
	extern sf::IntRect close;
	extern sf::IntRect scale_1;
	extern sf::IntRect scale_2;
	extern sf::IntRect window_close;
	extern sf::IntRect window_collapse;
};

namespace SceneManager
{
	enum SCENE_TYPE {
		NONE = -1,
		GAME_SCENE = 0,
		SKIN_SCENE,
	};

	extern std::unique_ptr<sf::Texture> ui_texture;
	extern std::unique_ptr<sf::Font> font_bold;
	extern std::unique_ptr<sf::Font> font;
	

	extern bool scene_changed;
	extern SceneManager::SCENE_TYPE active_scene;

	void load_resources();
	void change_scene(SceneManager::SCENE_TYPE scene_type);
}

namespace Utilities
{
	sf::Vector2f normalize(sf::Vector2f source);
	sf::Vector2f lerp(sf::Vector2f a, sf::Vector2f b, float t);
	inline std::string str_to_upper(std::string str);
};
