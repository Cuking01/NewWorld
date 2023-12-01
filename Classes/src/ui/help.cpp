#pragma once


bool Help::init()
{
	cocos2d::Scene::init();
	auto*background=Sprite::create("background/help.png");
	background->setAnchorPoint(Vec2(0,0));
	background->setPosition(0,0);
	background->setLocalZOrder(1);
	this->addChild(background);

	auto mouseListener = cocos2d::EventListenerMouse::create();
	mouseListener->onMouseDown=[](cocos2d::Event*){Director::getInstance()->popScene();};

	background->getEventDispatcher()->addEventListenerWithSceneGraphPriority(mouseListener,background);
	return true;
}

