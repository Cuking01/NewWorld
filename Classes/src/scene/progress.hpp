#pragma once

struct Progress
{
	Scene*scene;
	std::map<u2,Conditional_Task> condition_tasks;
	Progress(Scene*scene);
	void check_condition();
	u2 add_task(Conditional_Task ct);
};
