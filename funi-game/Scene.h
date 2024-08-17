#pragma once

#include "InputController.h"
#include "Player.h"
#include "ArrowManager.h"
#include "Utilities.h"
#include "Button.h"


class Scene
{
protected:
	std::shared_ptr<sf::RenderWindow> window;
	std::unique_ptr<sf::RenderTexture> scene;

public:
	void create(std::shared_ptr<sf::RenderWindow> window);

	void render();

	virtual void init() = 0;

	virtual void poll_event(sf::Event _event) = 0;
	virtual void update(float dt, InputController& ic) = 0;
	virtual void draw() = 0;
};

