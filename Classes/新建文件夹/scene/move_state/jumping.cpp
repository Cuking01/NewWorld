#pragma once

Jumping::Jumping(Scene*scene,People*people):
	Move_State(scene,people,100)
{}

void Jumping::load(){cnt=0;}
void Jumping::run()
{
	cnt++;
	if(cnt==5)
		people->set_ms(people->default_ms);
}

void Jumping::move(Dir dir)
{
	people->move(dir);
}

void Jumping::jump(f3 interrupt_strength)
{
	if(interrupt_strength>=10000)
	{
		people->jump_cnt=0;
		people->when_jc();
	}
	else if(people->jump_cnt<people->max_jump_cnt());
	else return;
	people->jump();
	cnt=0;
}

void Jumping::switch_weapon(s2 id)
{
	people->set_weapon(id);
}
