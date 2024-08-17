#pragma once

#include "Scene.h"


class GameScene : public Scene
{
private:
	std::shared_ptr<Arrow> m_arrow;
	ArrowDirection m_user_direction;

	sf::Vector2u m_window_size;
	sf::Vector2i m_mouse_position;


	unsigned long long m_streak;
	unsigned long long m_arrow_cursor;

	std::list<std::unique_ptr<Button>> m_buttons;

	std::unique_ptr<sf::Text> m_version_label;
	std::unique_ptr<sf::Text> m_count_label;
	std::unique_ptr<sf::Text> m_streak_label;
	std::unique_ptr<sf::Text> m_arrow_title_label;
	std::unique_ptr<sf::Text> m_arrow_author_label;

	sf::Sprite m_scale[2];

	float m_scale_scale;

	float m_timer_speed;
	sf::Time m_timer;


	sf::Vector2i m_grabbed_offset;
	bool m_grabbed_window;

	void load();


	void check_input(InputController ic);
	void correct();
	void wrong();

	void init_resources();
	void init_UI();
	void init_labels();

	void update_UI(float dt, InputController& ic);
	void update_labels();
	void update_info_labels();

	void draw_UI();
	void draw_labels();

public:
	GameScene();

	void init() override;

	void poll_event(sf::Event _event) override;
	void update(float dt, InputController& ic) override;
	void draw() override;
};

