#pragma once

void priest_init()
{
	std::string path="people/priest/";

	People people
	{
		.name=L"牧师",
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
		.box={{-92,-150},{92,125}},
		.armature=
		{
			.bone=
			{
				.name="body",
				.file_name=path+"body",
				.anchor={0.5,0.5},
				.pos={1500,600},
				.zorder = 80
			}
		},
		.default_ms="target_default",

	};

	people_table["priest"]=std::move(people);
}
