#pragma once
/*==================================ÉýÁúÈ­=============================================*/
W_Baroque_O_MS::W_Baroque_O_MS(Scene* scene, People* people) :
	Move_State(scene, people, 100)
{
}


void W_Baroque_O_MS::load()
{
	fuarm = &people->armature["front_upper_arm"].bone;
	flarm = &people->armature["front_upper_arm"]["front_lower_arm"].bone;
	buarm = &people->armature["back_upper_arm"].bone;
	blarm = &people->armature["back_upper_arm"]["back_lower_arm"].bone;
	fwp = &people->armature["front_upper_arm"]["front_lower_arm"]["baroque_front"].bone;
	light = &people->armature["front_upper_arm"]["front_lower_arm"]["baroque_light"].bone;
	light->rotation = 120;
	bwp = &people->armature["back_upper_arm"]["back_lower_arm"]["baroque_back"].bone;
	body = &people->armature.bone;
	fuleg = &people->armature["front_upper_leg"].bone;
	flleg = &people->armature["front_upper_leg"]["front_lower_leg"].bone;
	buleg = &people->armature["back_upper_leg"].bone;
	blleg = &people->armature["back_upper_leg"]["back_lower_leg"].bone;
	h = &people->armature["head"].bone;

	o1 = &people->armature["front_upper_arm"]["front_lower_arm"]["o1"].bone;
	o2 = &people->armature["front_upper_arm"]["front_lower_arm"]["o2"].bone;
	o3 = &people->armature["o3"].bone;
	o4 = &people->armature["o4"].bone;
	o5 = &people->armature["o5"].bone;
	o6 = &people->armature["o6"].bone;
	o7 = &people->armature["o7"].bone;
	o8 = &people->armature["o8"].bone;
	o9 = &people->armature["o9"].bone;
	o10 = &people->armature["o10"].bone;
	o11 = &people->armature["o11"].bone;

	people->v_y = 0;
	cnt = 0;


	fwp->visible = false;
	light->visible = true;
}

void W_Baroque_O_MS::run()
{
	cnt++;

	if (cnt <= 10) {
		fuarm->rotation += 10;
		flarm->rotation += 4.5;
		buarm->rotation -= 6;
		fuleg->rotation += 3;
		if (cnt == 5) {
			fwp->visible = false;
			light->visible = true;
		}
		body->rotation += 3;
		h->rotation += 4;
	}

	if (cnt > 40 && cnt <= 50) {
		buarm->rotation += 6;
		fuarm->rotation -= 15;
		flarm->rotation -= 4.5;
		buleg->rotation += 2;
		fuleg->rotation -= 4.5;
		flleg->rotation += 3;
		body->rotation -= 4;
		h->rotation -= 4;
		if (cnt == 45) {
			o3->visible = true;
		}
		if (cnt == 50) {
			o3->visible = false;
			o4->visible = true;
		}
	}

	if (cnt == 55) {
		people->find_and_attack({ {50,-100},{200,100} }, Damage(people->ATK() * 2.0), 200, { 0,0 }, 25, 50);
		scene->shake(50);
		o1->visible = true;
		o4->visible = false;
		o5->visible = true;
	}

	if (cnt == 60) {
		o1->visible = false;
		o2->visible = true;
		o5->visible = false;
	}

	if (cnt >= 65 && cnt <= 85) {
		if (cnt == 65) {
			o2->visible = false;
			o6->visible = true;
		}
		people->find_and_attack({ {50,-300},{200,300} }, Damage(people->ATK() * 2.0), 200, { 0,1500 }, 25, 50);

		if (cnt == 68) {
			o6->visible = false;
			o7->visible = true;
		}
		if (cnt == 71) {
			o7->visible = false;
			o8->visible = true;
		}
		if (cnt == 74) {
			o8->visible = false;
			o9->visible = true;
		}
		if (cnt == 77) {
			o9->visible = false;
			o10->visible = true;
		}
		if (cnt == 81) {
			o10->visible = false;
			o11->visible = true;
		}
		people->displace({ 0, 25 });
	}
	if (cnt == 85) o11->visible = false;
	if (cnt == 100) {
		people->set_ms(people->default_ms);
	}
}

void W_Baroque_O_MS::unload()
{
	h->rotation = 0;
	body->rotation = 0;
	fuarm->rotation = -45;
	flarm->rotation = -90;
	buarm->rotation = 0;
	blarm->rotation = -90;
	fuleg->rotation = 0;
	flleg->rotation = 0;
	buleg->rotation = 0;
	blleg->rotation = 0;

	fwp->visible = true;
	light->visible = false;

	o1->visible = false;
	o2->visible = false;
	o3->visible = false;
	o4->visible = false;
	o5->visible = false;
	o6->visible = false;
	o7->visible = false;
	o8->visible = false;
	o9->visible = false;
	o10->visible = false;
	o11->visible = false;

	cnt = 0;
}

W_Baroque_O::W_Baroque_O(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con) :
	Skill(scene, people, weapon, con),
	ms(scene, people)
{}

void W_Baroque_O::use(bool down, bool up)
{
	people->set_ms(&ms);
}

bool W_Baroque_O::can_use(bool down, bool up)
{
	if (people->on_floor() && up) {
		return true;
	}
	else return false;
}

void w_baroque_o_init()
{
	Config::Skill skill
	{
		.name = L"",
		.creator = [](const Config::Skill& con,Scene* scene,People* people,Weapon* weapon)->Skill*
		{
			return new W_Baroque_O(scene,people,weapon,con);
		}
	};

	skill_table["w_baroque_o"] = std::move(skill);
}
