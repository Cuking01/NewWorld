#pragma once


Scene::Scene():
	kb_dir(KB_Dir::mid),
	left_arrow(false),
	right_arrow(false),
	up_arrow(false),
	down_arrow(false),
	camera_min(-100,-100),
	camera_max(100,100),
	camera_to(100,60),
	camera_offset(0,0),
	camera_pos(100,60),
	people_min(0,ground_y),
	people_max(1920,1200),
	time(0),
	tick(0),
	id_cnt(0),
	rnd(0),
	main(nullptr),
	progress(nullptr),
	fight_ss(&Scene::fight_load,&Scene::fight_run,&Scene::fight_unload),
	dialog_ss(&Scene::dialog_load,&Scene::dialog_run,&Scene::dialog_unload),
	pause_ss(&Scene::pause_load,&Scene::pause_run,&Scene::pause_unload),

	ss(nullptr)
{}

Scene::~Scene()
{
	delete progress;
	for(auto [key,p]:peoples)
		delete p;
	peoples.clear();
}

u2 Scene::gen_id()
{
	return id_cnt++;
}

Handle Scene::create_people(std::string people_key,s2 level)
{
	u2 key=gen_id();
	People*people=Config::create_people(people_key,this,level);
	people->handle=Handle{this,key};
	if(key==0)main=people;

	peoples.insert({key,people});
	return Handle{this,key};
}

Handle Scene::create_people(std::string people_key)
{
	return create_people(std::move(people_key),enemy_level);
}

void Scene::erase_people(u2 key)
{
	to_erase.push_back(key);
}

void Scene::clear_to_erase()
{
	for(auto key:to_erase)
	{
		auto it=peoples.find(key);
		if(it==peoples.end())return;
		delete it->second;
		peoples.erase(it);
	}
	to_erase.clear();
}

void Scene::prepare_render_info()
{
	std::lock_guard lock(render_info_mutex);

	render_info.background_file=background_file;
	render_info.prospect_file=prospect_file;
	render_info.bgm_file=bgm_file;

	render_info.main_hp_lim=main&&main->alive?main->HP_lim():-1;
	render_info.main_hp=main&&main->alive?main->hp:-1;

	render_info.camera_pos=camera_pos+camera_offset;

	render_info.peoples.clear();
	for(auto& [key,people]:peoples)
		render_info.peoples.insert({key,{people->armature,people->box+people->pos,people->dir}});
	if (ss==&dialog_ss)
	{
		render_info.speaker=dialog.speaker;
		render_info.utterance=dialog.utterance;
		render_info.speakers.clear();
		for(auto& [key,speaker]:dialog.speakers)
			render_info.speakers.insert({key,{speaker}});
	}
	
	render_info.dialog_visible=ss==&dialog_ss;
}

void Scene::get_render_info(Render_Info&reciver)
{
	std::lock_guard lock(render_info_mutex);

	reciver=render_info;
	render_info.ses.clear();
}

void Scene::recv_kb_event(KB_Cache&new_kb)
{
	std::lock_guard lock(kb_event_mutex);
	kb_event.events.insert(kb_event.events.end(),new_kb.events.begin(),new_kb.events.end());

}

void Scene::deal_dialog()
{
	if(ss!=&dialog_ss)
	{
		set_ss(&dialog_ss);
		return;
	}

	if(!dialog.deal())
	{
		set_ss(&fight_ss);
	}
}

