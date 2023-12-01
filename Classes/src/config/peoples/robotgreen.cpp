#pragma once

void robotgreen_init()
{
	std::string path = "people/robotgreen/";

	People people
	{
		.name = L"绿机器人",
		.attributes =
		{
			.HP_lim = {1000000,5},
			.ATK = {20,1},
			.DEF = {20,0},
			.HARD = {50,0},
			.SPEED = {200,0},
			.max_jump_cnt = {2,0}
		},
		.阵营 = 1,
		.box = {{-232,-327},{232,257}},
		.armature =
		{
			.bone =
			{
				.name = "body",
				.file_name = path + "body",
				.anchor = {0.5,0.5},
				.pos = {1500,600},
				.zorder = 66
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
							.anchor = {0.7,0.8},
							.pos = {112,216},
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
										.anchor = {0.16,0.7},
										.pos = {35,37},
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
							.anchor = {0.16,0.75},
							.pos = {195,224},
							.zorder = -1
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
										.anchor = {0.17,0.68},
										.pos = {86,47},
										.zorder = 1
									}
								}
							}
						}
					}
				},
				{
					"front_leg",
					Armature
					{
						.bone =
						{
							.name = "front_leg",
							.file_name = path + "front_leg",
							.anchor = {0.44,0.67},
							.pos = {148,14},
							.zorder = 1
						}
					}
				},
				{
					"back_leg",
					Armature
					{
						.bone =
						{
							.name = "back_leg",
							.file_name = path + "back_leg",
							.anchor = {0.43,0.65},
							.pos = {225,14},
							.zorder = -1
						}
					}
				}
			}
		},
		.default_ms = "target_default",

	};
	people_table["robotgreen"] = std::move(people);
}
