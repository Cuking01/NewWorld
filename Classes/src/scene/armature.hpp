#pragma once

struct Bone
{
	std::string name;
	std::string file_name;
	
	Vector anchor;
	Vector pos;
	s2 zorder=0;
	float rotation=0;
	s2 visible=true;
	float opacity=255;
	Vector scale={1.0,1.0};
};

struct Armature
{
	Bone bone;
	
	std::map<std::string,Armature> sons;

	Armature& operator[](std::string key);
	void insert(std::string key,Armature armature);
	void set_opacity(float x);
};
