#pragma once

enum class Dir:u2
{
	left,right
};

struct People:Attributes
{
	Scene* scene;
	s2 阵营;
	Handle handle;

	Event_Cache new_event;
	Event_Cache event_cache;

	Trigger<Task> when_jc;
	Trigger<Task> when_back_to_floor;

	s2 level;
	bool fly;   //是否飞行

	f3 v_y; //纵向速度
	Dir dir; //朝向
	bool up_flag;     //是否按了上键
	bool down_flag;   //是否按了下键
	
	Bounding_Box box;    //相对于pos的包围盒。
	Armature armature;  //骨架
	Vector&pos;

	s2 freeze_protection_trigger_cnt;  //僵直保护参数，连续进入多少次僵直状态才会触发保护
	
	f3 hp;     //当前生命值
	s2 jump_cnt;
	bool alive;  //是否活着
	s2 freeze_protection;  //僵直保护，仅用来控制人物显示效果，实际保护效果由HARD属性的buff提供。
	s2 cant_be_attack;      //不可以被攻击，即无敌


	Skill*skill[people_skill_num];
	Weapon*weapons[people_weapon_num];
	s2 weapon_id; //武器

	Move_State*default_ms;
	Move_State*ms;

	Move_States::Freeze freeze_ms;
	Move_States::Jumping jumping_ms;
	Move_States::Death death_ms;


	People(Scene*scene,const ::Config::People& con,s2 level);
	~People();

	void reduce_hp(f3 damage);

	bool on_floor() const;
	Skill*get_skill(s2 id);
	Weapon* get_weapon();
	void set_weapon(s2 id);

	void set_ms(Move_State*nms);
	
	template<typename MS_T>
	Handle create_effect(Armature armature);

	void erase_effect(u2 key);

	//找到与pos+box相交的敌人。
	std::vector<People*> find_enemy(Bounding_Box box);
	void attack(const std::vector<People*>&enemy,const Damage&damage,f3 hit_intensity,Vector impact_dir,s2 impact_time,s2 freeze_time);
	void attack(const std::vector<People*>&enemy,const Damage&damage);
	void find_and_attack(Bounding_Box box,const Damage&damage,f3 hit_intensity,Vector impact_dir,s2 impact_time,s2 freeze_time);
	void find_and_attack(Bounding_Box box,const Damage&damage);

	void be_attack(const Damage&damage);
	void move(Dir dir);
	void move(Vector dir);
	void displace(Vector dir);
	void jump();

};
