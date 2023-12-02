#pragma once

void robot2_init()
{
	std::string path="people/robot2/";

	People people
	{
		.name=L"机器人二号",
		.attributes=
		{
			.HP_lim={150,5},
			.ATK={20,1},
			.DEF={20,0},
			.HARD={50,0},
			.SPEED={100,0},
			.max_jump_cnt={2,0}
		},
		.阵营=1,
		.box={{-141,-185},{141,157}},
		.armature=
		{
			.bone=
			{
				.name="body",
				.file_name=path+"body",
				.anchor={0.5,0.5},
				.pos={1500,600},
				.zorder = 76
			},
			.sons =
			{
				{
					"front_upper_arm",
					Armature
					{
						.bone =
						{
							.name = "front_upper_arm",
							.file_name = path + "front_upper_arm",
							.anchor = {0.85,0.5},
							.pos = {57,159},
							.zorder = 2
						},
						.sons =
						{
							{
								"front_lower_arm",
								Armature
								{
									.bone =
									{
										.name = "front_lower_arm",
										.file_name = path + "front_lower_arm",
										.anchor = {0.82,0.11},
										.pos = {10,11},
										.zorder = 1
									}
								}
							}
						}
					}
				},
				{
					"back_upper_arm",
					Armature
					{
						.bone =
						{
							.name = "back_upper_arm",
							.file_name = path + "back_upper_arm",
							.anchor = {0.15,0.37},
							.pos = {136,164},
							.zorder = 1
						},
						.sons =
						{
							{
								"back_lower_arm",
								Armature
								{
									.bone =
									{
										.name = "back_lower_arm",
										.file_name = path + "back_lower_arm",
										.anchor = {0.4,0.08},
										.pos = {58,18},
										.zorder = 1
									}
								}
							}
						}
					}
				}
			}
		},
		.default_ms="robot2_default",

	};
	people.skill[0]="p_robot2_attack";
	people_table["robot2"]=std::move(people);
}
