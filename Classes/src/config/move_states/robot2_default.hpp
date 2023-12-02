#pragma once

namespace Robot2_Default
{

	struct MS:AI_MS
	{
		s2 scnt;
		MS(Scene*scene,People*people);
		virtual void load();
		virtual void run();
		virtual void unload();
	};

};

void p_robot2_attack_init();