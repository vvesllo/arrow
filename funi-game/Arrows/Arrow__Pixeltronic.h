#pragma once

#include "Arrow.h"


class Arrow__Pixeltronic : public Arrow
{
private:
	std::unique_ptr<sf::Sprite> m_sprites[2];
	std::unique_ptr<sf::Texture> m_texture;
	sf::Vector2f m_sizes[2];
	float m_duration;

public:
	Arrow__Pixeltronic();

	void setup() override;
	void correct() override;
	void wrong() override;
	void update(float dt) override;

	void draw(sf::RenderTexture* scene) override;
};

