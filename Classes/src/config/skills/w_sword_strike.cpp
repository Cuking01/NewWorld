#pragma once

W_Sword_Strike_MS::W_Sword_Strike_MS(Scene* scene, People* people):
	Move_State(scene, people, 100)
{}

void W_Sword_Strike_MS::load()
{
	cnt = 0;
	uarm = &people->armature["front_upper_arm"].bone;
	larm = &people->armature["front_upper_arm"]["front_lower_arm"].bone;
	wp = &people->armature["front_upper_arm"]["front_lower_arm"]["sword"].bone;
	body = &people->armature.bone;
	blarm = &people->armature["back_upper_arm"].bone;
	fuleg = &people->armature["front_upper_leg"].bone;
	flleg = &people->armature["front_upper_leg"]["front_lower_leg"].bone;
	buleg = &people->armature["back_upper_leg"].bone;
	blleg = &people->armature["back_upper_leg"]["back_lower_leg"].bone;
}

void W_Sword_Strike_MS::run()
{
	cnt++;
	auto enermies = people->find_enemy({ {50,-100},{150,100} });
	if (enermies.size())
	{
		people->attack(std::move(enermies), Damage(people->ATK() * 1.0), 200, { 200,0 }, 25, 50);
		people->set_ms(people->default_ms);
	}
	people->displace({ 30,0 });
	if (cnt == 20)
	{
		people->set_ms(people->default_ms);
	}
}

void W_Sword_Strike_MS::unload()
{
	uarm->rotation = 0;
	larm->rotation = 0;
	wp->rotation = 0;
	wp->scale = { 1,1 };
	body->rotation = 0;
	blarm->rotation = 0;
	fuleg->rotation = 0;
	flleg->rotation = 0;
	buleg->rotation = 0;
	blleg->rotation = 0;
}

W_Sword_Strike::W_Sword_Strike(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con) :
	Skill(scene, people, weapon, con),
	ms(scene, people)
{}

void W_Sword_Strike::use(bool down,bool up)
{
	people->set_ms(&ms);
}

void w_sword_strike_init()
{
	Config::Skill skill
	{
		.name = L"",
		.creator = [](const Config::Skill& con,Scene* scene,People* people,Weapon* weapon)->Skill*
		{
			return new W_Sword_Strike(scene,people,weapon,con);
		}
	};

	skill_table["w_sword_strike"] = std::move(skill);

}