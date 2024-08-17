#pragma once

#include "../Utilities.h"
#include "../Easing.h"


using ArrowDirection = enum ARROW_DIRECTION
{
	UP=0,
	RIGHT=1,
	DOWN=2,
	LEFT=3,
};

namespace ArrowManager
{
	enum ArrowType : int {
		ARROW_FINGER,
		ARROW_BOTINOK,
		ARROW_UMBRELLA,
		ARROW_PIXELTRONIC,
	};
}

class Arrow
{
private:
	std::string m_title; 
	std::string m_author;
	std::string m_path;

	ArrowManager::ArrowType m_type;
	ArrowDirection m_direction;
	bool m_is_loaded;

protected:
	float rotation=0;
	float timer=0;

	int prev_rotation=0;
	int new_rotation=0;
	int new_direction=0;


public:
	Arrow();

	virtual void init(
		ArrowManager::ArrowType type, 
		std::string title, 
		std::string author, 
		std::string path, 
		ArrowDirection direction);

	virtual void setup();
	virtual void update(float dt);
	virtual void correct()=0;
	virtual void wrong()=0;

	virtual void draw(sf::RenderTexture* scene)=0;

	void switch_direction();
	bool is_loaded();

	std::string get_title();
	std::string get_author();
	std::string get_path();

	ArrowManager::ArrowType get_type();

	void set_direction(ArrowDirection direction);
	ArrowDirection get_direction();

};


namespace ArrowManager
{
	static const short arrow_max_width = 300;
	extern std::map<ArrowManager::ArrowType, std::shared_ptr<Arrow>> arrow_map;
	extern std::map<ArrowManager::ArrowType, std::unique_ptr<sf::Texture>> arrow_icons;

	void load_icons();
	void load_icon(ArrowManager::ArrowType type, std::string path);
}
