#pragma once

struct Task_Queue
{
	struct Node
	{
		s2 t;
		Task task;
		s2 operator<(const Node&node) const
		{
			return t>node.t;
		}
	};
	std::priority_queue<Node> q;

	void add(s2 time,const Task&task);
	void run(s2 time);
};
