#pragma once

struct Event_Cache
{
	struct Node
	{
		u2 t;
		Event*e;
	};

	Scene*scene;
	People*people;
	std::deque<Node> eq;
	
	Event_Cache(Scene*scene,People*people);
	~Event_Cache();

	void add(u2 t,Event*event);
	void add(Event*event);
	template<typename T>
	void add(T event) requires std::derived_from<T,Event>;
	void clear();
	void refresh();
	auto begin(){return eq.rbegin();}
	auto end(){return eq.rend();}
};
