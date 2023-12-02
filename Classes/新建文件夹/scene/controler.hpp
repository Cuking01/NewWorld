#pragma once



struct Controler
{
	Render_Info render_info;
	KB_Cache kb_event;

	Scene*scene;

	Node*node;
	Node*fight_scene;

	Sprite*background;
	Sprite*prospect;
	
	Node*dialog;
	Label*speaker;
	Label*content;

	DrawNode*hp_drawnode;

	int bgm_id;

	f3 prospect_scale;

	std::thread logi;

	Controler(std::string scene_key,s2 level,Node*node);

	void init();
	Node*create_armature(const Armature& armature);
	void update_dir(People_Render_Info&now);
	void update_bounding_box(DrawNode*node,People_Render_Info&old,People_Render_Info&now);
	void update_bone(Node*node,Bone&old,Bone&now);
	void update_armature(Node*node,Armature&old,Armature&now);
	void create_speaker(const Speaker& speaker);
	void update_speaker(Node* node,Speaker&old,const Speaker&now);
	void update_dialog(Render_Info&now);
	void update_peoples(Render_Info&now);
	void update_camera(Render_Info& now);
	void update_hp(Render_Info&now);
	void update_other(Render_Info&old,Render_Info&now);
	void update_render_info();
	void update_kb_event();
	void run();
	
};
