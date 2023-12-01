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


