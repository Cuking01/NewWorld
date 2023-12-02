#pragma once

Handle::operator People* () const
{
	auto it=scene->peoples.find(key);
	if(it==scene->peoples.end())
		return nullptr;
	return it->second;
}

Handle::operator u2 () const
{
	return key;
}
