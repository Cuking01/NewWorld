#pragma once
W_Baroque_IE_MS::W_Baroque_IE_MS(Scene* scene, People* people) :Move_State(scene, people) { cnt = 0; }
void W_Baroque_IE_MS::run() {
	cnt++;
	if (cnt > mx) {
		people->erase_effect(people->handle);
		return;
	}
}
//===================================================================
W_Baroque_I_MS::W_Baroque_I_MS(Scene* scene, People* people) :
	Move_State(scene, people, 100)
{
}


void W_Baroque_I_MS::load()
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

	e1 = &people->armature["e1"];
	e2 = &people->armature["e2"];
	e3 = &people->armature["e3"];
	e4 = &people->armature["e4"];
	e5 = &people->armature["e5"];
	e6 = &people->armature["e6"];

	i1 = &people->armature["back_upper_leg"]["back_lower_leg"]["i1"];
	i2 = &people->armature["back_upper_leg"]["back_lower_leg"]["i2"];
	i3 = &people->armature["back_upper_leg"]["back_lower_leg"]["i3"];
	i4 = &people->armature["back_upper_leg"]["back_lower_leg"]["i4"];

	people->v_y = 0;
	cnt = 0;
}

void W_Baroque_I_MS::run()
{
	cnt++;
	people->armature.set_opacity(0);
	if (cnt <= 5) {
		(e1->bone).visible = true;
		e1->set_opacity(255);
	}
	else if (cnt <= 10) {
		people->displace({ -5, 0 });
		(e1->bone).visible = false;
		(e2->bone).visible = true;
		e2->set_opacity(255);
		(i1->bone).visible = true;
		i1->set_opacity(255);
		people->find_and_attack({ {-200,-100},{200,100} }, Damage(people->ATK() * 0.1), 200, { 20,200 }, 25, 50);
	}
	else if (cnt <= 15) {
		people->displace({ -5, 0 });
		(e2->bone).visible = false;
		(e3->bone).visible = true;
		e3->set_opacity(255);
		(i1->bone).visible = false;
		(i2->bone).visible = true;
		i2->set_opacity(255);
		people->find_and_attack({ {-200,-100},{200,100} }, Damage(people->ATK() * 0.1), 200, { 20,200 }, 25, 50);
	}
	else if (cnt <= 20) {
		people->displace({ -5, 0 });
		(e3->bone).visible = false;
		(e4->bone).visible = true;
		e4->set_opacity(255);
		(i2->bone).visible = false;
		(i3->bone).visible = true;
		i3->set_opacity(255);
		people->find_and_attack({ {-200,-100},{200,100} }, Damage(people->ATK() * 0.1), 200, { 20,200 }, 25, 50);
	}
	else if (cnt <= 25) {
		people->displace({ -5, 0 });
		(e4->bone).visible = false;
		(e5->bone).visible = true;
		e5->set_opacity(255);
		(i3->bone).visible = false;
		(i4->bone).visible = true;
		i4->set_opacity(255);
		people->find_and_attack({ {-200,-100},{200,100} }, Damage(people->ATK() * 0.1), 200, { 20,200 }, 25, 50);
	}
	else if (cnt <= 30) {
		(e5->bone).visible = false;
		(e6->bone).visible = true;
		e6->set_opacity(255);
	}
	else {
		(i4->bone).visible = false;
		(e6->bone).visible = false;
		people->set_ms(people->default_ms);
	}
}

void W_Baroque_I_MS::unload()
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

	(e1->bone).visible = false;
	(e2->bone).visible = false;
	(e3->bone).visible = false;
	(e4->bone).visible = false;
	(e5->bone).visible = false;
	(e6->bone).visible = false;
	(i1->bone).visible = false;
	(i2->bone).visible = false;
	(i3->bone).visible = false;
	(i4->bone).visible = false;

	(*people).armature.set_opacity(255);

	cnt = 0;
}


W_Baroque_I::W_Baroque_I(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con) :
	Skill(scene, people, weapon, con),
	ms(scene, people)
{}

void W_Baroque_I::use(bool down, bool up)
{
	people->set_ms(&ms);
}

bool W_Baroque_I::can_use(bool down, bool up)
{
	return people->on_floor();
}

void w_baroque_i_init()
{
	Config::Skill skill
	{
		.name = L"",
		.creator = [](const Config::Skill& con,Scene* scene,People* people,Weapon* weapon)->Skill*
		{
			return new W_Baroque_I(scene,people,weapon,con);
		}
	};

	skill_table["w_baroque_i"] = std::move(skill);
}
