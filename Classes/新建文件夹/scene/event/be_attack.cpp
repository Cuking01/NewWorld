#pragma once

Be_Attack::Be_Attack(Damage damage,f3 hit_intensity,Vector impact_dir,s2 impact_time,s2 freeze_time):
	Event(Event_T::Be_Attack),
	damage(std::move(damage)),
	hit_intensity(hit_intensity),
	impact_dir(impact_dir),
	impact_time(impact_time),
	freeze_time(freeze_time)
{};

void Be_Attack::apply(People*people)
{
	people->ms->be_attack(damage,hit_intensity,impact_dir,impact_time,freeze_time);
}
