#pragma once

#include "Arrow.h"


class Arrow__Finger : public Arrow
{
private:
	std::unique_ptr<sf::Sprite> m_sprites[2];
	std::unique_ptr<sf::Texture> m_texture;
	sf::Vector2f m_sizes[2];

public:
	Arrow__Finger();

	void setup() override;
	void correct() override;
	void wrong() override;
	void update(float dt) override;

	void draw(sf::RenderTexture* scene) override;
};

