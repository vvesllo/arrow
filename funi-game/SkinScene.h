#pragma once

#include <vector>

#include "Scene.h"
#include "Button.h"


class SkinScene : public Scene
{
private:
	std::list<std::unique_ptr<Button>> m_buttons;

	sf::Vector2i m_mouse_position;
	int m_padding;

	sf::Vector2i m_grabbed_offset;
	bool m_grabbed_window;

	void update_UI(float dt, InputController& ic);

public:
	~SkinScene();
	void init() override;

	void poll_event(sf::Event _event) override;
	void update(float dt, InputController& ic) override;
	void draw() override;
};


