#pragma once

struct Freeze:Move_State
{
	Vector impact_dir;    	//击退方向和速度
	s2 impact_time;			//击退持续时间
	s2 freeze_time;			//僵直持续时间
	
	s2 cnt;					//已经僵直了多少帧
	s2 freeze_combo_cnt;	//连续进入僵直多少次

	void set(Vector impact_dir,s2 impact_time,s2 freeze_time);

	Freeze(Scene*scene,People*people);

	virtual void load();
	virtual void run();
	virtual void unload();

	virtual void be_attack(const Damage&damage,f3 hit_intensity,Vector impact_dir,s2 impact_time,s2 freeze_time);
	virtual void switch_weapon(s2 id);
};
