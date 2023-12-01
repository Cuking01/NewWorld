#pragma once

General::General(Scene*scene,People*people):
	Move_State(scene,people,-1),
	fuleg(people->armature["front_upper_leg"].bone),
	buleg(people->armature["back_upper_leg"].bone),
	flleg(people->armature["front_upper_leg"]["front_lower_leg"].bone),
	blleg(people->armature["back_upper_leg"]["back_lower_leg"].bone),
	fuarm(people->armature["front_upper_arm"].bone),
	buarm(people->armature["back_upper_arm"].bone)
{}

void General::load()
{
	move_duration=0;
	idle_duration=0;
	move_flag=0;
	jump_skill_flag=0;
	switch_weapon_flag=0;
	buarm.rotation-=15;

}

void General::run()
{
	Event* jump_skill=nullptr;
	jump_skill_flag=0;
	Skill*skill=nullptr;
	for(auto [t,e]:people->event_cache)
	{
		if(e->type==Event_T::Jump||e->type==Event_T::Use_Skill)
		{
			if(jump_skill_flag==0)
			{
				jump_skill_flag=1;
				jump_skill=e;
			}
		}
		else if(jump_skill_flag)
		{
			e->apply(people);
		}
	}

	if(jump_skill_flag)
	{
		if(jump_skill->type==Event_T::Use_Skill)
		{
			auto*se=dynamic_cast<Events::Use_Skill*>(jump_skill);
			skill=people->get_skill(se->id);
			if(skill==nullptr||scene->time-se->time>pre_input_duration)
			{
				people->event_cache.clear();
				return;
			}
			if(!skill->can_use(se->down,se->up)||skill->get_interrupt_strength(se->down,se->up)-priority<-eps)
			{
				auto event=*se;
				people->event_cache.clear();
				people->event_cache.add(event);
			}
			else
			{
				skill->use(se->down,se->up);
				people->event_cache.clear();
			}
		}
		else
		{
			jump_skill->apply(people);
			people->event_cache.clear();
		}
		return;
	}

	for(auto [t,e]:people->event_cache)
		e->apply(people);

	if(!move_flag)
	{
		move_duration=0;
		idle_duration++;
	}

	if(move_flag)
	{
		if((move_duration/20)%2==0)
		{
			fuleg.rotation-=2.25;
			buleg.rotation+=2.25;
			fuarm.rotation+=0.2;
			buarm.rotation+=1.2;
		}
		else
		{
			fuleg.rotation+=2.25;
			buleg.rotation-=2.25;
			fuarm.rotation-=0.2;
			buarm.rotation-=1.2;
		}
		
	}
	else
	{
		fuleg.rotation=0;
		buleg.rotation=0;
		fuarm.rotation=0;
		buarm.rotation=-15;
	}

	move_flag=0;
	switch_weapon_flag=0;
	people->event_cache.clear();
}

void General::unload()
{
	fuleg.rotation=0;
	buleg.rotation=0;
	fuarm.rotation=0;
	buarm.rotation=0;
	people->event_cache.clear();
}

void General::move(Dir dir)
{
	if(!move_flag)
	{
		move_flag=1;
		move_duration++;
		idle_duration=0;
		people->move(dir);
	}
}

void General::use_skill(s2 id,bool down,bool up)
{
	Skill*skill=people->get_skill(id);
	if(skill==nullptr)return;
	if(!skill->can_use(down,up)||skill->get_interrupt_strength(down,up)-priority<-eps)
	{
		people->event_cache.add(Events::Use_Skill{id,down,up,scene->time});
		return;
	}
	skill->use(down,up);
}

void General::switch_weapon(s2 id)
{
	if(!switch_weapon_flag)
	{
		switch_weapon_flag=1;
		people->set_weapon(id);
	}
}

