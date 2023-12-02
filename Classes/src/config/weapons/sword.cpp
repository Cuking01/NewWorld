#pragma once

Sword::Sword(const Config::Weapon& con, Scene* scene, People* people)
	:Weapon(con, scene, people)
{
	people->armature["front_upper_arm"]["front_lower_arm"].insert("sword", con.armature);
}

void Sword::load()
{
	people->armature["front_upper_arm"]["front_lower_arm"]["sword"].bone.visible = true;
}

void Sword::unload()
{
	people->armature["front_upper_arm"]["front_lower_arm"]["sword"].bone.visible = false;
}

void sword_init()
{
	Config::Weapon weapon
	{
		.name = L"",
		.armature =
		{
			.bone =
			{
				.name = "sword",
				.file_name = "weapon/sword/sword",
				.anchor = {0.2,0.5},
				.pos = {3,10},
				.zorder = -1,
				.visible = false
			},
			.sons =
			{
				{
					"i1",
					Armature
					{
						.bone =
						{
							.name = "i1",
							.file_name = "weapon/sword/i1",
							.anchor = {0,0},
							.pos = {20,0},
							.zorder = 1,
							.visible = false,
							.scale = {0.08,0.08}
						}
					}
				},
			}
		},
		.creator = [](const Config::Weapon& con,Scene* scene,People* people)->Weapon*
		{
			return new Sword(con,scene,people);
		}
	};
	weapon.skill[0] = "w_sword_attack";
	weapon.skill[1] = "w_sword_strike";
	weapon.skill[2] = "w_sword_u";
	weapon.skill[3] = "w_sword_i";

	weapon_table["sword"] = std::move(weapon);
}
