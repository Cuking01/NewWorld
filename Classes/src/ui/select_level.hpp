#pragma once

struct Select_Level: cocos2d::Scene
{
	s2 enemy_level;
	std::string level_scene;
	std::vector<Sprite*>exhibitions;
	std::vector<MenuItemLabel*>levels;
	std::vector<MenuItemLabel*>difficulties;

	virtual bool init();
	
	CREATE_FUNC(Select_Level);
};
