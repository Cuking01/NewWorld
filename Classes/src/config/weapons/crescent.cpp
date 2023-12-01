#pragma once

Crescent::Crescent(const Config::Weapon& con, Scene* scene, People* people)
	:Weapon(con, scene, people)
{
	people->armature["front_upper_arm"]["front_lower_arm"].insert("crescent", con.armature);
}

void Crescent::load()
{
	people->armature["front_upper_arm"]["front_lower_arm"]["crescent"].bone.visible = true;
}

void Crescent::unload()
{
	people->armature["front_upper_arm"]["front_lower_arm"]["crescent"].bone.visible = false;
}

void crescent_init()
{
	Config::Weapon weapon
	{
		.name = L"",
		.armature =
		{
			.bone =
			{
				.name = "crescent",
				.file_name = "weapon/crescent/crescent",
				.anchor = {0.7,0.7},
				.pos = {3,10},
				.zorder=-1,
				.visible = false
				
			},
			.sons=
			{
				{
					"1",
					Armature
					{
						.bone=
						{
							.name="1",
							.file_name="weapon/crescent/1",
							.anchor={0.15,0.5},
							.pos={10,70},
							.zorder=1,
							.visible=false,
							.scale={0.18,0.08}
						}
					}
				},
				{
					"2",
					Armature
					{
						.bone=
						{
							.name="2",
							.file_name="weapon/crescent/2",
							.anchor={0.6,0.5},
							.pos={10,70},
							.zorder=1,
							.visible=false,
							.scale={0.18,0.08}
						}
					}
				},
				{
					"u1",
					Armature
					{
						.bone=
						{
							.name="u1",
							.file_name="weapon/crescent/u1",
							.anchor={0.5,0.5},
							.pos={100,75},
							.zorder=1,
							.visible=false,
							.scale={1,1}
						}
					}
				},
				{
					"u2",
					Armature
					{
						.bone=
						{
							.name="u2",
							.file_name="weapon/crescent/u2",
							.anchor={0.5,0.5},
							.pos={100,75},
							.zorder=1,
							.visible=false,
							.scale={1,1}
						}
					}
				},
				{
					"u3",
					Armature
					{
						.bone=
						{
							.name="u3",
							.file_name="weapon/crescent/u3",
							.anchor={0.5,0.5},
							.pos={100,75},
							.zorder=1,
							.visible=false,
							.scale={1,1}
						}
					}
				},
				{
					"u3",
					Armature
					{
						.bone=
						{
							.name="u3",
							.file_name="weapon/crescent/u3",
							.anchor={0.5,0.5},
							.pos={100,75},
							.zorder=1,
							.visible=false,
							.scale={1,1}
						}
					}
				},
				{
					"i0",
					Armature
					{
						.bone=
						{
							.name="i0",
							.file_name="weapon/crescent/i0",
							.anchor={0.5,0.5},
							.pos={110,69},
							.zorder=10,
							.visible=false,
							.scale={0.5,0.5}
						}
					}
				},
			}
		},
		.creator = [](const Config::Weapon& con,Scene* scene,People* people)->Weapon*
		{
			return new Crescent(con,scene,people);
		}
	};
	weapon.skill[0] = "w_crescent_attack";
	weapon.skill[1] = "w_crescent_h";
	weapon.skill[2] = "w_crescent_u";
	weapon.skill[3] = "w_crescent_i";
	weapon.skill[4] = "w_crescent_o";
	weapon_table["crescent"] = std::move(weapon);
}
