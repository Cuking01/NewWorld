#pragma once

template<typename T>
struct Trigger{
	std::map<u2,T> events;
	
	void add(u2 key,const T&e);
	T* find(u2 key);
	void erase(u2 key);
	template<typename... Args>
	s2 operator()(Args&&...args);
};
