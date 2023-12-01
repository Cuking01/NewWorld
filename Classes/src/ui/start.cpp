#pragma once

bool Start::init()
{
	cocos2d::Scene::init();
	::Config::init();
	select_level=Select_Level::create();
	select_level->retain();

	help=Help::create();
	help->retain();

	Node* background=Sprite::create("background/start.png");
	
	background->setAnchorPoint(Vec2(0,0));
	background->setPosition(0,0);
	background->setLocalZOrder(-1);
	this->addChild(background);

	auto menu=Menu::create();
	menu->setAnchorPoint(Vec2(0.5,0.5));
	menu->setPosition(960,300);

	

	// auto label1=Label::createWithSystemFont("开始","Arial",80);
	auto label1=Label::createWithTTF("开始","fonts/msyh.ttc",80);
	label1->setColor(Color3B(0,0,0));
	auto item1=MenuItemLabel::create(label1);
	item1->setCallback([this](Ref*){Director::getInstance()->pushScene(select_level);});

	auto label2=Label::createWithTTF(" ","fonts/msyh.ttc",80);
	label2->setColor(Color3B(0,0,0));
	auto item2=MenuItemLabel::create(label2);
	

	// auto label3=Label::createWithSystemFont("帮助","Arial",80);
	auto label3=Label::createWithTTF("帮助","fonts/msyh.ttc",80);
	label3->setColor(Color3B(0,0,0));
	auto item3=MenuItemLabel::create(label3);
	item3->setCallback(
		[this](Ref*) {
			Director::getInstance()->pushScene(help);
		});

	menu->addChild(item1);
	menu->addChild(item2);
	menu->addChild(item3);
	
	menu->alignItemsVerticallyWithPadding(30);
	this->addChild(menu);
	return true;
}
