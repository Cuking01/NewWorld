#pragma once
/*==================================�Ϲ�ȭ=============================================*/
W_Baroque_H_MS::W_Baroque_H_MS(Scene* scene, People* people) :
	Move_State(scene, people, 100)
{
}


void W_Baroque_H_MS::load()
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

	h1 = &people->armature["h1"].bone;
	h2 = &people->armature["h2"].bone;
	h3 = &people->armature["h3"].bone;
	h4 = &people->armature["h4"].bone;
	h5 = &people->armature["h5"].bone;
	h6 = &people->armature["h6"].bone;

	people->v_y = 0;
	cnt = 0;
}

void W_Baroque_H_MS::run()
{
	cnt++;

	if (cnt <= 10) {
		fuarm->rotation += 4.5;
		body->rotation += 1.5;
		h->rotation += 3;
	}

	if (cnt > 10 && cnt <= 20) {
		fuarm->rotation -= 10;
		body->rotation -= 2;
	}

	if (cnt > 20 && cnt <= 30) {
		h1->visible = true;
		if (cnt > 25) {
			h1->visible = false;
			h2->visible = true;
		}
		if (cnt == 30) {
			h2->visible = false;
			h3->visible = true;
		}
		fuarm->rotation -= 4;
		flarm->rotation += 3;
		fuleg->rotation -= 5;
		flleg->rotation += 8;
		h->rotation -= 4;
	}
	if (cnt > 30) {
		h3->visible = false;
		h4->visible = true;
	}
	if (cnt > 35) {
		h4->visible = false;
		h5->visible = true;
	}
	if (cnt > 40) {
		h5->visible = false;
		h6->visible = true;
	}

	if (cnt == 25) {
		people->find_and_attack({ {50,-100},{200,100} }, Damage(people->ATK() * 1.5), 200, { 30,800 }, 25, 50);
		scene->shake(50);
		people->displace({ 12, 0 });
		people->v_y = 0;
	}

	if (cnt > 35 && cnt <= 45) {
		fuarm->rotation += 9.5;
		flarm->rotation -= 3;
		body->rotation += 0.5;
		fuleg->rotation += 5;
		flleg->rotation -= 8;
		h->rotation += 3;
	}

	if (cnt == 45) {
		h6->visible = false;
		people->set_ms(people->default_ms);
	}
}

void W_Baroque_H_MS::unload()
{
	h1->visible = false;
	h2->visible = false;
	h3->visible = false;
	h4->visible = false;
	h5->visible = false;
	h6->visible = false;

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
	cnt = 0;
}

/*==================================������=============================================*/
W_Baroque_HS_MS::W_Baroque_HS_MS(Scene* scene, People* people) :
	Move_State(scene, people, 100)
{
}

void W_Baroque_HS_MS::load()
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

void W_Baroque_HS_MS::run()
{
	cnt++;
	if (cnt <= 10) {
		fuarm->rotation -= 9;
		buarm->rotation -= 12;
		body->rotation -= 0.5;
		flleg->rotation += 9;
		blleg->rotation += 9;
	}

	if (cnt > 20 && cnt <= 30) {
		fuarm->rotation += 4;
		flarm->rotation += 9;
		buarm->rotation += 9;
		blarm->rotation += 3;
		
		body->rotation += 5;
		h->rotation += 3;
	}

	if (cnt == 25) {
		people->displace({ 0,-1e5 });
		scene->shake(50);
		people->find_and_attack({ {25,-1000},{75,200} }, Damage(people->ATK() * 1.5), 200, { 10,-1e5 }, 25, 50);
	}

	if (cnt == 40) {
		people->set_ms(people->default_ms);
	}
}

void W_Baroque_HS_MS::unload()
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
	cnt = 0;
	people->v_y = 0;
}
//
/*==================================U=============================================*/
W_Baroque_H::W_Baroque_H(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con) :
	Skill(scene, people, weapon, con),
	ms(scene, people), ms_hs(scene, people)
{}

void W_Baroque_H::use(bool down, bool up)
{
	if (!people->on_floor()) {
		if (down) {  //������
			people->set_ms(&ms_hs); //S+H
		}
	}
	else {
	   	people->set_ms(&ms); //�Ϲ�ȭH
	}
}

bool W_Baroque_H::can_use(bool down, bool up)
{
	if (!people->on_floor()) {
		if (down) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return true;
	}
}

void w_baroque_h_init()
{
	Config::Skill skill
	{
		.name = L"",
		.creator = [](const Config::Skill& con,Scene* scene,People* people,Weapon* weapon)->Skill*
		{
			return new W_Baroque_H(scene,people,weapon,con);
		}
	};

	skill_table["w_baroque_h"] = std::move(skill);
}
