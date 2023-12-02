#pragma once

namespace Bear_Default
{

struct MS:AI_MS
{
	Bone*fleg,*bleg,*farm,*barm;
	MS(Scene*scene,People*people);
	virtual void load();
	virtual void run();
	virtual void unload();
};

};

void bear_default_init();
