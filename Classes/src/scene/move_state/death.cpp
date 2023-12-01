#pragma once

Death::Death(Scene*scene,People*people):Move_State(scene,people){}
void Death::load()
{
	cnt=0;
	auto d=people->box.r-people->box.l;
	box_dy=d.y-d.x;
}
void Death::run()
{
	cnt++;
	if(cnt<=100)
	{
		people->armature.bone.rotation-=0.9;
		people->box.l.y+=box_dy*0.005;
		people->box.r.y+=box_dy*0.005;
	}
	
	if(cnt==150&&people!=scene->main)
	{
		scene->erase_people(people->handle);
	}
}
void Death::move(Dir){}
void Death::jump(f3){}
void Death::use_skill(s2,bool down,bool up){}
void Death::be_attack(const Damage&,f3,Vector,s2,s2){}
void Death::switch_weapon(s2){}

