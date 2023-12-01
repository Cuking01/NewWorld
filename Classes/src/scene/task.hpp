#pragma once

struct Task
{
	std::function<void()> task;
	void operator()();
};
