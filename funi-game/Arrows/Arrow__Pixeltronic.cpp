#include "Arrow__Pixeltronic.h"

Arrow__Pixeltronic::Arrow__Pixeltronic()
{
	init(
		ArrowManager::ArrowType::ARROW_PIXELTRONIC,
		"Pixeltronic",
		AUTHOR_WSLL,
		PATH_ARROWS + "/Pixeltronic",
		ArrowDirection::UP
	);
}

void Arrow__Pixeltronic::setup()
{
	Arrow::setup();

	m_duration = 0.5f;

	m_texture = std::make_unique<sf::Texture>();
	m_texture->loadFromFile(get_path() + "/asset.png");

	m_sprites[0] = std::make_unique<sf::Sprite>(*m_texture);
	m_sprites[0]->setTextureRect(
		sf::IntRect(1, 1, 39, 39)
	);

	m_sprites[1] = std::make_unique<sf::Sprite>(*m_texture);
	m_sprites[1]->setTextureRect(
		sf::IntRect(41, 1, 13, 19)
	);

	m_sizes[0] = m_sprites[0]->getGlobalBounds().getSize();
	m_sizes[1] = m_sprites[1]->getGlobalBounds().getSize();

	m_sprites[0]->setOrigin(m_sizes[0] / 2.f);
	m_sprites[1]->setOrigin(m_sizes[1] / 2.f);

}

void Arrow__Pixeltronic::correct()
{
	switch_direction();
}

void Arrow__Pixeltronic::wrong()
{
}

void Arrow__Pixeltronic::update(float dt)
{
	Arrow::update(dt);

	if (timer < m_duration)
		rotation = std::lerp(prev_rotation, new_rotation, Easing::elastic_out(timer / m_duration, 2));
	else
		rotation = new_rotation;

	m_sprites[1]->setRotation(rotation * 90);
}

void Arrow__Pixeltronic::draw(sf::RenderTexture* scene)
{
	sf::Vector2u scene_size = scene->getSize();
	scene->clear(sf::Color(94, 70, 80));

	float scale = ArrowManager::arrow_max_width / std::max(m_sizes[0].x, m_sizes[0].y);
	m_sprites[0]->setScale(scale, scale);
	m_sprites[1]->setScale(scale, scale);

	m_sprites[0]->setPosition((sf::Vector2f)scene_size / 2.f);
	m_sprites[1]->setPosition((sf::Vector2f)scene_size / 2.f);

	scene->draw(*m_sprites[0]);
	scene->draw(*m_sprites[1]);

	scene->display();
}