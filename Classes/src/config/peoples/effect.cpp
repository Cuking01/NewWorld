#pragma once

void effect_init()
{
	People people
	{
		.name=L"",
		.attributes={},
		.阵营=0,
		.fly=true,
		.freeze_protection_trigger_cnt=-1,
		.box={{inf,inf},{-inf,-inf}},
		.default_ms="",
	};

	people_table["effect"]=std::move(people);
}