void Scene::deal_kb_event()
{
	kb_event_mutex.lock();
	auto tmp=std::move(kb_event);
	kb_event_mutex.unlock();

	if(main==nullptr)return;

	using KC=cocos2d::EventKeyboard::KeyCode;

	for(auto [key,type]:tmp.events)
	{
		if(type==KB_Event::Down)
		{
			if(key==KC::KEY_CAPITAL_F||key==KC::KEY_F)
				if(function_key)function_key();
			if(key==KC::KEY_CAPITAL_T||key==KC::KEY_T)
				deal_dialog();
			if(key==KC::KEY_LEFT_ARROW)
				left_arrow=true;
			if(key==KC::KEY_RIGHT_ARROW)
				right_arrow=true;
			if(key==KC::KEY_UP_ARROW)
				up_arrow=true;
			if(key==KC::KEY_DOWN_ARROW)
				down_arrow=true;

			if(key==KC::KEY_CAPITAL_D||key==KC::KEY_D)
				kb_dir=KB_Dir::right;
			if(key==KC::KEY_CAPITAL_A||key==KC::KEY_A)
				kb_dir=KB_Dir::left;
			if(key==KC::KEY_CAPITAL_W||key==KC::KEY_W)
				if(main)main->up_flag=true;
			if(key==KC::KEY_CAPITAL_S||key==KC::KEY_S)
				if(main)main->down_flag=true;
			if(key==KC::KEY_CAPITAL_K||key==KC::KEY_K)
				if(main)
					main->new_event.add(!main->on_floor()&&main->find_enemy({main->box.l,{main->box.r.x,main->box.l.y+10}}).size()?Events::Jump(2e4):Events::Jump{});
			if(key==KC::KEY_1)
				if(main)main->new_event.add(Events::Switch_Weapon{0});
			if(key==KC::KEY_2)
				if(main)main->new_event.add(Events::Switch_Weapon{1});
			if(key==KC::KEY_3)
				if(main)main->new_event.add(Events::Switch_Weapon{2});
			if(key==KC::KEY_4)
				if(main)main->new_event.add(Events::Switch_Weapon{3});
			if(key==KC::KEY_5)
				if(main)main->new_event.add(Events::Switch_Weapon{4});
			if(key==KC::KEY_CAPITAL_J||key==KC::KEY_J)
				if(main)main->new_event.add(Events::Use_Skill{people_skill_num+0,main->down_flag,main->up_flag,time});
			if(key==KC::KEY_CAPITAL_H||key==KC::KEY_H)
				if(main)main->new_event.add(Events::Use_Skill{people_skill_num+1,main->down_flag,main->up_flag,time});
			if(key==KC::KEY_CAPITAL_U||key==KC::KEY_U)
				if(main)main->new_event.add(Events::Use_Skill{people_skill_num+2,main->down_flag,main->up_flag,time});
			if(key==KC::KEY_CAPITAL_I||key==KC::KEY_I)
				if(main)main->new_event.add(Events::Use_Skill{people_skill_num+3,main->down_flag,main->up_flag,time});
			if(key==KC::KEY_CAPITAL_O||key==KC::KEY_O)
				if(main)main->new_event.add(Events::Use_Skill{people_skill_num+4,main->down_flag,main->up_flag,time});
			if(key==KC::KEY_CAPITAL_E||key==KC::KEY_E)
				if(main)main->new_event.add(Events::Use_Skill{0,main->down_flag,main->up_flag,time});
			if(key==KC::KEY_CAPITAL_L||key==KC::KEY_L)
				if(main)main->new_event.add(Events::Use_Skill{1,main->down_flag,main->up_flag,time});
			
		}
		else
		{
			if(key==KC::KEY_LEFT_ARROW)
				left_arrow=false;
			if(key==KC::KEY_RIGHT_ARROW)
				right_arrow=false;
			if(key==KC::KEY_UP_ARROW)
				up_arrow=false;
			if(key==KC::KEY_DOWN_ARROW)
				down_arrow=false;
			if(key==KC::KEY_CAPITAL_D||key==KC::KEY_D)
				if(kb_dir==KB_Dir::right)
					kb_dir=KB_Dir::mid;
			if(key==KC::KEY_CAPITAL_A||key==KC::KEY_A)
				if(kb_dir==KB_Dir::left)
					kb_dir=KB_Dir::mid;
			if(key==KC::KEY_CAPITAL_W||key==KC::KEY_W)
				if(main)main->up_flag=false;
			if(key==KC::KEY_CAPITAL_S||key==KC::KEY_S)
				if(main)main->down_flag=false;
		}
	}
}

std::vector<People*> Scene::find_people(Bounding_Box box,s2 阵营)
{
	std::vector<People*> tmp;

	for(auto [key,people]:peoples)
	{
		bool a=has_intersection(people->pos+(people->dir==Dir::left?people->box.flipped_x():people->box), box);
		bool b=people->阵营!=阵营;
		bool c=!people->cant_be_attack;
		bool d=people->alive;
		if (a&&b&&c&&d)
			tmp.push_back(people);
	}

	return tmp;
}

