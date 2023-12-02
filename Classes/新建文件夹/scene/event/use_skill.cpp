#pragma once

Use_Skill::Use_Skill(s2 id,bool down,bool up,s2 time):Event(Event_T::Use_Skill),id(id),down(down),up(up),time(time){}
void Use_Skill::apply(People*people)
{
	people->ms->use_skill(id,down,up);
}
