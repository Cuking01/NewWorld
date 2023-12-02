#pragma once

void main_init()
{
	std::string path="people/main/";

	People people
	{
		.name=L"王者铜",
		.attributes=
		{
			.HP_lim={1000,5},
			.ATK={20,1},
			.DEF={20,0},
			.HARD={50,0},
			.SPEED={250,0},
			.max_jump_cnt={2,0}
		},
		.阵营=0,
		.freeze_protection_trigger_cnt=3,
		.box={{-100,-117},{100,180}},
		.armature=
		{
			.bone=
			{
				.name="body",
				.file_name=path+"body",
				.anchor={0.5,0.5},
				.pos={500,600},
				.zorder=100
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
							.anchor = {0.75,0.37},
							.pos = {56,99},
							.zorder = 1,
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
							.anchor={0.7,0.8},
							.pos={31,88},
							.zorder=2,
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
										.anchor = {0.7,0.9},
										.pos = {5,2},
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
							.anchor={0.2,0.8},
							.pos={60,88},
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
										.anchor = {0.2,0.9},
										.pos = {10,2},
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
							.anchor={0.5,0.75},
							.pos={37,34},
							.zorder=-1
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
										.anchor = {0.75,0.9},
										.pos = {5,3},
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
							.anchor={0.5,0.75},
							.pos={62,34},
							.zorder=-1,
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
										.anchor = {0.5,0.9},
										.pos = {9,1},
										.zorder = -1
									}
								}
							}
						}
					}
				},
				{
					"crescent_i1",
					Armature
					{
						.bone =
						{
							.name = "crescent_i1",
							.file_name = path + "crescent_i1",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible=false,
							.scale={1,1},
						}
					}
				},
				{
					"crescent_i2",
					Armature
					{
						.bone =
						{
							.name = "crescent_i2",
							.file_name = path + "crescent_i2",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible=false,
							.scale={1,1},
						}
					}
				},
				{
					"crescent_i3",
					Armature
					{
						.bone =
						{
							.name = "crescent_i3",
							.file_name = path + "crescent_i3",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible=false,
							.scale={1,1},
						}
					}
				},
				{
					"atk11",
					Armature
					{
						.bone =
						{
							.name = "atk11",
							.file_name = path + "crescent/atk11",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible=false,
							.scale={1,1},
						}
					}
				},
				{
					"atk12",
					Armature
					{
						.bone =
						{
							.name = "atk12",
							.file_name = path + "crescent/atk12",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible=false,
							.scale={1,1},
						}
					}
				},
				{
					"atk13",
					Armature
					{
						.bone =
						{
							.name = "atk13",
							.file_name = path + "crescent/atk13",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible=false,
							.scale={1,1},
						}
					}
				},
				{
					"atk14",
					Armature
					{
						.bone =
						{
							.name = "atk14",
							.file_name = path + "crescent/atk14",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible=false,
							.scale={1,1},
						}
					}
				},
				{
					"atk15",
					Armature
					{
						.bone =
						{
							.name = "atk15",
							.file_name = path + "crescent/atk15",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible=false,
							.scale={1,1},
						}
					}
				},
				{
					"atk16",
					Armature
					{
						.bone =
						{
							.name = "atk16",
							.file_name = path + "crescent/atk16",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible=false,
							.scale={1,1},
						}
					}
				},
				{
					"atk21",
					Armature
					{
						.bone =
						{
							.name = "atk21",
							.file_name = path + "crescent/atk21",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible=false,
							.scale={1,1},
						}
					}
				},
				{
					"atk22",
					Armature
					{
						.bone =
						{
							.name = "atk22",
							.file_name = path + "crescent/atk22",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible=false,
							.scale={1,1},
						}
					}
				},
				{
					"atk23",
					Armature
					{
						.bone =
						{
							.name = "atk23",
							.file_name = path + "crescent/atk23",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible=false,
							.scale={1,1},
						}
					}
				},
				{
					"atk24",
					Armature
					{
						.bone =
						{
							.name = "atk24",
							.file_name = path + "crescent/atk24",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible=false,
							.scale={1,1},
						}
					}
				},
				{
					"atk25",
					Armature
					{
						.bone =
						{
							.name = "atk25",
							.file_name = path + "crescent/atk25",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible=false,
							.scale={1,1},
						}
					}
				},
				{
					"atk26",
					Armature
					{
						.bone =
						{
							.name = "atk26",
							.file_name = path + "crescent/atk26",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible=false,
							.scale={1,1},
						}
					}
				},
				{
					"atk27",
					Armature
					{
						.bone =
						{
							.name = "atk27",
							.file_name = path + "crescent/atk27",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible=false,
							.scale={1,1},
						}
					}
				},
				{
					"atk31",
					Armature
					{
						.bone =
						{
							.name = "atk31",
							.file_name = path + "crescent/atk31",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible=false,
							.scale={1,1},
						}
					}
				},
				{
					"atk32",
					Armature
					{
						.bone =
						{
							.name = "atk32",
							.file_name = path + "crescent/atk32",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible=false,
							.scale={1,1},
						}
					}
				},
				{
					"atk33",
					Armature
					{
						.bone =
						{
							.name = "atk33",
							.file_name = path + "crescent/atk33",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible=false,
							.scale={1,1},
						}
					}
				},
				{
					"atk34",
					Armature
					{
						.bone =
						{
							.name = "atk34",
							.file_name = path + "crescent/atk34",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible=false,
							.scale={1,1},
						}
					}
				},
				{
					"atk35",
					Armature
					{
						.bone =
						{
							.name = "atk35",
							.file_name = path + "crescent/atk35",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible=false,
							.scale={1,1},
						}
					}
				},
				{
					"atk36",
					Armature
					{
						.bone =
						{
							.name = "atk36",
							.file_name = path + "crescent/atk36",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible=false,
							.scale={1,1},
						}
					}
				},
				{
					"crescent_o6",
					Armature
					{
						.bone =
						{
							.name = "o6",
							.file_name = path + "crescent/o6",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible=false,
							.scale={1,1},
						}
					}
				},
				{
					"crescent_o7",
					Armature
					{
						.bone =
						{
							.name = "o7",
							.file_name = path + "crescent/o7",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible=false,
							.scale={1,1},
						}
					}
				},
				{
					"crescent_o8",
					Armature
					{
						.bone =
						{
							.name = "o8",
							.file_name = path + "crescent/o8",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible=false,
							.scale={1,1},
						}
					}
				},
				{
					"crescent_o9",
					Armature
					{
						.bone =
						{
							.name = "o9",
							.file_name = path + "crescent/o9",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible=false,
							.scale={1,1},
						}
					}
				},
				{
					"e1",
					Armature
					{
						.bone =
						{
							.name = "e1",
							.file_name = path + "baroque_ie/e1",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible = false,
							.scale = {1,1},
						}
					}
				},
				{
					"e2",
					Armature
					{
						.bone =
						{
							.name = "e2",
							.file_name = path + "baroque_ie/e2",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible = false,
							.scale = {1,1},
						}
					}
				},
				{
					"e3",
					Armature
					{
						.bone =
						{
							.name = "e3",
							.file_name = path + "baroque_ie/e3",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible = false,
							.scale = {1,1},
						}
					}
				},
				{
					"e4",
					Armature
					{
						.bone =
						{
							.name = "e4",
							.file_name = path + "baroque_ie/e4",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible = false,
							.scale = {1,1},
						}
					}
				},
				{
					"e5",
					Armature
					{
						.bone =
						{
							.name = "e5",
							.file_name = path + "baroque_ie/e5",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible = false,
							.scale = {1,1},
						}
					}
				},
				{
					"e6",
					Armature
					{
						.bone =
						{
							.name = "e6",
							.file_name = path + "baroque_ie/e6",
							.anchor = {0.5,0.5},
							.pos = {60,106},
							.zorder = 10,
							.visible = false,
							.scale = {1,1},
						}
					}
				},
			}
		},
		.default_ms="general",

	};
	people.weapons[0]="crescent";
	people.weapons[1]="baroque";
	people.weapons[2]="sword";

	people.skill[1]="p_main_dash";

	people_table["main"]=std::move(people);
}
