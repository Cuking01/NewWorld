#pragma once

void robotboss_init()
{
	std::string path = "people/robotboss/";

	People people
	{
		.name = L"机器人Boss",
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
		.box = {{-261,-256},{261,235}},
		.armature =
		{
			.bone =
			{
				.name = "body",
				.file_name = path + "body",
				.anchor = {0.5,0.5},
				.pos = {1500,600},
				.zorder = 72
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
							.anchor = {0.35,0.85},
							.pos = {109,226},
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
										.anchor = {0.08,0.82},
										.pos = {72,16},
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
							.anchor = {0.36,0.85},
							.pos = {253,208},
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
										.anchor = {0.08,0.74},
										.pos = {76,13},
										.zorder = 1
									}
								}
							}
						}
					}
				}
			}
		},
		.default_ms = "target_default",

	};

	people_table["robotboss"] = std::move(people);
}
