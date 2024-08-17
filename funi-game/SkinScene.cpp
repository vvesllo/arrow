#include "SkinScene.h"

void SkinScene::update_UI(float dt, InputController& ic)
{

}

SkinScene::~SkinScene()
{
	m_buttons.clear();
}

void SkinScene::init()
{
	int _i = 0;
	float _k;
	m_padding = 10;
	
	sf::Sprite sprite(*SceneManager::ui_texture);

	sprite.setTextureRect(UIRect::close);
	m_buttons.push_back(
		std::make_unique<Button>(
			[]() { SceneManager::change_scene(SceneManager::SCENE_TYPE::GAME_SCENE); },
			sf::Vector2f(55, window->getSize().y - 55),
			sprite
		)
	);

	sprite.setTextureRect(UIRect::window_close);
	m_buttons.push_back(
		std::make_unique<Button>(
			[=]() { window->close(); SaveManager::save(); },
			sf::Vector2f(window->getSize().x - 50, 30),
			sprite
		)
	);

	sprite.setTextureRect(UIRect::window_collapse);
	m_buttons.push_back(
		std::make_unique<Button>(
			[=]() { SendNotifyMessage(window->getSystemHandle(), WM_SYSCOMMAND, SC_MINIMIZE, 0); },
			sf::Vector2f(50, 30),
			sprite
		)
	);


	std::unique_ptr<Button> button;
	std::function<void()> f;
	sf::Sprite icon_sprite;
	bool active;

	for (std::pair<ArrowManager::ArrowType, std::shared_ptr<Arrow>> arrow : ArrowManager::arrow_map)
	{
		active = true;
		icon_sprite.setTexture(*ArrowManager::arrow_icons[arrow.first]);
		f = [=]() { player_data.current_skin = arrow.first; };


		if (std::find(
			player_data.allowed_skins.cbegin(),
			player_data.allowed_skins.cend(),
			arrow.first
		) == player_data.allowed_skins.cend())
		{
			active = false;
			icon_sprite.setColor(sf::Color(0, 0, 0));
		}

		_k = 100 / icon_sprite.getLocalBounds().width;
		icon_sprite.setScale(_k, _k);


		m_buttons.push_back(
			std::make_unique<Button>(
				f, sf::Vector2f(50 + m_padding + (100 + m_padding * 2) * _i++, 100 + m_padding),
				icon_sprite, active
			)
		);
	}
}

void SkinScene::poll_event(sf::Event _event)
{
	switch (_event.type)
	{
	case sf::Event::MouseButtonPressed:
		if (_event.mouseButton.button == sf::Mouse::Left)
		{

			bool flag = false;
			for (std::list<std::unique_ptr<Button>>::const_iterator it = m_buttons.begin(); it != m_buttons.end(); it++)
			{
				if (flag = (*it)->get_rect()
					.contains(sf::Vector2f(_event.mouseButton.x, _event.mouseButton.y)))
					break;
			}
			if (!flag)
			{
				m_grabbed_offset = window->getPosition() - sf::Mouse::getPosition();
				m_grabbed_window = true;
			}
		}
		break;
	case sf::Event::MouseButtonReleased:
		if (_event.mouseButton.button == sf::Mouse::Left)
			m_grabbed_window = false;
		break;
	case sf::Event::MouseMoved:
		if (m_grabbed_window)
			window->setPosition(sf::Mouse::getPosition() + m_grabbed_offset);
		break;
	}
}

void SkinScene::update(float dt, InputController& ic)
{
	m_mouse_position = sf::Mouse::getPosition(*window);

	for (std::list<std::unique_ptr<Button>>::const_iterator it = m_buttons.begin(); it != m_buttons.end(); it++)
		(*it)->update(dt, m_mouse_position, ic.LMouse_);
}

void SkinScene::draw()
{
	scene->clear(sf::Color(54, 60, 99));


	for (std::list<std::unique_ptr<Button>>::const_iterator it = m_buttons.begin(); it != m_buttons.end(); it++)
		scene->draw((*it)->get_sprite());

	scene->display();
}
