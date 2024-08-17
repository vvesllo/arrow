#include "Button.h"

Button::Button(std::function<void()> action)
{
	m_action = action;
	m_is_active = true;
	m_start_color = sf::Color::White;
}

Button::Button(std::function<void()> action, sf::Vector2f position)
{
	m_action = action;
	m_is_active = true;
	m_start_color = sf::Color::White;
	m_position = position;
}

Button::Button(std::function<void()> action, sf::Vector2f position, sf::Sprite sprite)
{
	m_action = action;
	m_is_active = true;
	m_start_color = sf::Color::White;
	m_position = position;
	set_sprite(sprite);
}

Button::Button(std::function<void()> action, sf::Vector2f position, sf::Sprite sprite, bool active)
{
	m_action = action;
	m_is_active = active;
	m_start_color = sf::Color::White;
	m_position = position;
	set_sprite(sprite);
}

void Button::update(
	float dt,
	sf::Vector2i mouse_position,
	bool mouse_pressed)
{
	m_sprite.setPosition(m_position);
	m_sprite.setColor(m_start_color);

	if (get_rect().contains(sf::Vector2f(mouse_position)) && m_is_active)
	{
		m_sprite.setColor(
			sf::Color(
				std::max((int)m_start_color.r-50, 0),
				std::max((int)m_start_color.g-50, 0),
				std::max((int)m_start_color.b-50, 0)
			)
		);
		if (mouse_pressed) m_action();
	}
}

void Button::set_sprite(sf::Sprite sprite)
{
	m_start_color = sprite.getColor();
	m_sprite = sprite;
	m_sprite.setOrigin(sprite.getGlobalBounds().getSize() / 2.f);
}

void Button::set_position(sf::Vector2f position) { m_position = position; }

void Button::set_active(bool is_active) { m_is_active = is_active; }

sf::Sprite Button::get_sprite() { return m_sprite; }
sf::FloatRect Button::get_rect() { return m_sprite.getGlobalBounds(); }
bool Button::get_active() { return m_is_active; }
