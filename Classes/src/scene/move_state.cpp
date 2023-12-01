#pragma once

Move_State::Move_State(Scene*scene,People*people,f3 priority)
	:scene(scene),people(people),priority(priority)
{}

Move_State::~Move_State(){}

void Move_State::init(){}
void Move_State::load(){}
void Move_State::run(){}
void Move_State::unload(){}

void Move_State::move(Dir dir)
{
	people->event_cache.add(Events::Move{dir});
}
void Move_State::jump(f3 interrupt_strength)
{
	if(interrupt_strength>=10000)     //Jump Cancel
	{
		people->jump_cnt=0;
		people->when_jc();
		people->jump();
		return;
	}
	if(interrupt_strength-priority<-eps)
	{
		people->event_cache.add(Events::Jump{interrupt_strength});
		return;
	}

	if(people->on_floor())
	{
		people->jump_cnt=0;
		people->jump();
	}
	else if(people->jump_cnt<people->max_jump_cnt())
	{
		people->jump();
	}
}

void Move_State::use_skill(s2 id,bool down,bool up)
{
	Skill*skill=people->get_skill(id);
	if(skill==nullptr||!skill->can_use(down,up)||skill->get_interrupt_strength(down,up)-priority<-eps)
	{
		people->event_cache.add(Events::Use_Skill(id,down,up,scene->time));
		return;
	}
	skill->use(down,up);
}

void Move_State::be_attack(const Damage&damage,f3 hit_intensity,Vector impact_dir,s2 impact_time,s2 freeze_time)
{
	if(hit_intensity-people->HARD()>eps)
	{
		people->freeze_ms.set(impact_dir,impact_time,freeze_time);
		people->set_ms(&people->freeze_ms);
	}
	people->be_attack(damage);
}

void Move_State::switch_weapon(s2 id)
{
	people->event_cache.add(Events::Switch_Weapon{id});
}

namespace Move_States
{

	#include"move_state/general.cpp"
	#include"move_state/freeze.cpp"
	#include"move_state/jumping.cpp"
	#include"move_state/death.cpp"
};


