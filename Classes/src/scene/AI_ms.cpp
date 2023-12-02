#pragma once

AI_MS::AI_MS(Scene*scene,People*people):
	Move_State(scene,people,-1),
	main(scene->main),
	attack_d(0)
{}

void AI_MS::load()
{
	move_flag=0;
	move_duration=0;
	idle_duration=0;
}

void AI_MS::run()
{
	move_flag=0;

	if(!main)return;
	auto pos=main->pos;


	if(people->fly||people->on_floor())
	{
		if(pos.x<people->pos.x-attack_d+scene->rnd()%50-scene->rnd()%50)
			move(Dir::left);
		else if(pos.x>people->pos.x+attack_d+scene->rnd()%50-scene->rnd()%50)
			move(Dir::right);
	}

	if(people->fly)
	{
		if(pos.y<people->pos.y)
			people->move({0,-3});
		else
			people->move({0,3});
	}

	if(!move_flag)
	{
		move_duration=0;
		idle_duration++;
	}
}

void AI_MS::unload(){}

void AI_MS::move(Dir dir)
{
	if(!move_flag)
	{
		move_flag=1;
		move_duration++;
		idle_duration=0;
		people->move(dir);
	}
}

