#pragma once

Switch_Weapon::Switch_Weapon(s2 id):Event(Event_T::Switch_Weapon),id(id){};
void Switch_Weapon::apply(People*people)
{
	people->ms->switch_weapon(id);
}
