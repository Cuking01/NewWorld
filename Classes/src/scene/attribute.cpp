#pragma once

Attribute::Attribute(Scene*scene):Attribute(scene,0){}
Attribute::Attribute(Scene*scene,f3 x):Attribute(scene,x,0,inf){}
Attribute::Attribute(Scene*scene,f3 x,f3 min,f3 max):scene(scene),x(x),min(min),max(max){}

u2 Attribute::add(const Buff&buff)
{
	u2 key=scene->gen_id();
	buffes.add(key,buff);
	return key;
}
void Attribute::erase(u2 key)
{
	buffes.erase(key);
}
Buff* Attribute::find(u2 key)
{
	return buffes.find(key);
}

f3 Attribute::operator()()
{	
	Buff_Helper bh;
	buffes(x,bh);
	f3 tmp=bh(x);
	return std::max(std::min(tmp,max),min);
}

Attributes::Attributes(Scene*scene,const Config::Attributes&con,s2 level):
	HP_lim(scene,con.HP_lim(level),1,inf),
	ATK(scene,con.ATK(level),0,inf),
	DEF(scene,con.DEF(level),-20,inf),
	HARD(scene,con.HARD(level),0,inf),
	SPEED(scene,con.SPEED(level),0,300),
	max_jump_cnt(scene,con.max_jump_cnt(level),1,5)
{}

