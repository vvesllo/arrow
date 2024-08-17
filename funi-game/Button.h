#pragma once

#include "Utilities.h"

class Button
{
private:
	sf::Vector2f m_position;
	sf::Sprite m_sprite;
	sf::Color m_start_color;

	std::function<void()> m_action;
	bool m_is_active;

public:
	Button(std::function<void()> action);
	Button(std::function<void()> action, sf::Vector2f position);
	Button(std::function<void()> action, sf::Vector2f position, sf::Sprite sprite);
	Button(std::function<void()> action, sf::Vector2f position, sf::Sprite sprite, bool active);

	void update(
		float dt,
		sf::Vector2i mouse_position,
		bool mouse_pressed);


	void set_sprite(sf::Sprite sprite);
	void set_position(sf::Vector2f position);
	void set_active(bool is_active);

	sf::Sprite get_sprite();
	sf::FloatRect get_rect();
	bool get_active();
};