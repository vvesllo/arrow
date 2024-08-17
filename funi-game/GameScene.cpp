#include "GameScene.h"


GameScene::GameScene() {}

void GameScene::load()
{
}

void GameScene::init()
{
	m_grabbed_window = 0;

	m_streak = 0;
	m_timer_speed = 0;
	m_window_size = window->getSize();

	m_timer = sf::milliseconds(0);


	m_arrow_cursor = std::find(
		player_data.allowed_skins.cbegin(),
		player_data.allowed_skins.cend(),
		player_data.current_skin
	) - player_data.allowed_skins.cbegin();


	m_arrow = ArrowManager::arrow_map.at(player_data.current_skin);
	if (!m_arrow->is_loaded())
		m_arrow->setup();

	init_resources();

	load();

	init_UI();
	init_labels();

	update_info_labels();

	m_count_label->setPosition(20, 45);
	m_streak_label->setPosition(20, 80);


	sf::Vector2f version_size = m_version_label->getGlobalBounds().getSize();
	m_version_label->setPosition(
		(m_window_size.x - version_size.x) / 2,
		m_window_size.y - version_size.y - 20
	);
}

void GameScene::init_resources() {}

void GameScene::init_UI()
{
	sf::Sprite sprite(*SceneManager::ui_texture);
	sprite.setTextureRect(UIRect::discord);

	m_buttons.push_back(
		std::make_unique<Button>(
			[]() {
				OPEN_WEB(L"https://discord.com/invite/dk4qYYH8bc");
			},
			sf::Vector2f(window->getSize().x - 70, window->getSize().y - 70 * 2 - 20),
			sprite
		)
	);


	sprite.setTextureRect(UIRect::skins);
	m_buttons.push_back(
		std::make_unique<Button>(
			[]() {
				SceneManager::change_scene(SceneManager::SCENE_TYPE::SKIN_SCENE);
			},
			sf::Vector2f(window->getSize().x - 70, window->getSize().y - 70),
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

	m_scale[0].setTexture(*SceneManager::ui_texture);
	m_scale[0].setTextureRect(UIRect::scale_1);
	m_scale[0].setPosition(20, 120);

	m_scale[1].setTexture(*SceneManager::ui_texture);
	m_scale[1].setTextureRect(UIRect::scale_1);
	m_scale[1].setPosition(20, 120);
}

void GameScene::init_labels()
{

	m_count_label = std::make_unique<sf::Text>("0", *SceneManager::font_bold, 32);
	m_count_label->setFillColor(sf::Color::Black);

	m_streak_label = std::make_unique<sf::Text>("0", *SceneManager::font, 24);
	m_streak_label->setFillColor(sf::Color::Black);

	m_arrow_title_label = std::make_unique<sf::Text>(m_arrow->get_title(), *SceneManager::font_bold, 32);
	m_arrow_title_label->setFillColor(sf::Color::Black);

	m_arrow_author_label = std::make_unique<sf::Text>(m_arrow->get_author(), *SceneManager::font, 24);
	m_arrow_author_label->setFillColor(sf::Color::Black);

	m_version_label = std::make_unique<sf::Text>(
		"Version " + std::to_string(MAJOR) + "." + std::to_string(MINOR) + "." + std::to_string(PATCH),
		*SceneManager::font, 24);
	m_version_label->setFillColor(sf::Color::Black);
}

void GameScene::update_UI(float dt, InputController& ic)
{
	for (std::list<std::unique_ptr<Button>>::const_iterator it = m_buttons.begin(); it != m_buttons.end(); it++)
		(*it)->update(dt, m_mouse_position, ic.LMouse_);
}

void GameScene::update_labels()
{
	m_count_label->setString(
		"Count: " + std::to_string(player_data.count)
	);
	m_streak_label->setString(
		"Streak: " + std::to_string(m_streak) + "/" + std::to_string(player_data.max_streak)
	);

	m_arrow_title_label->setPosition(m_window_size.x - m_arrow_title_label->getGlobalBounds().getSize().x - 20, 45);
	m_arrow_author_label->setPosition(m_window_size.x - m_arrow_author_label->getGlobalBounds().getSize().x - 20, 80);
}

void GameScene::update_info_labels()
{
	m_arrow_author_label->setString("idea: " + m_arrow->get_author());
	m_arrow_title_label->setString(m_arrow->get_title());
}

void GameScene::poll_event(sf::Event _event)
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

void GameScene::update(float dt, InputController& ic)
{
	m_mouse_position = sf::Mouse::getPosition(*window);
	check_input(ic);

	
	if (m_timer == sf::milliseconds(0))
	{
		m_streak = 0;
		m_timer_speed = 1;
	}

	m_timer = std::clamp(m_timer, sf::milliseconds(0), sf::milliseconds(1000));
	m_timer -= sf::milliseconds(1) * m_timer_speed;

	sf::IntRect m_scale_rect = UIRect::scale_2;
	m_scale_rect.width = 200 * m_scale_scale;

	m_scale_scale = float(m_timer.asMilliseconds() / 1000.f);
	m_scale[1].setTextureRect(m_scale_rect);

	m_arrow->update(dt);

	update_labels();
	update_UI(dt, ic);
}

void GameScene::draw_UI()
{

	for (std::list<std::unique_ptr<Button>>::const_iterator it = m_buttons.begin(); it != m_buttons.end(); it++)
		scene->draw((*it)->get_sprite());

	scene->draw(m_scale[0]);
	scene->draw(m_scale[1]);
}

void GameScene::draw_labels()
{
	scene->draw(*m_count_label);
	scene->draw(*m_streak_label);
	scene->draw(*m_arrow_title_label);
	scene->draw(*m_arrow_author_label);
	scene->draw(*m_version_label);

}

void GameScene::draw()
{
	m_arrow->draw(scene.get());

	draw_labels();
	draw_UI();
	
	scene->display();
}

void GameScene::check_input(InputController ic)
{
	if (ic._W || ic._Up)
	{
		if (m_arrow->get_direction() == ArrowDirection::UP) correct();
		else wrong();
	}
	if (ic._A || ic._Left)
	{
		if (m_arrow->get_direction() == ArrowDirection::LEFT) correct();
		else wrong();
	}
	if (ic._S || ic._Down)
	{
		if (m_arrow->get_direction() == ArrowDirection::DOWN) correct();
		else wrong();
	}
	if (ic._D || ic._Right)
	{
		if (m_arrow->get_direction() == ArrowDirection::RIGHT) correct();
		else wrong();
	}
}

void GameScene::correct()
{
	m_arrow->correct();
	m_streak++;
	player_data.count++;
	player_data.max_streak = std::max(m_streak, player_data.max_streak);
	m_timer += sf::milliseconds(100);
	m_timer_speed = std::clamp(m_timer_speed + 0.1f, 1.f, 20.f);
}

void GameScene::wrong()
{
	m_arrow->wrong();
	m_streak = 0;
	m_timer = sf::milliseconds(0);
	m_timer_speed = 0;
}
