#pragma once


struct Clipping_Rectangle: cocos2d::ClippingNode
{
	static Clipping_Rectangle* create(s2 w,s2 h);
	virtual void init();
};
