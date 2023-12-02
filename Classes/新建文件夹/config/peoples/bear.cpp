#pragma once

void bear_init()
{
	std::string path="people/bear/";

	People people
	{
		.name=L"黑熊",
		.attributes=
		{
			.HP_lim={800,5},
			.ATK={20,1},
			.DEF={20,0},
			.HARD={50,0},
			.SPEED={200,0},
			.max_jump_cnt={2,0}
		},
		.阵营=1,
		.box={{-230,-275},{230,233}},
		.armature=
		{
			.bone=
			{
				.name="body",
				.file_name=path+"body",
				.anchor={0.5,0.5},
				.pos={1500,600},
				.zorder = 68
			},
			.sons=
			{
				{
					"head",
					Armature
					{
						.bone =
						{
							.name = "head",
							.file_name = path + "head",
							.anchor = {0.26,0.5},
							.pos = {363,106},
							.zorder = 1
						}
					}
				},
				{
					"front_arm",
					Armature
					{
						.bone=
						{
							.name="front_arm",
							.file_name=path+"front_arm",
							.anchor={0.28,0.76},
							.pos={238,37},
							.zorder=2,
							//.visible=false
						}
					}
				},
				{
					"back_arm",
					Armature
					{
						.bone=
						{
							.name="back_arm",
							.file_name=path+"back_arm",
							.anchor={0.33,0.82},
							.pos={361,58},
							.zorder=-1,
							//.visible =false
						}
					}
				},
				{
					"front_leg",
					Armature
					{
						.bone=
						{
							.name="front_leg",
							.file_name=path+"front_leg",
							.anchor={0.5,0.8},
							.pos={93,35},
							.zorder=1,
							//.visible = false
						}
					}
				},
				{
					"back_leg",
					Armature
					{
						.bone=
						{
							.name="back_leg",
							.file_name=path+"back_leg",
							.anchor={0.41,0.77},
							.pos={48,59},
							.zorder=-1,
							//.visible = false
						}
					}
				}
			}
		},
		.default_ms="bear_default",

	};
	people_table["bear"]=std::move(people);
}
