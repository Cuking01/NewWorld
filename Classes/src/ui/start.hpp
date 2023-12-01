#pragma once

struct Start: cocos2d::Scene
{
	cocos2d::Scene*select_level;
	cocos2d::Scene*prepare;
	cocos2d::Scene*help;
	
	virtual bool init();
	
	CREATE_FUNC(Start);
};
