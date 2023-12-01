#pragma once

Controler::Controler(std::string scene_key,s2 level,Node*node):
	node(node)
{
	auto*p=Config::create_scene(std::move(scene_key),level);
	if(p==nullptr)
	{
		throw std::exception("controler start failed.");
		return;
	}


	scene=p;
	using cocos2d::EventListenerKeyboard;
	using cocos2d::EventKeyboard;
	using cocos2d::Event;


	
	
	auto listener=EventListenerKeyboard::create();
	listener->onKeyPressed =
		[this](EventKeyboard::KeyCode keyCode, Event* event)
		{
			kb_event.events.push_back({keyCode,KB_Event::Down });
		};

	listener->onKeyReleased =
		[this](EventKeyboard::KeyCode keyCode, Event* event)
		{
			kb_event.events.push_back({keyCode,KB_Event::Up });
		};

	node->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, node);

	render_info.background_file=scene->background_file;
	render_info.prospect_file=scene->prospect_file;
	render_info.bgm_file=scene->bgm_file;
	prospect_scale=scene->prospect_scale;

	fight_scene=Node::create();
	fight_scene->setAnchorPoint(Vec2(0,0));
	fight_scene->setPosition(-p->camera_pos.x,-p->camera_pos.y);
	node->addChild(fight_scene);

	if(scene->bgm_file!="")
		bgm_id=AudioEngine::play2d(scene->bgm_file);
	else
		bgm_id=-114514;

	background=Sprite::create(scene->background_file+".png");
	background->setAnchorPoint(Vec2(0,0));
	background->setPosition(0,0);
	background->setLocalZOrder(-100);
    fight_scene->addChild(background);

    if(scene->prospect_file!="")
    {
    	prospect=Sprite::create(scene->prospect_file+".png");
		prospect->setAnchorPoint(Vec2(0,0));
		prospect->setPosition(-p->camera_pos.x*prospect_scale,-p->camera_pos.y*prospect_scale);
		prospect->setLocalZOrder(-200);
	    node->addChild(prospect);
    }
    else
    	prospect=nullptr;
    
    render_info.main_hp=-1;
    render_info.main_hp_lim=-1;
    hp_drawnode=DrawNode::create();
    hp_drawnode->setAnchorPoint(Vec2(0,1));
    hp_drawnode->setPosition(100,1030);
	node->addChild(hp_drawnode);

	dialog=Sprite::create("background/dialog.png");
	dialog->setAnchorPoint(Vec2(0,1));
	dialog->setPosition(0,400);
	dialog->setLocalZOrder(10000);
	dialog->setVisible(false);

	node->addChild(dialog);

	// speaker=Label::createWithSystemFont("","Arial",45);
	speaker=Label::createWithTTF("","fonts/msyh.ttc",45);
	speaker->setAnchorPoint(Vec2(0,1));
	speaker->setPosition(75,740);
	speaker->setColor(Color3B(0,0,0));
	dialog->addChild(speaker);

	// content=Label::createWithSystemFont("","Arial",42);
	content=Label::createWithTTF("","fonts/msyh.ttc",42);
	content->setAnchorPoint(Vec2(0,1));
	content->setPosition(100,600);
	content->setLineBreakWithoutSpace(true);
	content->setColor(Color3B(0,0,0));
	content->setWidth(1400);
	dialog->addChild(content);

	

	logi=std::thread([this](){this->scene->start();});

}

void Controler::init()
{
	
}

Node*Controler::create_armature(const Armature& armature)
{
	auto&bone=armature.bone;
	Node*p=Sprite::create(bone.file_name+".png");

	p->setPosition(bone.pos.x,bone.pos.y);
	p->setAnchorPoint(Vec2(bone.anchor.x,bone.anchor.y));
	p->setRotation(bone.rotation);
	p->setLocalZOrder(bone.zorder);
	p->setVisible(bone.visible);
	p->setOpacity(bone.opacity);
	p->setScale(bone.scale.x,bone.scale.y);

	for(auto&[name,armature_s]:armature.sons)
	{
		auto*ch=create_armature(armature_s);
		p->addChild(ch,ch->getLocalZOrder(),name);
	}
	

	return p;
}
void Controler::update_dir(People_Render_Info&now)
{
	auto &tmp=now.armature.bone;
	if(now.dir==Dir::left)
	{
		tmp.scale=tmp.scale.flipped_x();
		tmp.rotation=-tmp.rotation;
	}
}

void Controler::update_bounding_box(DrawNode*node,People_Render_Info&old,People_Render_Info&now)
{
	if(old.box!=now.box)
	{
		node->clear();
		node->drawRect(Vec2(now.box.l.x,now.box.l.y),Vec2(now.box.r.x,now.box.r.y),Color4F(0,0,0,1));
		node->setPosition(0,0);
		node->setVisible(bounding_box_visible);
		old.box=now.box;
	}
}

