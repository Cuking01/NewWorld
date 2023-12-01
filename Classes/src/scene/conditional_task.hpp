#pragma once

struct Conditional_Task
{
	bool once=true;
	std::function<bool()> condition;
	std::function<void()> task;
};


