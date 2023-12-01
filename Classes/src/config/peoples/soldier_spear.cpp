#pragma once

void soldier_spear_init()
{
	std::string path = "people/soldier_spear/";

	People people
	{
		.name = L"带枪侍卫",
		.attributes =
		{
			.HP_lim = {1000000,5},
			.ATK = {20,1},
			.DEF = {20,0},
			.HARD = {50,0},
			.SPEED = {100,0},
			.max_jump_cnt = {2,0}
		},
		.阵营 = 1,
		.box = {{-123,-157},{123,130}},
		.armature =
		{
			.bone =
			{
				.name = "body",
				.file_name = path + "body",
				.anchor = {0.5,0.5},
				.pos = {1500,600},
				.zorder = 82
			},
			.sons =
			{
				{
					"front_arm",
					Armature
					{
						.bone =
						{
							.name = "front_arm",
							.file_name = path + "front_arm",
							.anchor = {0.22,0.81},
							.pos = {56,84},
							.zorder = 2
						}
					}
				},
				{
					"back_arm",
					Armature
					{
						.bone =
						{
							.name = "back_arm",
							.file_name = path + "back_arm",
							.anchor = {0.19,0.8},
							.pos = {98,87},
							.zorder = -1
						}
					}
				}
			}
		},
		.default_ms = "target_default",

	};

	people_table["soldier_spear"] = std::move(people);
}
