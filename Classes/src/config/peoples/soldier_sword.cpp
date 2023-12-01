#pragma once

void soldier_sword_init()
{
	std::string path = "people/soldier_sword/";

	People people
	{
		.name = L"带刀侍卫",
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
							.anchor = {0.59,0.88},
							.pos = {58,85},
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
							.anchor = {0.06,0.8},
							.pos = {100,85},
							.zorder = -1
						}
					}
				}
			}
		},
		.default_ms = "target_default",

	};

	people_table["soldier_sword"] = std::move(people);
}
