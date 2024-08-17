#include "Arrow__Botinok.h"

Arrow__Botinok::Arrow__Botinok()
{
	init(
		ArrowManager::ArrowType::ARROW_BOTINOK,
		"Botinok",
		AUTHOR_KOATEG,
		PATH_ARROWS + "/Botinok",
		ArrowDirection::UP
	);
}

void Arrow__Botinok::setup()
{
	Arrow::setup();
	m_texture = std::make_unique<sf::Texture>();
	m_texture->loadFromFile(get_path() + "/asset.png");

	m_sprite = std::make_unique<sf::Sprite>(*m_texture);
	m_sprite->setOrigin((sf::Vector2f)m_texture->getSize() / 2.f);

	m_size = m_sprite->getGlobalBounds().getSize();
}

void Arrow__Botinok::correct()
{
	switch_direction();
}

void Arrow__Botinok::wrong()
{
}

void Arrow__Botinok::update(float dt)
{
	rotation = std::lerp(rotation, new_rotation, .6f);
	m_sprite->setRotation(rotation * 90);
}

void Arrow__Botinok::draw(sf::RenderTexture* scene)
{
	sf::Vector2u scene_size = scene->getSize();
	scene->clear(sf::Color(50, 168, 82));

	float scale = ArrowManager::arrow_max_width / std::max(m_size.x, m_size.y);

	m_sprite->setScale(scale, scale);
	m_sprite->setPosition((sf::Vector2f)scene_size / 2.f);

	scene->draw(*m_sprite);
}