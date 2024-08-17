#include "Scene.h"

void Scene::create(std::shared_ptr<sf::RenderWindow> window)
{
	this->window = window;

	scene = std::make_unique<sf::RenderTexture>();
	scene->create(
		window->getSize().x,
		window->getSize().y
	);

	init();
}

void Scene::render()
{
	window->clear();

	draw();
	window->draw(sf::Sprite(scene->getTexture()));

	window->display();
}
