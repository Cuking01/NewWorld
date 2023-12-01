#pragma once

Armature& Armature::operator[](std::string key)
{
	auto it=sons.find(std::move(key));
	if(it==sons.end())
		throw std::exception("visit a no exist bone.");
	return it->second;
}

void Armature::insert(std::string key,Armature armature)
{
	sons.emplace(std::move(key),std::move(armature));
}

void Armature::set_opacity(float x)
{
	bone.opacity=x;
	for(auto&[key,armature]:sons)
		armature.set_opacity(x);
}
