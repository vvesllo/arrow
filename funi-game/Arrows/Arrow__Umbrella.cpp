#include "Arrow__Umbrella.h"

Arrow__Umbrella::Arrow__Umbrella()
{
	init(
		ArrowManager::ArrowType::ARROW_UMBRELLA,
		"Umbrella",
		AUTHOR_KOATEG,
		PATH_ARROWS + "/Umbrella",
		ArrowDirection::UP
	);
}

void Arrow__Umbrella::setup()
{
	Arrow::setup();

	m_duration = .5f;
	m_texture = std::make_unique<sf::Texture>();
	m_texture->loadFromFile(get_path() + "/asset.png");

	m_sprite = std::make_unique<sf::Sprite>(*m_texture);
	m_sprite->setOrigin((sf::Vector2f)m_texture->getSize() / 2.f);

	m_size = m_sprite->getGlobalBounds().getSize();

}

void Arrow__Umbrella::correct()
{
	switch_direction();
}

void Arrow__Umbrella::wrong()
{
}

void Arrow__Umbrella::update(float dt)
{
	Arrow::update(dt);

	if (timer < m_duration)
		rotation = std::lerp(prev_rotation, new_rotation, Easing::back_out(timer / m_duration));
	else
		rotation = new_rotation;

	m_sprite->setRotation(rotation * 90);
}

void Arrow__Umbrella::draw(sf::RenderTexture* scene)
{
	sf::Vector2u scene_size = scene->getSize();
	scene->clear(sf::Color(180, 180, 180));
	
	float scale = ArrowManager::arrow_max_width / std::max(m_size.x, m_size.y);

	m_sprite->setScale(scale, scale);
	m_sprite->setPosition((sf::Vector2f)scene_size / 2.f);

	scene->draw(*m_sprite);
}