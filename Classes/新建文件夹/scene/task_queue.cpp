#pragma once

void Task_Queue::add(s2 time,const Task&task)
{
	q.push({time,task});
}

void Task_Queue::run(s2 time)
{
	while(!q.empty()&&q.top().t<=time)
	{
		auto task=q.top().task;
		q.pop();
		task();
	}
}
