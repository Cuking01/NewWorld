#pragma once

enum class KB_Dir:u2
{
	left,right,mid
};

struct Scene_State
{
	void (Scene::*load)();
	void (Scene::*run)();
	void (Scene::*unload)();
};

struct Scene
{
	std::string background_file;
	std::string prospect_file;
	std::string bgm_file;

	f3 prospect_scale;

	std::atomic<s2> end_flag=0;

	KB_Dir kb_dir; // 键盘按键方式
	
	bool left_arrow,right_arrow,up_arrow,down_arrow;
	Vector camera_min,camera_max;
	Vector camera_to,camera_offset;
	Vector camera_pos;

	Vector people_min,people_max;

	s2 time;    //只有fight_run里会自增，代表战斗时间
	s2 tick;    //每帧自增1

	u2 id_cnt;
	std::mt19937_64 rnd;

	std::map<u2,People*> peoples;
	People*main;
	
	Progress*progress;

	Task_Queue task_q;
	Task_Queue task_q_tick;

	Trigger<Task> every_frame;

	Render_Info render_info;
	std::mutex render_info_mutex;

	KB_Cache kb_event;
	std::mutex kb_event_mutex;

	Scene_State fight_ss;
	Scene_State	dialog_ss;
	Scene_State	pause_ss;

	Scene_State*ss;

	std::string dialog_file="10";
	Dialog dialog;

	std::function<void()> function_key;

	s2 pause_duration;
	Scene_State*last_ss;
	std::vector<u2> to_erase;

	Scene();
	~Scene();

	u2 gen_id();

	Handle create_people(std::string people_key,s2 level);
	void erase_people(u2 key);
	void clear_to_erase();

	void prepare_render_info();
	void get_render_info(Render_Info&reciver);

	void recv_kb_event(KB_Cache&new_kb);
	void deal_kb_event();

	void deal_dialog();
	//找到不处于此阵营的，与包围盒相交的，且cant_be_attack为0的
	std::vector<People*> find_people(Bounding_Box box,s2 阵营);

	void update_camera();
	void shake(s2 duration,s2 strength=25);
	void play_se(std::string file_name,u2 overlay);
	void start();
	void end();
	void pause();
	void pause_for(s2 duration);


	void fight_load();
	void fight_run();
	void fight_unload();

	void dialog_load();
	void dialog_run();
	void dialog_unload();

	void pause_load();
	void pause_run();
	void pause_unload();

	void set_ss(Scene_State*p);
	

};

