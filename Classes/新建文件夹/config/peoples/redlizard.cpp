#pragma once

void redlizard_init()
{
	std::string path = "people/redlizard/";

	People people
	{
		.name = L"红蜥蜴",
		.attributes =
		{
			.HP_lim = {0,100},
			.ATK = {0,5},
			.DEF = {20,0},
			.HARD = {50,0},
			.SPEED = {200,0},
			.max_jump_cnt = {2,0}
		},
		.阵营 = 1,
		.box = {{-73,-240},{73,240}},
		.armature =
		{
			.bone =
			{
				.name = "body",
				.file_name = path + "body",
				.anchor = {0.5,0.5},
				.pos = {1500,600},
				.zorder = 78
			},
			.sons =
			{
				{
					"head",
					Armature
					{
						.bone =
						{
							.name = "head",
							.file_name = path + "head",
							.anchor = {0.6,0.3},
							.pos = {43,152},
							.zorder = 1
						}
					}
				},
				{
					"front_upper_arm",
					Armature
					{
						.bone =
						{
							.name = "front_upper_arm",
							.file_name = path + "front_upper_arm",
							.anchor = {0.8,0.85},
							.pos = {8,131},
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
										.anchor = {0.55,0.85},
										.pos = {9,2},
										.zorder = -1
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
							.anchor = {0.3,0.8},
							.pos = {64,126},
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
										.anchor = {0.75,0.9},
										.pos = {34,3},
										.zorder = -1
									}
								}
							}
						}
					}
				},
				{
					"front_upper_leg",
					Armature
					{
						.bone =
						{
							.name = "front_upper_leg",
							.file_name = path + "front_upper_leg",
							.anchor = {0.5,0.8},
							.pos = {21,3},
							.zorder = -1
						},
						.sons =
						{
							{
								"front_lower_leg",
								Armature
								{
									.bone =
									{
										.name = "front_lower_leg",
										.file_name = path + "front_lower_leg",
										.anchor = {0.5,0.85},
										.pos = {13,3},
										.zorder = -1
									}
								}
							}
						}
					}
				},
				{
					"back_upper_leg",
					Armature
					{
						.bone =
						{
							.name = "back_upper_leg",
							.file_name = path + "back_upper_leg",
							.anchor = {0.5,0.8},
							.pos = {56,3},
							.zorder = -1
						},
						.sons =
						{
							{
								"back_lower_leg",
								Armature
								{
									.bone =
									{
										.name = "back_lower_leg",
										.file_name = path + "back_lower_leg",
										.anchor = {0.7,0.8},
										.pos = {22,2},
										.zorder = -1
									}
								}
							}
						}
					}
				}
			}
		},
		.default_ms = "redlizard_default",

	};
	people.skill[0]="p_redrizard_assassinate";
	people_table["redlizard"] = std::move(people);
}
