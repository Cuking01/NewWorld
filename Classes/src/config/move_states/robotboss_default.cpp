#pragma once

Robotboss_Default_MS::Robotboss_Default_MS(Scene*scene,People*people):
	AI_MS(scene,people)
{
	attack_d=200;
}

void Robotboss_Default_MS::load()
{
	AI_MS::load();
	strategy=-1;
	scnt=0;
	uarm = &people->armature["front_upper_arm"].bone;
	larm = &people->armature["front_upper_arm"]["front_lower_arm"].bone;
	uarm->rotation = 30;
}

void Robotboss_Default_MS::run()
{
	if (scnt>=1&&scnt<=30)
	{
		uarm->rotation -= 2;
	}
	if (scnt>=51&&scnt<=80)
	{
		uarm->rotation += 2;
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

void Robotboss_Default_MS::unload()
{
	AI_MS::unload();
}


void robotboss_default_init()
{
	ms_table["robotboss_default"]=
	{
		[](Scene*scene,People*people)->Move_State*
		{
			return new Robotboss_Default_MS(scene,people);
		}
	};
}


