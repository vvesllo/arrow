#include "Arrow__Finger.h"

Arrow__Finger::Arrow__Finger() 
{
	init(
		ArrowManager::ArrowType::ARROW_FINGER,
		"Finger",
		AUTHOR_PARTICLE,
		PATH_ARROWS + "/Finger",
		ArrowDirection::UP
	);
}

void Arrow__Finger::setup()
{
	Arrow::setup();

	m_texture = std::make_unique<sf::Texture>();
	m_texture->loadFromFile(get_path() + "/asset.png");

	m_sprites[0] = std::make_unique<sf::Sprite>(*m_texture);
	m_sprites[0]->setTextureRect(
		sf::IntRect(1, 1, 80, 80)
	);

	m_sprites[1] = std::make_unique<sf::Sprite>(*m_texture);
	m_sprites[1]->setTextureRect(
		sf::IntRect(96, 1, 32, 55)
	);

	m_sizes[0] = m_sprites[0]->getGlobalBounds().getSize();
	m_sizes[1] = m_sprites[1]->getGlobalBounds().getSize();

	m_sprites[0]->setOrigin(m_sizes[0] / 2.f);
	m_sprites[1]->setOrigin(m_sizes[1] / 2.f);
}

void Arrow__Finger::correct()
{
	switch_direction();
}

void Arrow__Finger::wrong()
{
}

void Arrow__Finger::update(float dt)
{
	rotation = std::lerp(rotation, new_rotation, .5f);
	m_sprites[1]->setRotation(rotation * 90);
}

void Arrow__Finger::draw(sf::RenderTexture* scene)
{
	sf::Vector2u scene_size = scene->getSize();
	scene->clear(sf::Color(114, 156, 81));

	float scale = ArrowManager::arrow_max_width / std::max(m_sizes[0].x, m_sizes[0].y);
	m_sprites[0]->setScale(scale, scale);
	m_sprites[1]->setScale(scale, scale);

	m_sprites[0]->setPosition((sf::Vector2f)scene_size / 2.f);
	m_sprites[1]->setPosition((sf::Vector2f)scene_size / 2.f);
	
	scene->draw(*m_sprites[0]);
	scene->draw(*m_sprites[1]);

	scene->display();
}