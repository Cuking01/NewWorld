#pragma once

Baroque::Baroque(const Config::Weapon& con, Scene* scene, People* people)
	:Weapon(con, scene, people)
{}

void Baroque::load()
{
	people->armature["front_upper_arm"]["front_lower_arm"]["baroque_front"].bone.visible = true;
	people->armature["back_upper_arm"]["back_lower_arm"]["baroque_back"].bone.visible = true;
	people->armature["front_upper_leg"]["front_lower_leg"]["front"].bone.visible = true;
	people->armature["back_upper_leg"]["back_lower_leg"]["back"].bone.visible = true;

	people->armature["front_upper_arm"].bone.rotation = -45;
	people->armature["front_upper_arm"]["front_lower_arm"].bone.rotation = -90;
	people->armature["back_upper_arm"]["back_lower_arm"].bone.rotation = -90;
	people->armature["front_upper_leg"].bone.rotation = 0;
	people->armature["front_upper_leg"]["front_lower_leg"].bone.rotation = 0;
	people->armature["front_upper_arm"]["front_lower_arm"]["baroque_front"].bone.rotation = 35;
	people->armature["back_upper_arm"]["back_lower_arm"]["baroque_back"].bone.rotation = 30;
}

void Baroque::unload()
{
	people->armature["front_upper_arm"]["front_lower_arm"]["baroque_front"].bone.visible = false;
	people->armature["back_upper_arm"]["back_lower_arm"]["baroque_back"].bone.visible = false;
	people->armature["front_upper_leg"]["front_lower_leg"]["front"].bone.visible = false;
	people->armature["back_upper_leg"]["back_lower_leg"]["back"].bone.visible = false;

	people->armature["front_upper_arm"].bone.rotation = 0;
	people->armature["front_upper_arm"]["front_lower_arm"].bone.rotation = 0;
	people->armature["back_upper_arm"]["back_lower_arm"].bone.rotation = 0;
	people->armature["front_upper_leg"].bone.rotation = 0;
	people->armature["front_upper_leg"]["front_lower_leg"].bone.rotation = 0;
	people->armature["front_upper_arm"]["front_lower_arm"]["baroque_front"].bone.rotation = 35;
	people->armature["back_upper_arm"]["back_lower_arm"]["baroque_back"].bone.rotation = 30;
}

