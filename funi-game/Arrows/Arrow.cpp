#include "Arrow.h"

Arrow::Arrow() {}

void Arrow::init(
	ArrowManager::ArrowType type, 
	std::string title,
	std::string author,
	std::string path,
	ArrowDirection direction)
{
	m_is_loaded = false;
	m_title = title;
	m_author = author;
	m_path = path;
	m_direction = direction;
	m_type = type;
}

void Arrow::switch_direction()
{
	int k = (1 + rand() % 2) * ((rand() % 2) ? 1 : -1);

	prev_rotation = new_rotation;
	new_rotation += k;
	new_direction += k;

	timer = 0;

	if (new_direction < 0) new_direction += 4;
	if (new_direction > 3) new_direction -= 4;
	m_direction = (ArrowDirection)new_direction;
}

void Arrow::update(float dt) { timer += dt; }
bool Arrow::is_loaded() { return m_is_loaded; }
void Arrow::setup() { m_is_loaded = true; }
std::string Arrow::get_title(){ return m_title; }
std::string Arrow::get_author(){ return m_author; }
std::string Arrow::get_path(){ return m_path; }
ArrowManager::ArrowType Arrow::get_type() { return m_type; }
void Arrow::set_direction(ArrowDirection direction) { m_direction = direction; }
ArrowDirection Arrow::get_direction() { return m_direction; }

