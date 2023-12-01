#pragma once

Target_Default_MS::Target_Default_MS(Scene*scene,People*people)
	:AI_MS(scene,people)
{
	attack_d=200;
}


void target_default_init()
{
	ms_table["target_default"]=
	{
		[](Scene*scene,People*people)->Move_State*
		{
			return new Target_Default_MS(scene,people);
		}
	};
}