void Scene::update_camera()
{
	if(left_arrow)camera_to.x-=0.8;
	if(right_arrow)camera_to.x+=0.8;
	if(up_arrow)camera_to.y+=0.8;
	if(down_arrow)camera_to.y-=0.8;

	camera_to.x=std::max(camera_to.x,camera_min.x);
	camera_to.y=std::max(camera_to.y,camera_min.y);
	camera_to.x=std::min(camera_to.x,camera_max.x);
	camera_to.y=std::min(camera_to.y,camera_max.y);

	auto to_val=[](f3&x,f3 t)
	{
		f3 dis=std::fabs(x-t);
		if(dis<1)
		{
			x=t;
			return;
		}
		f3 d=dis*0.02;
		if(d<1)d=1;
		if(d>10)d=20;
		if(x<t)x+=d;
		else x-=d;
	};

	to_val(camera_pos.x,camera_to.x);
	to_val(camera_pos.y,camera_to.y);
}

void Scene::shake(s2 duration,s2 strength)
{
	for(s2 i=1;i<=duration;i+=6)
	{
		task_q_tick.add(tick+i,
		{
			[this,strength]()
			{
				double x=(double)(rnd()%(strength*2+1))-strength;
				double y=(double)(rnd()%(strength*2+1))-strength;
				camera_offset={x,y};
			}
		});
	}
	task_q_tick.add(tick+duration+1,
	{
		[this](){camera_offset={0,0};}
	});
}

void Scene::play_se(std::string file_name,u2 overlay)
{
	if(overlay==0)return;
	f2 volume;
	if(overlay==1)volume=0.4;
	else if(overlay==2)volume=0.7;
	else volume=1;

	std::lock_guard lock(render_info_mutex);
	render_info.ses.push_back({file_name,volume});
}

void Scene::start()
{
	set_ss(&fight_ss);
	auto start=std::chrono::steady_clock::now();

	while(end_flag<=100)
	{
		auto now=std::chrono::steady_clock::now();
		if(now<tick*10ms+start)
		{
			std::this_thread::sleep_for(1ms);
			continue;
		}

		tick++;

		task_q_tick.run(tick);

		prepare_render_info();
		deal_kb_event();
		update_camera();

		if(kb_dir==KB_Dir::left)
			if(main)main->new_event.add(Events::Move(Dir::left));
		if(kb_dir==KB_Dir::right)
			if(main)main->new_event.add(Events::Move(Dir::right));

		(this->*(ss->run))();

	}

	delete this;
}

void Scene::end()
{
	end_flag=1;
}

void Scene::pause()
{
	pause_for(1000000000);
}


void Scene::pause_for(s2 duration)
{
	pause_duration=duration;
	last_ss=ss;
	set_ss(&pause_ss);
}

void Scene::fight_load()
{

}

void Scene::fight_run()
{
	time++;
	every_frame();
	progress->check_condition();
	task_q.run(time);

	for(auto [key,people]:peoples)
	{
		//处理新事件
		people->event_cache.refresh();
		for(auto [t,e]:people->new_event)
			e->apply(people);
		people->new_event.clear();

		if(people->on_floor())
			people->jump_cnt=0;

		//处理纵向速度
		if(people->fly)
			people->v_y=0;
		else if(!people->on_floor())
			people->v_y-=6.7;
		people->move({0.0,people->v_y*0.01});
		
		people->ms->run();
	}
	
	clear_to_erase();
	if(main->pos.x+main->box.r.x>camera_to.x+1800)
		camera_to.x=main->pos.x+main->box.r.x-1800;
	if(main->pos.x+main->box.l.x<camera_to.x+120)
		camera_to.x=main->pos.x+main->box.l.x-120;
	if(main->pos.y+main->box.r.y>camera_to.y+1000)
		camera_to.y=main->pos.y+main->box.r.y-1000;
	if(main->pos.y+main->box.l.y<camera_to.y)
		camera_to.y=main->pos.y+main->box.l.y;
}

void Scene::fight_unload()
{

}
void Scene::dialog_load()
{
	if(dialog_file=="")
	{
		set_ss(&fight_ss);
		return;
	}
	dialog.load("dialog/"+dialog_file+".txt");
}

void Scene::dialog_run()
{
	if(tick%6==0)
		dialog.next_s();
}

void Scene::dialog_unload()
{

}

void Scene::pause_load()
{

}

void Scene::pause_run()
{
	pause_duration--;
	if(pause_duration<=0)
		ss=last_ss;
}

void Scene::pause_unload()
{

}

void Scene::set_ss(Scene_State*p)
{
	if(p==ss)return;
	if(ss)(this->*(ss->unload))();

	ss=p;
	(this->*(ss->load))();
}
