#pragma once

Test::Test(const Config::Weapon&con,Scene*scene,People*people)
	:Weapon(con,scene,people)
{
	people->armature["front_upper_arm"].insert("test",con.armature);
}

void Test::load()
{
	people->armature["front_upper_arm"]["test"].bone.visible=true;
}

void Test::unload()
{
	people->armature["front_upper_arm"]["test"].bone.visible=false;
}

void test_init()
{
	Config::Weapon weapon
	{
		.name=L"测试武器",
		.armature=
		{
			.bone=
			{
				.name="test",
				.file_name="weapon/test/test",
				.anchor={0.16,0.1},
				.pos={3,10},
				.visible=false
			}
		},
		.creator=[](const Config::Weapon&con,Scene*scene,People*people)->Weapon*
		{
			return new Test(con,scene,people);
		}
	};
	weapon.skill[0]="w_test_attack";
	weapon_table["test"]=std::move(weapon);
}
