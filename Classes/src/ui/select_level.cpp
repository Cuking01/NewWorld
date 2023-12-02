#pragma once

bool Select_Level::init()
{
	cocos2d::Scene::init();

	Node* background=Sprite::create("background/select_level.png");
	
	background->setAnchorPoint(Vec2(0,0));
	background->setPosition(0,0);
	background->setLocalZOrder(-1);
	this->addChild(background);

	auto difficulty_menu=Menu::create();

	auto make_difficuty=[difficulty_menu,this](std::string name,Color3B color,s2 enemy_level)
	{
		auto label=Label::createWithTTF(name,"fonts/msyh.ttc",50);

		label->setColor(color);
		auto item=MenuItemLabel::create(label);
		item->setCallback(
			[color, enemy_level, label, this](Ref*)
			{
				for(auto p:difficulties)
					static_cast<Label*>(p->getLabel())->disableEffect();
				label->enableShadow({color.r,color.g,color.b,255},cocos2d::Size(3,-3),1);
				this->enemy_level=enemy_level;
			}
		);
		difficulty_menu->addChild(item);
		return item;
	};

	difficulties.push_back(make_difficuty("手到擒来",{0,255,0},2));
	difficulties.push_back(make_difficuty("势均力敌",{150,150,150},4));
	difficulties.push_back(make_difficuty("有惊无险",{220,220,0},7));
	difficulties.push_back(make_difficuty("千难万险",{255,140,0},12));
	difficulties.push_back(make_difficuty("难过登天",{255,0,0},20));

	static_cast<Label*>(difficulties[0]->getLabel())->enableShadow({0,255,0,255},cocos2d::Size(3,-3),1);
	this->enemy_level=2;

	difficulty_menu->alignItemsHorizontallyWithPadding(70);
	difficulty_menu->setAnchorPoint(Vec2(0,1));
	difficulty_menu->setPosition(1000,1020);
	this->addChild(difficulty_menu);

	auto*level_menu=Menu::create();
	

	auto make_level=[level_menu,this](std::string name,Sprite*exhibition,std::string scene)
	{
		auto*label=Label::createWithTTF(name,"fonts/msyh.ttc",40);

		label->setColor(Color3B(0,0,0));
		auto*item=MenuItemLabel::create(label);
		level_menu->addChild(item);
		item->setCallback(
			[exhibition,scene,this](Ref*)
			{
				for(auto p:exhibitions)
					p->setVisible(false);
				exhibition->setVisible(true);
				if(level_scene==scene)
				{
					auto*fight_scene=Fight::create();
					fight_scene->start(scene,enemy_level);
				}
				else
					level_scene=scene;
			}
		);
		return item;
	};

	auto make_exhibition=[this](std::string file_name)
	{
		auto sprite=Sprite::create(file_name);
		sprite->setAnchorPoint(Vec2(0,0));
		sprite->setPosition(550,180);
		sprite->setVisible(false);
		this->addChild(sprite);

		return sprite;
	};

	exhibitions.push_back(make_exhibition("background/exhibition10.png"));
	levels.push_back(make_level("第一章",exhibitions.back(),"chapter10"));

	exhibitions.push_back(make_exhibition("background/exhibition11.png"));
	levels.push_back(make_level("间章·灯塔",exhibitions.back(),"chapter11"));

	exhibitions.push_back(make_exhibition("background/exhibition20.png"));
	levels.push_back(make_level("第二章",exhibitions.back(),"chapter20"));

	exhibitions.push_back(make_exhibition("background/exhibition21.png"));
	levels.push_back(make_level("间章·前夕",exhibitions.back(),"chapter21"));

	exhibitions.push_back(make_exhibition("background/empty.png"));
	levels.push_back(make_level("未完待续",exhibitions.back(),"empty"));

	exhibitions.push_back(make_exhibition("background/empty.png"));
	levels.push_back(make_level("To be continued",exhibitions.back(),"empty"));

	exhibitions.push_back(make_exhibition("background/empty.png"));
	levels.push_back(make_level("………",exhibitions.back(),"test"));


	level_menu->alignItemsVerticallyWithPadding(40);
	level_menu->setAnchorPoint(Vec2(0,1));
	level_menu->setPosition(230,520);
	this->addChild(level_menu);



	return true;
}
