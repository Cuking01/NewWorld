#pragma once

namespace Robot2_Default{

	MS::MS(Scene*scene,People*people):AI_MS(scene,people){
		attack_d=600;
	}

	void MS::load(){
		AI_MS::load();
		scnt=0;
	}

	void MS::run(){
		scnt++;
		if(scnt<=100)AI_MS::run();
		else{
			if(scene->rnd()&1)use_skill(0,false,false);
			else scnt=60;
		}
		AI_MS::run();

	}
	void MS::unload()
	{
		AI_MS::unload();
	}

};

void robot2_default_init()
{
	ms_table["robot2_default"]=
	{
		[](Scene*scene,People*people)->Move_State*
		{
			return new Robot2_Default::MS(scene,people);
		}
	};
}