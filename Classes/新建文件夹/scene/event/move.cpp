#pragma once

Move::Move(Dir dir):Event(Event_T::Move),dir(dir){};
void Move::apply(People*people)
{
	people->ms->move(dir);
}
