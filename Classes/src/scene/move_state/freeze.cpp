#pragma once

Freeze::Freeze(Scene*scene,People*people):
	Move_State(scene,people,1000)
{}

void Freeze::set(Vector impact_dir,s2 impact_time,s2 freeze_time)
{
	this->impact_dir=impact_dir;
	this->impact_time=impact_time;
	this->freeze_time=freeze_time;
}

void Freeze::load()
{
	cnt=0;
	freeze_combo_cnt=1;
	people->v_y=0;
	people->armature.bone.rotation=15;
}

void Freeze::run()
{
	cnt++;
	if(cnt<=impact_time)
		people->move(impact_dir*0.01);
	if(cnt==freeze_time)
		people->set_ms(people->default_ms);
}

void Freeze::unload()
{
	people->armature.bone.rotation=0;
}

void Freeze::be_attack(const Damage&damage,f3 hit_intensity,Vector impact_dir,s2 impact_time,s2 freeze_time)
{
	if(hit_intensity-people->HARD()>eps)
	{
		set(impact_dir,impact_time,freeze_time);
		cnt=0;
		people->v_y=0;
		freeze_combo_cnt++;
		if(freeze_combo_cnt==people->freeze_protection_trigger_cnt)
		{
			auto id=people->HARD.add({[](f3,Buff_Helper&bh)->s2{bh.add+=10000;return 0;}});
			people->freeze_protection=true;

			scene->task_q.add(scene->time+200,
				{[handle=people->handle,id]()
				{
					People*people=handle;
					if(people==nullptr)return;
					
					people->HARD.erase(id);
					people->freeze_protection=false;
				}}
			);
			people->armature.bone.opacity=150;
			for (int i = 0;i < 5;i++)
			{
				scene->task_q.add(scene->time+40*(i+1),
					{[handle=people->handle,i]()
					{
						People*people=handle;
						if(people==nullptr)return;
					
						people->armature.bone.opacity=i%2?150:255;
					}}
				);
			}
			
			people->set_ms(people->default_ms);
		}
	}
	people->be_attack(damage);
}

void Freeze::switch_weapon(s2 id)
{
	people->set_weapon(id);
}
