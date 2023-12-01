#pragma once

W_Baroque_0_MS::W_Baroque_0_MS(Scene* scene, People* people) :
	Move_State(scene, people, 100)
{
}


void W_Baroque_0_MS::load()
{
	fuarm = &people->armature["front_upper_arm"].bone;
	flarm = &people->armature["front_upper_arm"]["front_lower_arm"].bone;
	buarm = &people->armature["back_upper_arm"].bone;
	blarm = &people->armature["back_upper_arm"]["back_lower_arm"].bone;
	fwp = &people->armature["front_upper_arm"]["front_lower_arm"]["baroque_front"].bone;
	bwp = &people->armature["back_upper_arm"]["back_lower_arm"]["baroque_back"].bone;
	body = &people->armature.bone;
	fuleg = &people->armature["front_upper_leg"].bone;
	flleg = &people->armature["front_upper_leg"]["front_lower_leg"].bone;
	buleg = &people->armature["back_upper_leg"].bone;
	blleg = &people->armature["back_upper_leg"]["back_lower_leg"].bone;
	h = &people->armature["head"].bone;
	people->v_y = 0;
	cnt = 0;
}

void W_Baroque_0_MS::run()
{
	cnt++;

	if (cnt <= 10) {
		fuarm->rotation -= 10;
		flarm->rotation += 9;
		body->rotation += 0.5;
		h->rotation += 0.25;
	}


	if (cnt == 10) {
		people->find_and_attack({ {50,-100},{200,100} }, Damage(people->ATK() * 1.5), 200, { 50,0 }, 25, 50);
	}

	if (cnt > 20 && cnt <= 30) {
		fuarm->rotation += 10;
		flarm->rotation -= 9;
		buarm->rotation -= 9;
		blarm->rotation += 9;
		body->rotation += 0.5;
		h->rotation += 0.25;
	}

	if (cnt == 30) {
		people->find_and_attack({ {50,-100},{200,100} }, Damage(people->ATK() * 1.5), 200, { 50,0 }, 25, 50);
	}

	if (cnt > 30 && cnt <= 40) {
		body->rotation -= 1;
		blarm->rotation -= 9;
		buarm->rotation += 9;
		h->rotation -= 0.5;
	}

	if (cnt == 40) {
		people->set_ms(people->default_ms);
	}
}

void W_Baroque_0_MS::unload()
{
}


W_Baroque_0::W_Baroque_0(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con) :
	Skill(scene, people, weapon, con),
	ms(scene, people)
{}

void W_Baroque_0::use(bool down,bool up)
{
	people->set_ms(&ms);
}

void w_baroque_0_init()
{
	Config::Skill skill
	{
		.name = L"",
		.creator = [](const Config::Skill& con,Scene* scene,People* people,Weapon* weapon)->Skill*
		{
			return new W_Baroque_0(scene,people,weapon,con);
		}
	};

	skill_table["w_baroque_0"] = std::move(skill);
}
