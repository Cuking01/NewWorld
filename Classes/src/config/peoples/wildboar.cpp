#pragma once

void wildboar_init()
{
	std::string path="people/wildboar/";

	People people
	{
		.name=L"野猪",
		.attributes=
		{
			.HP_lim={1000000,5},
			.ATK={20,1},
			.DEF={20,0},
			.HARD={50,0},
			.SPEED={200,0},
			.max_jump_cnt={2,0}
		},
		.阵营=1,
		.box={{-300,-225},{300,200}},
		.armature=
		{
			.bone=
			{
				.name="body",
				.file_name=path+"body",
				.anchor={0.5,0.5},
				.pos={1500,600},
				.zorder = 70
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
							.anchor = {0.2,0.5},
							.pos = {348,94},
							.zorder = 1
						}
					}
				},
				{
					"front_upper_arm",
					Armature
					{
						.bone=
						{
							.name="front_upper_arm",
							.file_name=path+"front_upper_arm",
							.anchor={0.5,0.75},
							.pos={244,21},
							.zorder=2
						},
						.sons=
						{
							{
								"front_lower_arm",
								Armature
								{
									.bone=
									{
										.name = "front_lower_arm",
										.file_name = path + "front_lower_arm",
										.anchor = {0.4,0.75},
										.pos = {27,11},
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
						.bone=
						{
							.name="back_upper_arm",
							.file_name=path+"back_upper_arm",
							.anchor={0.5,0.75},
							.pos={280,24},
							.zorder=-1
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
										.anchor = {0.32,0.75},
										.pos = {23,10},
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
						.bone=
						{
							.name="front_upper_leg",
							.file_name=path+"front_upper_leg",
							.anchor={0.67,0.65},
							.pos={19,26},
							.zorder=1
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
										.anchor = {0.5,0.78},
										.pos = {49,5},
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
						.bone=
						{
							.name="back_upper_leg",
							.file_name=path+"back_upper_leg",
							.anchor={0.67,0.65},
							.pos={57,26},
							.zorder=-1
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
										.anchor = {0.5,0.77},
										.pos = {48,5},
										.zorder = -1
									}
								}
							}
						}
					}
				}
			}
		},
		.default_ms="target_default",

	};
	people_table["wildboar"]=std::move(people);
}
