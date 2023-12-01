#pragma once

People::People(Scene*scene,const ::Config::People& con,s2 level):
	Attributes(scene,con.attributes,level),
	scene(scene),
	阵营(con.阵营),
	new_event(scene,this),
	event_cache(scene,this),
	level(level),
	fly(con.fly),
	v_y(0),
	dir(Dir::right),
	down_flag(false),
	up_flag(false),
	box(con.box),
	armature(con.armature),
	pos(armature.bone.pos),
	freeze_protection_trigger_cnt(con.freeze_protection_trigger_cnt),
	hp(HP_lim()),
	jump_cnt(0),
	alive(true),
	freeze_protection(0),
	cant_be_attack(0),
	ms(nullptr),
	weapon_id(-1),
	default_ms(::Config::create_ms(con.default_ms,scene,this)),
	freeze_ms(scene,this),
	jumping_ms(scene,this),
	death_ms(scene,this)
{
	int i=0;
	for(auto&p:skill)
		p=::Config::create_skill(con.skill[i++],scene,this,nullptr);
	i=0;
	for(auto&p:weapons)
		p=::Config::create_weapon(con.weapons[i++],scene,this);
	if(con.initor)
		con.initor(this);
	set_ms(default_ms);
}

People::~People()
{
	delete default_ms;
	for(auto p:skill)
		delete p;
	for(auto p:weapons)
		delete p;
}

void People::reduce_hp(f3 damage)
{
	hp-=damage;
	if(hp<eps)
	{
		alive=false;
		set_ms(&death_ms);
	}
}

bool People::on_floor() const
{
	return pos.y+box.l.y<scene->people_min.y+eps;
}

Skill*People::get_skill(s2 id)
{
	if(id<0||id>=people_skill_num+weapon_skill_num)return nullptr;
	if(id<people_skill_num)return skill[id];
	auto*weapon=get_weapon();
	if(weapon)return weapon->skill[id-people_skill_num];
	return nullptr;
}

Weapon*People::get_weapon()
{
	if(weapon_id<0||weapon_id>=people_weapon_num)return nullptr;
	return weapons[weapon_id];
}

void People::set_weapon(s2 id)
{
	if(weapon_id==id)return;
	if(id<0||id>=5)return;
	if(weapons[id]==nullptr)return;

	auto*weapon=get_weapon();
	if(weapon)weapon->unload();
	weapon_id=id;
	weapons[id]->load();
}

void People::set_ms(Move_State*nms)
{
	if(nms==nullptr||ms==nms)return;
	if(ms)ms->unload();
	ms=nms;
	nms->load();
}

template<typename MS_T>
Handle People::create_effect(Armature armature)
{
	Config::people_table["effect"].armature=std::move(armature);
	People*people=scene->create_people("effect",level);
	people->阵营=阵营;
	people->dir=dir;
	people->cant_be_attack=1;
	people->default_ms=new MS_T(scene,people);
	people->set_ms(people->default_ms);
	static_cast<Attributes&>(*people)=static_cast<Attributes&>(*this);
	
	return people->handle;
}

void People::erase_effect(u2 key)
{
	scene->erase_people(key);
}

std::vector<People*> People::find_enemy(Bounding_Box box)
{
	auto tmp=scene->find_people(pos+(dir==Dir::left?box.flipped_x():box),阵营);
	return tmp;
}

void People::attack(const std::vector<People*>&enemy,const Damage&damage,f3 hit_intensity,Vector impact_dir,s2 impact_time,s2 freeze_time)
{
	scene->play_se("se/hit.mp3",enemy.size());
	for(People* people:enemy)
		people->ms->be_attack(damage,hit_intensity,dir==Dir::left?impact_dir.flipped_x():impact_dir,impact_time,freeze_time);
}
void People::attack(const std::vector<People*>&enemy,const Damage&damage)
{
	attack(enemy,damage,200,{0,0},0,50);
}
void People::find_and_attack(Bounding_Box box,const Damage&damage,f3 hit_intensity,Vector impact_dir,s2 impact_time,s2 freeze_time)
{
	attack(find_enemy(box),damage,hit_intensity,impact_dir,impact_time,freeze_time);
}
void People::find_and_attack(Bounding_Box box,const Damage&damage)
{
	attack(find_enemy(box),damage);
}

void People::be_attack(const Damage&damage)
{
	reduce_hp(damage.x/(1+DEF()*0.01));
}

void People::move(Dir dir)
{
	this->dir=dir;
	displace(Vector{0.01*SPEED(),0});
}

void People::move(Vector dir)
{
	bool flag=on_floor();

	pos+=dir;
	if(on_floor())
	{
		pos.y=scene->people_min.y-box.l.y;
		if(!flag)when_back_to_floor();
	}
	if(pos.x+box.l.x<scene->people_min.x)
		pos.x=scene->people_min.x-box.l.x;
	if(pos.x+box.r.x>scene->people_max.x)
		pos.x=scene->people_max.x-box.r.x;
	if(pos.y+box.r.y>scene->people_max.y)
		pos.y=scene->people_max.y-box.r.y;

}

void People::displace(Vector dir)
{
	if(this->dir==Dir::left)dir=dir.flipped_x();
	move(dir);
}

void People::jump()
{
	if(jump_cnt==0&&!on_floor())jump_cnt++;
	jump_cnt++;
	if(on_floor())
		v_y=600;
	else
		v_y=450;
	set_ms(&jumping_ms);
}
