#pragma once

struct Jump:Event
{
	f3 interrupt_strength;
	Jump(f3 interrupt_strength=10);
	virtual void apply(People*people);
};
