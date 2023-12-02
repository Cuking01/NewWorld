#pragma once

namespace Bear_Default
{

	struct MS:AI_MS
	{
		s2 scnt;
		Bone*fleg,*bleg,*farm,*barm;
		MS(Scene*scene,People*people);
		virtual void load();
		virtual void run();
		virtual void unload();
	};

};

void p_bear_attack_init();