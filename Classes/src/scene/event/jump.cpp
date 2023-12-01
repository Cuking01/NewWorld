#pragma once

Jump::Jump(f3 interrupt_strength):
	Event(Event_T::Jump),interrupt_strength(interrupt_strength)
{}

void Jump::apply(People*people)
{
	people->ms->jump(interrupt_strength);
}
