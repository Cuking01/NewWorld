#pragma once



struct KB_Event
{
	static constexpr s2 Down=0;
	static constexpr s2 Up=1;
	cocos2d::EventKeyboard::KeyCode key;
	s2 type;
};

struct KB_Cache
{
	std::vector<KB_Event> events;
};
