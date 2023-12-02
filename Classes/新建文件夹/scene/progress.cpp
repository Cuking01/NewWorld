#pragma once

Progress::Progress(Scene*scene):
	scene(scene)
{}

void Progress::check_condition()
{
	for(auto it=condition_tasks.begin();it!=condition_tasks.end();)
	{
		auto&[key,ct]=*it;
		if(ct.condition())
		{
			ct.task();
			if(ct.once)
				it=condition_tasks.erase(it);
			else it++;
		}
		else it++;
	}
}

u2 Progress::add_task(Conditional_Task ct)
{
	u2 key=scene->gen_id();
	condition_tasks.emplace(std::pair{key,std::move(ct)});
	return key;
}


