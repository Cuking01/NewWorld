#pragma once

struct Be_Attack:Event
{
	Damage damage;
	f3 hit_intensity;
	Vector impact_dir;
	s2 impact_time;
	s2 freeze_time;

	Be_Attack(Damage damage,f3 hit_intensity,Vector impact_dir,s2 impact_time,s2 freeze_time);
	virtual void apply(People*people);
};
