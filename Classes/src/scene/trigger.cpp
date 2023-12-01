#pragma once

template<typename T>
void Trigger<T>::add(u2 key,const T&e)
{
	events[key]=e;
}

template<typename T>
T* Trigger<T>::find(u2 key)
{
	if(auto it=events.find(key);it!=events.end())
		return &it->second;
	return nullptr;
}

template<typename T>
void Trigger<T>::erase(u2 key)
{
	events.erase(key);
}

template<typename T>
template<typename...Args>
s2 Trigger<T>::operator()(Args&&...args)
{
	for(auto&[k,v]:events)
	{
		if constexpr(std::is_same_v<decltype(v(std::forward<Args&&>(args)...)),void>)
		{
			v(std::forward<Args&&>(args)...);
		}
		else
		{
			if(s2 ret=v(std::forward<Args&&>(args)...);ret)
				return ret;
		}
		
	}
	return 0;
}