void Controler::update_bone(Node*node,Bone&old,Bone&now)
{
	if (old.pos!=now.pos)
	{
		node->setPosition(now.pos.x,now.pos.y);
		old.pos=now.pos;
	}
	if(old.anchor!=now.anchor)
	{
		node->setAnchorPoint(Vec2(now.anchor.x,now.anchor.y));
		old.anchor=now.anchor;
	}
	if(old.rotation!=now.rotation)
	{
		node->setRotation(now.rotation);
		old.rotation=now.rotation;
	}
	if(old.zorder!=now.zorder)
	{
		node->setLocalZOrder(now.zorder);
		old.zorder=now.zorder;
	}
	if(old.visible!=now.visible)
	{
		node->setVisible(now.visible);
		old.visible=now.visible;
	}
	if(old.opacity!=now.opacity)
	{
		node->setOpacity(now.opacity);
		old.opacity=now.opacity;
	}
	if(old.scale!=now.scale)
	{
		node->setScale(now.scale.x,now.scale.y);
		old.scale=now.scale;
	}
}

void Controler::update_armature(Node*node,Armature&old,Armature&now)
{
	update_bone(node,old.bone,now.bone);

	auto it1=old.sons.begin();
	auto end1=old.sons.end();

	auto it2=now.sons.begin();
	auto end2=now.sons.end();

	while(it1!=end1&&it2!=end2)
	{
		if(it1->first==it2->first)
		{
			update_armature(
				node->getChildByName(it1->first),
				it1->second,
				it2->second);
			it1++;
			it2++;
		}
		else if(it1->first<it2->first)
		{
			node->removeChildByName(it1->first);
			it1=old.sons.erase(it1);
		}
		else
		{
			auto*ch=create_armature(it2->second);

			node->addChild(ch,ch->getLocalZOrder(),it2->first);
			old.sons.insert(*it2);
			
			it2++;
		}
	}

	while(it1!=end1)
	{
		node->removeChildByName(it1->first);
		it1=old.sons.erase(it1);
	}

	while(it2!=end2)
	{
		auto*ch=create_armature(it2->second);
		node->addChild(ch,ch->getLocalZOrder(),it2->first);
		old.sons.insert(*it2);
		it2++;
	}

}

void Controler::create_speaker(const Speaker&speaker)
{
	auto*p=Sprite::create("dialog/"+speaker.file_name+".png");
	p->setPosition(speaker.pos.x,speaker.pos.y);
	p->setAnchorPoint(Vec2(0,0));
	dialog->addChild(p,-1,speaker.name);

}

void Controler::update_speaker(Node*node,Speaker&old,const Speaker&now)
{
	if(old.pos!=now.pos)
	{
		node->setPosition(now.pos.x,now.pos.y);
		old.pos=now.pos;
	}
	if(old.speak!=now.speak)
	{
		old.speak=now.speak;
	}
	if(old.zorder!=now.zorder)
	{
		node->setLocalZOrder(now.zorder);
		old.zorder=now.zorder;
	}
}

void Controler::update_dialog(Render_Info&now)
{
	auto it1=render_info.speakers.begin();
	auto end1=render_info.speakers.end();

	auto it2=now.speakers.begin();
	auto end2=now.speakers.end();

	while(it1!=end1&&it2!=end2)
	{
		if(it1->first==it2->first)
		{
			auto ch=dialog->getChildByName(it1->first);
			update_speaker(ch,it1->second.speaker,it2->second.speaker);
			it1++;
			it2++;
		}
		else if(it1->first<it2->first)
		{
			dialog->removeChildByName(it1->first);
			it1=render_info.speakers.erase(it1);
		}
		else
		{
			create_speaker(it2->second.speaker);
			render_info.speakers.insert(*it2);
			it2++;
		}
	}

	while(it1!=end1)
	{
		dialog->removeChildByName(it1->first);
		it1=render_info.speakers.erase(it1);
	}

	while(it2!=end2)
	{
		create_speaker(it2->second.speaker);
		render_info.speakers.insert(*it2);
		it2++;
	}

	if(render_info.speaker!=now.speaker)
	{
		speaker->setString(now.speaker);
		render_info.speaker=now.speaker;
	}
	if(render_info.utterance!=now.utterance)
	{
		content->setString("      "+now.utterance);
		render_info.utterance=now.utterance;
	}
	if(render_info.dialog_visible!=now.dialog_visible)
	{
		dialog->setVisible(now.dialog_visible);
		render_info.dialog_visible=now.dialog_visible;
	}
}

