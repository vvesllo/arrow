#pragma once

#include "Utilities.h"

#include "GameScene.h"
#include "SkinScene.h"


using WindowData = struct WINDOW_DATA {
	unsigned short width;
	unsigned short height;
	unsigned short framerate_limit;
	std::string title;
};

class Game
{
private:
	std::shared_ptr<sf::RenderWindow> m_window;
	
	std::unique_ptr<Scene> m_current_scene;

	WindowData m_window_data;

	InputController m_input_controller;

	sf::Time poll_event();
	void update_scene();

public:
	Game(
		unsigned short width, unsigned short height,
		unsigned short framerate_limit,
		std::string title
	);

	void input_update(sf::Event _event);
	void run();

};

