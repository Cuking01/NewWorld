#pragma once


struct Speaker_Render_Info
{
	Speaker speaker;
};

struct People_Render_Info
{
	Armature armature;
	Bounding_Box box;
	Dir dir;
};

struct SE_Info
{
	std::string file_name;
	f2 volume;
};

struct Render_Info
{
	std::string background_file;
	std::string prospect_file;
	std::string bgm_file;

	f3 main_hp_lim;
	f3 main_hp;
	
	Vector camera_pos={0,0};
	std::map<u2,People_Render_Info> peoples;
	std::vector<SE_Info> ses;
	std::map<std::string,Speaker_Render_Info> speakers;
	std::string speaker;
	std::string utterance;
	bool dialog_visible=false;
};