void Controler::update_peoples(Render_Info&now)
{
	auto it1=render_info.peoples.begin();
	auto end1=render_info.peoples.end();

	auto it2=now.peoples.begin();
	auto end2=now.peoples.end();

	while(it1!=end1&&it2!=end2)
	{
		if(it1->first==it2->first)
		{
			auto*ch=fight_scene->getChildByTag(it1->first);
			update_dir(it2->second);
			update_armature(ch,it1->second.armature,it2->second.armature);
			update_bounding_box(static_cast<DrawNode*>(fight_scene->getChildByName("bounding_box_"+std::to_string(it1->first))),it1->second,it2->second);
			it1++;
			it2++;
		}
		else if(it1->first<it2->first)
		{
			fight_scene->removeChildByTag(it1->first);
			fight_scene->removeChildByName("bounding_box_"+std::to_string(it1->first));
			it1=render_info.peoples.erase(it1);
		}
		else
		{
			
			update_dir(it2->second);
			auto*ch=create_armature(it2->second.armature);

			auto*drawnode=DrawNode::create();
			drawnode->setAnchorPoint(Vec2(0,0));
			drawnode->setPosition(0,0);
			fight_scene->addChild(drawnode,10000,"bounding_box_"+std::to_string(it2->first));

			render_info.peoples.insert(*it2);
			fight_scene->addChild(ch,ch->getLocalZOrder(),it2->first);
			it2++;
		}
	}

	while(it1!=end1)
	{
		fight_scene->removeChildByTag(it1->first);
		fight_scene->removeChildByName("bounding_box_"+std::to_string(it1->first));
		it1=render_info.peoples.erase(it1);
	}

	while(it2!=end2)
	{
		update_dir(it2->second);
		auto*ch=create_armature(it2->second.armature);

		auto*drawnode=DrawNode::create();
		drawnode->setAnchorPoint(Vec2(0,0));
		drawnode->setPosition(0,0);
		fight_scene->addChild(drawnode,10000,"bounding_box_"+std::to_string(it2->first));

		render_info.peoples.insert(*it2);
		fight_scene->addChild(ch,ch->getLocalZOrder(),it2->first);
		it2++;
	}
}

void Controler::update_camera(Render_Info&now)
{
	if(render_info.camera_pos!=now.camera_pos)
	{
		fight_scene->setPosition(-now.camera_pos.x,-now.camera_pos.y);
		if(prospect)
			prospect->setPosition(-now.camera_pos.x*prospect_scale,-now.camera_pos.y*prospect_scale);
		render_info.camera_pos=now.camera_pos;
	}
}

void Controler::update_hp(Render_Info&now)
{
	auto&old=render_info;
	if(old.main_hp_lim!=now.main_hp_lim||old.main_hp!=now.main_hp)
	{
		f3 hp_lim=now.main_hp_lim;
		f3 hp=now.main_hp;
		if(hp_lim<0)
		{
			hp_drawnode->setVisible(false);
		}
		else
		{
			hp_drawnode->clear();
			hp_drawnode->drawSolidRect(Vec2(-5,-5),Vec2(hp_lim+5,35),Color4F(0,0,0,1));
			hp_drawnode->drawSolidRect(Vec2(0,0),Vec2(hp_lim,30),Color4F(1,1,1,0));
			hp_drawnode->drawSolidRect(Vec2(0,0),Vec2(hp,30),Color4F(1-hp/hp_lim,hp/hp_lim,0,1));
			hp_drawnode->setVisible(true);
			old.main_hp_lim=now.main_hp_lim;
			old.main_hp=now.main_hp;
		}
	}
}

void Controler::update_other(Render_Info&old,Render_Info&now)
{
	if(old.background_file!=now.background_file)
	{
		background->removeFromParent();
		background=Sprite::create(now.background_file+".png");
		background->setAnchorPoint(Vec2(0,0));
		background->setPosition(-old.camera_pos.x,-old.camera_pos.y);
		background->setLocalZOrder(-100);
		fight_scene->addChild(background);
		old.background_file=now.background_file;
	}
	if(old.prospect_file!=now.prospect_file)
	{
		if(prospect)prospect->removeFromParent();
		if(now.prospect_file!="")
		{
			prospect=Sprite::create(now.prospect_file+".png");
			prospect->setAnchorPoint(Vec2(0,0));
			prospect->setPosition(-old.camera_pos.x*prospect_scale,-old.camera_pos.y*prospect_scale);
			prospect->setLocalZOrder(-200);
			node->addChild(prospect);
		}
		else
			prospect=nullptr;
		old.prospect_file=now.prospect_file;
	}
	if(old.bgm_file!=now.bgm_file)
	{
		if(bgm_id!=-114514)AudioEngine::stop(bgm_id);
		if(now.bgm_file!="")
			bgm_id=AudioEngine::play2d(now.bgm_file);
		else
			bgm_id=-114514;
		old.bgm_file=now.bgm_file;
	}


}

void Controler::update_render_info()
{
	Render_Info now;
	scene->get_render_info(now);
	
	update_other(render_info,now);
	update_hp(now);
	update_peoples(now);
	update_dialog(now);
	update_camera(now);
	
	using audio=cocos2d::experimental::AudioEngine;
	audio::lazyInit();
	for(auto& [file_name,volume]:now.ses)
		audio::play2d(file_name.c_str(),false,volume);
}

void Controler::update_kb_event()
{
	scene->recv_kb_event(kb_event);
	kb_event.events.clear();
}

void Controler::run()
{
	update_render_info();
	update_kb_event();

	if(scene->end_flag)
	{
		if(scene->end_flag==100)
		{
			node->unschedule("fight_rend");
			Director::getInstance()->popScene();
			scene->end_flag++;
			logi.join();
			delete this;
			return;
		}
		scene->end_flag++;
	}
}
