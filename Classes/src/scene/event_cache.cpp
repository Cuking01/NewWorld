#pragma once

Event_Cache::Event_Cache(Scene*scene,People*people):
	scene(scene),people(people)
{}

Event_Cache::~Event_Cache(){clear();}

void Event_Cache::add(u2 t,Event*event)
{
	eq.emplace_back(t,event);
}

void Event_Cache::add(Event*event)
{
	add(scene->time,event);
}

template<typename T>
void Event_Cache::add(T event) requires std::derived_from<T,Event>
{
	add(new T(std::move(event)));
}

void Event_Cache::clear()
{
	for(auto [t,e]:eq)
		delete e;
	eq.clear();
}

void Event_Cache::refresh()
{
	while(!eq.empty()&&scene->time-eq.front().t>pre_input_duration)
		eq.pop_front();
}
