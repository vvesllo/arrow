#include "Game.h"


Game::Game(
    unsigned short width, unsigned short height,
    unsigned short framerate_limit, 
    std::string title
)
{
    m_window_data.width = width;
    m_window_data.height = height;
    m_window_data.framerate_limit = framerate_limit;
    m_window_data.title = title;
	
    m_window = std::make_shared<sf::RenderWindow>();
    m_window->create(sf::VideoMode(width, height), title, sf::Style::None);
    m_window->setFramerateLimit(framerate_limit);

	srand((unsigned int)time(NULL));

	SceneManager::load_resources();
	SceneManager::change_scene(SceneManager::SCENE_TYPE::GAME_SCENE);
	ArrowManager::load_icons();

	if (std::filesystem::exists(PATH_SAVE))
		SaveManager::load();
}

void Game::input_update(sf::Event _event)
{
	switch (_event.type)
	{
	case sf::Event::MouseButtonPressed:
		switch (_event.mouseButton.button)
		{
		case sf::Mouse::Left:		m_input_controller.press_lmouse();			break;
		case sf::Mouse::Right:		m_input_controller.press_rmouse();			break;
		case sf::Mouse::XButton1:	m_input_controller.press_x1mouse();			break;
		case sf::Mouse::XButton2:	m_input_controller.press_x2mouse();			break;
		}
		break;
	case sf::Event::MouseButtonReleased:
		switch (_event.mouseButton.button)
		{
		case sf::Mouse::Left:		m_input_controller.release_lmouse();			break;
		case sf::Mouse::Right:		m_input_controller.release_rmouse();			break;
		case sf::Mouse::XButton1:	m_input_controller.release_x1mouse();			break;
		case sf::Mouse::XButton2:	m_input_controller.release_x2mouse();			break;
		}
		break;
	case sf::Event::KeyPressed:
		switch (_event.key.code)
		{
		case sf::Keyboard::A:			m_input_controller.press_A();			break;
		case sf::Keyboard::B:			m_input_controller.press_B();			break;
		case sf::Keyboard::C:			m_input_controller.press_C();			break;
		case sf::Keyboard::D:			m_input_controller.press_D();			break;
		case sf::Keyboard::E:			m_input_controller.press_E();			break;
		case sf::Keyboard::F:			m_input_controller.press_F();			break;
		case sf::Keyboard::G:			m_input_controller.press_G();			break;
		case sf::Keyboard::H:			m_input_controller.press_H();			break;
		case sf::Keyboard::I:			m_input_controller.press_I();			break;
		case sf::Keyboard::J:			m_input_controller.press_J();			break;
		case sf::Keyboard::K:			m_input_controller.press_K();			break;
		case sf::Keyboard::L:			m_input_controller.press_L();			break;
		case sf::Keyboard::M:			m_input_controller.press_M();			break;
		case sf::Keyboard::N:			m_input_controller.press_N();			break;
		case sf::Keyboard::O:			m_input_controller.press_O();			break;
		case sf::Keyboard::P:			m_input_controller.press_P();			break;
		case sf::Keyboard::Q:			m_input_controller.press_Q();			break;
		case sf::Keyboard::R:			m_input_controller.press_R();			break;
		case sf::Keyboard::S:			m_input_controller.press_S();			break;
		case sf::Keyboard::T:			m_input_controller.press_T();			break;
		case sf::Keyboard::U:			m_input_controller.press_U();			break;
		case sf::Keyboard::V:			m_input_controller.press_V();			break;
		case sf::Keyboard::W:			m_input_controller.press_W();			break;
		case sf::Keyboard::X:			m_input_controller.press_X();			break;
		case sf::Keyboard::Y:			m_input_controller.press_Y();			break;
		case sf::Keyboard::Z:			m_input_controller.press_Z();			break;

		case sf::Keyboard::F1:			m_input_controller.press_F1();		break;
		case sf::Keyboard::F2:			m_input_controller.press_F2();		break;
		case sf::Keyboard::F3:			m_input_controller.press_F3();		break;
		case sf::Keyboard::F4:			m_input_controller.press_F4();		break;
		case sf::Keyboard::F5:			m_input_controller.press_F5();		break;
		case sf::Keyboard::F6:			m_input_controller.press_F6();		break;
		case sf::Keyboard::F7:			m_input_controller.press_F7();		break;
		case sf::Keyboard::F8:			m_input_controller.press_F8();		break;
		case sf::Keyboard::F9:			m_input_controller.press_F9();		break;
		case sf::Keyboard::F10:			m_input_controller.press_F10();		break;
		case sf::Keyboard::F11:			m_input_controller.press_F11();		break;
		case sf::Keyboard::F12:			m_input_controller.press_F12();		break;

		case sf::Keyboard::Space:		m_input_controller.press_Space();	break;
		case sf::Keyboard::Return:		m_input_controller.press_Return();	break;
		case sf::Keyboard::Escape:		m_input_controller.press_Escape();	break;

		case sf::Keyboard::Left:		m_input_controller.press_left();	break;
		case sf::Keyboard::Right:		m_input_controller.press_right();	break;
		case sf::Keyboard::Up:			m_input_controller.press_up();		break;
		case sf::Keyboard::Down:		m_input_controller.press_down();	break;
		}
		break;
	case sf::Event::KeyReleased:
		switch (_event.key.code)
		{
		case sf::Keyboard::A:			m_input_controller.release_A();		break;
		case sf::Keyboard::B:			m_input_controller.release_B();		break;
		case sf::Keyboard::C:			m_input_controller.release_C();		break;
		case sf::Keyboard::D:			m_input_controller.release_D();		break;
		case sf::Keyboard::E:			m_input_controller.release_E();		break;
		case sf::Keyboard::F:			m_input_controller.release_F();		break;
		case sf::Keyboard::G:			m_input_controller.release_G();		break;
		case sf::Keyboard::H:			m_input_controller.release_H();		break;
		case sf::Keyboard::I:			m_input_controller.release_I();		break;
		case sf::Keyboard::J:			m_input_controller.release_J();		break;
		case sf::Keyboard::K:			m_input_controller.release_K();		break;
		case sf::Keyboard::L:			m_input_controller.release_L();		break;
		case sf::Keyboard::M:			m_input_controller.release_M();		break;
		case sf::Keyboard::N:			m_input_controller.release_N();		break;
		case sf::Keyboard::O:			m_input_controller.release_O();		break;
		case sf::Keyboard::P:			m_input_controller.release_P();		break;
		case sf::Keyboard::Q:			m_input_controller.release_Q();		break;
		case sf::Keyboard::R:			m_input_controller.release_R();		break;
		case sf::Keyboard::S:			m_input_controller.release_S();		break;
		case sf::Keyboard::T:			m_input_controller.release_T();		break;
		case sf::Keyboard::U:			m_input_controller.release_U();		break;
		case sf::Keyboard::V:			m_input_controller.release_V();		break;
		case sf::Keyboard::W:			m_input_controller.release_W();		break;
		case sf::Keyboard::X:			m_input_controller.release_X();		break;
		case sf::Keyboard::Y:			m_input_controller.release_Y();		break;
		case sf::Keyboard::Z:			m_input_controller.release_Z();		break;

		case sf::Keyboard::F1:			m_input_controller.release_F1();		break;
		case sf::Keyboard::F2:			m_input_controller.release_F2();		break;
		case sf::Keyboard::F3:			m_input_controller.release_F3();		break;
		case sf::Keyboard::F4:			m_input_controller.release_F4();		break;
		case sf::Keyboard::F5:			m_input_controller.release_F5();		break;
		case sf::Keyboard::F6:			m_input_controller.release_F6();		break;
		case sf::Keyboard::F7:			m_input_controller.release_F7();		break;
		case sf::Keyboard::F8:			m_input_controller.release_F8();		break;
		case sf::Keyboard::F9:			m_input_controller.release_F9();		break;
		case sf::Keyboard::F10:			m_input_controller.release_F10();		break;
		case sf::Keyboard::F11:			m_input_controller.release_F11();		break;
		case sf::Keyboard::F12:			m_input_controller.release_F12();		break;

		case sf::Keyboard::Space:		m_input_controller.release_Space();		break;
		case sf::Keyboard::Return:		m_input_controller.release_Return();	break;
		case sf::Keyboard::Escape:		m_input_controller.release_Escape();	break;

		case sf::Keyboard::Left:		m_input_controller.release_left();		break;
		case sf::Keyboard::Right:		m_input_controller.release_right();		break;
		case sf::Keyboard::Up:			m_input_controller.release_up();		break;
		case sf::Keyboard::Down:		m_input_controller.release_down();		break;
		}
		break;
	}
}

void Game::run()
{
    float dt;
    sf::Clock _clock;
    _clock.restart();

    while (m_window->isOpen())
    {
		update_scene();
        dt = (float)(_clock.restart() - poll_event()).asSeconds();
		m_current_scene->update(dt, m_input_controller);
		m_current_scene->render();
		m_input_controller.update();
    }
}

sf::Time Game::poll_event()
{
    sf::Clock _clock;
    sf::Event _event;
	while (m_window->pollEvent(_event))
	{
		m_current_scene->poll_event(_event);
		input_update(_event);
	}

    return _clock.getElapsedTime();
}

void Game::update_scene()
{
	if (SceneManager::scene_changed)
	{
		m_current_scene.reset();

		switch (SceneManager::active_scene)
		{
		case SceneManager::SCENE_TYPE::GAME_SCENE:
			m_current_scene = std::make_unique<GameScene>();
			break;
		case SceneManager::SCENE_TYPE::SKIN_SCENE:
			m_current_scene = std::make_unique<SkinScene>();
			break;
		}

		m_current_scene->create(m_window);

		SceneManager::scene_changed = false;
	}
}
