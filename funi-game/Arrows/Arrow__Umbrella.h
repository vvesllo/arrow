#pragma once

#include "Arrow.h"


class Arrow__Umbrella : public Arrow
{
private:
	std::unique_ptr<sf::Sprite> m_sprite;
	std::unique_ptr<sf::Texture> m_texture;
	sf::Vector2f m_size;
	float m_duration;

public:
	Arrow__Umbrella();

	void setup() override;
	void correct() override;
	void wrong() override;
	void update(float dt) override;

	void draw(sf::RenderTexture* scene) override;
};

