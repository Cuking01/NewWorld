#pragma once



void target_init()
{
	std::string path="people/target/";

	People people
	{
		.name=L"target",
		.attributes=
		{
			.HP_lim={1000000,5},
			.ATK={20,1},
			.DEF={20,0},
			.HARD={50,0},
			.SPEED={100,0},
			.max_jump_cnt={2,0}
		},
		.阵营=1,
		.box={{-150,-200},{150,175}},
		.armature=
		{
			.bone=
			{
				.name="body",
				.file_name=path+"body",
				.anchor={0.5,0.5},
				.pos={1500,700},
				.zorder = 74
			},
		},
		.default_ms="target_default",

	};

	people_table["target"]=std::move(people);
}
