#pragma once

Redlizard_Default_MS::Redlizard_Default_MS(Scene*scene,People*people):
	AI_MS(scene,people)
{
	attack_d=900;
}

void Redlizard_Default_MS::load()
{
	AI_MS::load();
	fleg=&people->armature["front_upper_leg"].bone;
	bleg=&people->armature["back_upper_leg"].bone;
	farm=&people->armature["front_upper_arm"].bone;
	barm=&people->armature["back_upper_arm"].bone;
	
	strategy=-1;
	scnt=0;
}

void Redlizard_Default_MS::run()
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

	if(scnt>=100)strategy=-1;
	if(strategy==-1)
	{
		strategy=scene->rnd()%3;
		scnt=0;
	}
	scnt++;

	if(strategy==0)
	{
		AI_MS::run();
	}
	else
	{
		use_skill(0,false,false);
		strategy=-1;
	}
}

void Redlizard_Default_MS::unload()
{
	fleg->rotation=0;
	bleg->rotation=0;
	farm->rotation=0;
	barm->rotation=0;
	AI_MS::unload();
}


void redlizard_default_init()
{
	ms_table["redlizard_default"]=
	{
		[](Scene*scene,People*people)->Move_State*
		{
			return new Redlizard_Default_MS(scene,people);
		}
	};
}


