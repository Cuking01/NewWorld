#pragma once

namespace Bear_Default
{

MS::MS(Scene*scene,People*people):
	AI_MS(scene,people)
{
	attack_d=300;
}

void MS::load()
{
	AI_MS::load();
	fleg=&people->armature["front_leg"].bone;
	bleg=&people->armature["back_leg"].bone;
	farm=&people->armature["front_arm"].bone;
	barm=&people->armature["back_arm"].bone;

}

void MS::run()
{
	if(move_duration)
	{
		if(move_duration%40<20)
		{
			fleg->rotation-=1;
			bleg->rotation+=1;
			farm->rotation-=0.5;
			barm->rotation+=0.5;

		}
		else
		{
			fleg->rotation+=1;
			bleg->rotation-=1;
			farm->rotation+=0.5;
			barm->rotation-=0.5;
		}

	}
	else
	{
		fleg->rotation=0;
		bleg->rotation=0;
		farm->rotation=0;
		barm->rotation=0;
	}
	AI_MS::run();

}
void MS::unload()
{
	fleg->rotation=0;
	bleg->rotation=0;
	farm->rotation=0;
	barm->rotation=0;
	AI_MS::unload();
}



};

void bear_default_init()
{
	ms_table["bear_default"]=
	{
		[](Scene*scene,People*people)->Move_State*
		{
			return new Bear_Default::MS(scene,people);
		}
	};
}