void baroque_init()
{
	Config::Weapon weapon
	{
		.name = L"",
		.creator = [](const Config::Weapon& con,Scene* scene,People* people)->Weapon*
		{
			auto p1 = new Baroque(con,scene,people);
			p1->people->armature["front_upper_arm"]["front_lower_arm"].insert("baroque_front", {
				.bone =
				{
					.name = "baroque_front",
					.file_name = "weapon/baroque/baroque_front",
					.anchor = { 0.5,0.5 },
					.pos = { 8,0 },
					.visible = false
				}
			});

			p1->people->armature["back_upper_arm"]["back_lower_arm"].insert("baroque_back", {
				.bone =
				{
					.name = "baroque_back",
					.file_name = "weapon/baroque/baroque_back",
					.anchor = { 0.5,0.5 },
					.pos = { 8,0 },
					.visible = false
				}
			});

			p1->people->armature["front_upper_leg"]["front_lower_leg"].insert("front", {
				.bone =
				{
					.name = "front",
					.file_name = "weapon/baroque/front",
					.anchor = { 0.4,0.4 },
					.pos = { 5,14 },
					.visible = false
				}
			});

			p1->people->armature["front_upper_arm"]["front_lower_arm"].insert("baroque_light", {
				.bone =
				{
					.name = "baroque_light",
					.file_name = "weapon/baroque/baroque_light",
					.anchor = { 0.4,0.4 },
					.pos = { 7,0 },
					.visible = false,
				}
			});

			p1->people->armature["back_upper_leg"]["back_lower_leg"].insert("back", {
				.bone =
				{
					.name = "back",
					.file_name = "weapon/baroque/back",
					.anchor = { 0.4,0.4 },
					.pos = { 5,14 },
					.visible = false
				}
			});

			p1->people->armature["back_upper_leg"]["back_lower_leg"].insert("i1", {
				.bone =
				{
					.name = "i1",
					.file_name = "weapon/baroque/I/i1",
					.anchor = { 0.5,0.5 },
					.pos = { 5,50 },
					.visible = false
				}
			});

			p1->people->armature["back_upper_leg"]["back_lower_leg"].insert("i2", {
				.bone =
				{
					.name = "i2",
					.file_name = "weapon/baroque/I/i2",
					.anchor = { 0.5,0.5 },
					.pos = { 10,75 },
					.visible = false
				}
			});

			p1->people->armature["back_upper_leg"]["back_lower_leg"].insert("i3", {
				.bone =
				{
					.name = "i3",
					.file_name = "weapon/baroque/I/i3",
					.anchor = { 0.5,0.5 },
					.pos = { 10,75 },
					.visible = false
				}
			});

			p1->people->armature["back_upper_leg"]["back_lower_leg"].insert("i4", {
				.bone =
				{
					.name = "i4",
					.file_name = "weapon/baroque/I/i4",
					.anchor = { 0.5,0.5 },
					.pos = { 55,100 },
					.visible = false
				}
			});

			p1->people->armature.insert("h1", {
				.bone =
				{
					.name = "h1",
					.file_name = "weapon/baroque/H/h1",
					.anchor = { 0.5,0.5 },
					.pos = { 150,150 },
					.visible = false
				}
			});

			p1->people->armature.insert("h2", {
				.bone =
				{
					.name = "h2",
					.file_name = "weapon/baroque/H/h2",
					.anchor = { 0.5,0.5 },
					.pos = { 150,150 },
					.visible = false
				}
			});

			p1->people->armature.insert("h3", {
				.bone =
				{
					.name = "h3",
					.file_name = "weapon/baroque/H/h3",
					.anchor = { 0.5,0.5 },
					.pos = { 150,150 },
					.visible = false
				}
			});

			p1->people->armature.insert("h4", {
				.bone =
				{
					.name = "h4",
					.file_name = "weapon/baroque/H/h4",
					.anchor = { 0.5,0.5 },
					.pos = { 150,150 },
					.visible = false
				}
			});

			p1->people->armature.insert("h5", {
				.bone =
				{
					.name = "h5",
					.file_name = "weapon/baroque/H/h5",
					.anchor = { 0.5,0.5 },
					.pos = { 150,150 },
					.visible = false
				}
			});

			p1->people->armature.insert("h6", {
				.bone =
				{
					.name = "h6",
					.file_name = "weapon/baroque/H/h6",
					.anchor = { 0.5,0.5 },
					.pos = { 150,150 },
					.visible = false
				}
			});

			p1->people->armature["front_upper_leg"]["front_lower_leg"].insert("u1", {
				.bone =
				{
					.name = "u1",
					.file_name = "weapon/baroque/U/u1",
					.anchor = { 0.5,0.5 },
					.pos = { 20,60 },
					.visible = false,
					.scale = {1, 1}
				}
			});

			p1->people->armature["front_upper_leg"]["front_lower_leg"].insert("u2", {
				.bone =
				{
					.name = "u2",
					.file_name = "weapon/baroque/U/u2",
					.anchor = { 0.5,0.5 },
					.pos = { 20,60 },
					.visible = false,
					.scale = {1, 1}
				}
			});

			p1->people->armature["front_upper_leg"]["front_lower_leg"].insert("u3", {
				.bone =
				{
					.name = "u3",
					.file_name = "weapon/baroque/U/u3",
					.anchor = { 0.5,0.5 },
					.pos = { 20,60 },
					.visible = false,
					.scale = {1, 1}
				}
			});

			p1->people->armature["front_upper_leg"]["front_lower_leg"].insert("u4", {
				.bone =
				{
					.name = "u4",
					.file_name = "weapon/baroque/U/u4",
					.anchor = { 0.5,0.5 },
					.pos = { 20,60 },
					.visible = false,
					.scale = {1, 1}
				}
			});

			p1->people->armature["front_upper_leg"]["front_lower_leg"].insert("u5", {
				.bone =
				{
					.name = "u5",
					.file_name = "weapon/baroque/U/u5",
					.anchor = { 0.5,0.5 },
					.pos = { 15,55 },
					.visible = false,
					.scale = {1, 1}
				}
			});

			p1->people->armature["front_upper_arm"]["front_lower_arm"].insert("o1", {
				.bone =
				{
					.name = "o1",
					.file_name = "weapon/baroque/O/o1",
					.anchor = { 0.4,0.4 },
					.pos = { -150,-100 },
					.visible = false,
				}
			});

			p1->people->armature["front_upper_arm"]["front_lower_arm"].insert("o2", {
				.bone =
				{
					.name = "o2",
					.file_name = "weapon/baroque/O/o2",
					.anchor = { 0.4,0.4 },
					.pos = { -150,-100 },
					.visible = false,
				}
			});

			p1->people->armature.insert("o3", {
				.bone =
				{
					.name = "o3",
					.file_name = "weapon/baroque/O/o3",
					.anchor = { 0.5,0.5 },
					.pos = { 150,250 },
					.visible = false
				}
			});

			p1->people->armature.insert("o4", {
				.bone =
				{
					.name = "o4",
					.file_name = "weapon/baroque/O/o4",
					.anchor = { 0.5,0.5 },
					.pos = { 150,250 },
					.visible = false
				}
			});

			p1->people->armature.insert("o5", {
				.bone =
				{
					.name = "o5",
					.file_name = "weapon/baroque/O/o5",
					.anchor = { 0.5,0.5 },
					.pos = { 50,250 },
					.visible = false
				}
			});

			p1->people->armature.insert("o6", {
				.bone =
				{
					.name = "o6",
					.file_name = "weapon/baroque/O/o6",
					.anchor = { 0.5,0.5 },
					.pos = { 50,250 },
					.visible = false
				}
			});

			p1->people->armature.insert("o7", {
				.bone =
				{
					.name = "o7",
					.file_name = "weapon/baroque/O/o7",
					.anchor = { 0.5,0.5 },
					.pos = { 50,150 },
					.visible = false
				}
			});

			p1->people->armature.insert("o8", {
				.bone =
				{
					.name = "o8",
					.file_name = "weapon/baroque/O/o8",
					.anchor = { 0.5,0.5 },
					.pos = { 50,100 },
					.visible = false
				}
			});

			p1->people->armature.insert("o9", {
				.bone =
				{
					.name = "o9",
					.file_name = "weapon/baroque/O/o9",
					.anchor = { 0.5,0.5 },
					.pos = { 50,100 },
					.visible = false
				}
			});

			p1->people->armature.insert("o10", {
				.bone =
				{
					.name = "o10",
					.file_name = "weapon/baroque/O/o10",
					.anchor = { 0.5,0.5 },
					.pos = { 50,100 },
					.visible = false
				}
			});

			p1->people->armature.insert("o11", {
				.bone =
				{
					.name = "o11",
					.file_name = "weapon/baroque/O/o11",
					.anchor = { 0.5,0.5 },
					.pos = { 50,100 },
					.visible = false
				}
			});

			p1->people->armature.insert("j1", {
				.bone =
				{
					.name = "j1",
					.file_name = "weapon/baroque/J/j1",
					.anchor = { 0.5,0.5 },
					.pos = { 125,100 },
					.visible = false,
					.scale = { 0.03, 0.03 }
				}
			});

			return p1;
		}
		

	};
	weapon.skill[0] = "w_baroque_attack";
	weapon.skill[1] = "w_baroque_h";
	weapon.skill[2] = "w_baroque_u";
	weapon.skill[3] = "w_baroque_i";
	weapon.skill[4] = "w_baroque_o";
	weapon_table["baroque"] = std::move(weapon);
}


