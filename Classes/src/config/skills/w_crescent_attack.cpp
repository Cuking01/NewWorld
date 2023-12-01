#pragma once
//=============================平a特效1==================================
W_Crescent_AE1_MS::W_Crescent_AE1_MS(Scene*scene,People*people):Move_State(scene,people){cnt=0;}
void W_Crescent_AE1_MS::run(){
	cnt++;
	if(cnt>mx){
		people->erase_effect(people->handle);
		return;
	}
}
//=============================普通攻击==================================

W_Crescent_Attack_MS::W_Crescent_Attack_MS(Scene* scene, People* people):Move_State(scene, people, 100){}

void W_Crescent_Attack_MS::load(){
	uarm = &people->armature["front_upper_arm"].bone;
	larm = &people->armature["front_upper_arm"]["front_lower_arm"].bone;
	wp = &people->armature["front_upper_arm"]["front_lower_arm"]["crescent"].bone;
	body =&people->armature.bone;
	blarm =&people->armature["back_upper_arm"].bone;
	fuleg=&people->armature["front_upper_leg"].bone;
	flleg=&people->armature["front_upper_leg"]["front_lower_leg"].bone;
	buleg=&people->armature["back_upper_leg"].bone;
	blleg=&people->armature["back_upper_leg"]["back_lower_leg"].bone;
	
	atk11=&people->armature["atk11"];
	atk12=&people->armature["atk12"];
	atk13=&people->armature["atk13"];
	atk14=&people->armature["atk14"];
	atk15=&people->armature["atk15"];
	atk16=&people->armature["atk16"];

	atk21=&people->armature["atk21"];
	atk22=&people->armature["atk22"];
	atk23=&people->armature["atk23"];
	atk24=&people->armature["atk24"];
	atk25=&people->armature["atk25"];
	atk26=&people->armature["atk26"];
	atk27=&people->armature["atk27"];

	atk31=&people->armature["atk31"];
	atk32=&people->armature["atk32"];
	atk33=&people->armature["atk33"];
	atk34=&people->armature["atk34"];
	atk35=&people->armature["atk35"];
	atk36=&people->armature["atk36"];

	people->v_y = 0;
	j = 0;
	cnt = 0;
	next_flag = 0;
	uarm->rotation = 0;
	larm->rotation = 0;
	wp->rotation = -10;
	wp->scale = { 1,-1 };
}

void W_Crescent_Attack_MS::run()
{
	cnt++;

	auto j1 = [this]()
	{
		people->armature.set_opacity(0);
		if(cnt<=4){
			(atk11->bone).visible=true;
			atk11->set_opacity(255);
		}else if(cnt<=9){
			(atk11->bone).visible=false;
			(atk12->bone).visible=true;
			atk12->set_opacity(255);
		}else if(cnt<=15){
			(atk12->bone).visible=false;
			(atk13->bone).visible=true;
			atk13->set_opacity(255);
		}else if(cnt<=21){
			(atk13->bone).visible=false;
			(atk14->bone).visible=true;
			atk14->set_opacity(255);
		}else if(cnt<=27){
			(atk14->bone).visible=false;
			(atk15->bone).visible=true;
			atk15->set_opacity(255);	
			if(cnt==25)people->find_and_attack({ {10,-100},{200,100} }, Damage(people->ATK() * 1.5), 200, {100,0 }, 25, 50);
		}else if(cnt<=33){
			(atk15->bone).visible=false;
			(atk16->bone).visible=true;
			atk16->set_opacity(255);
		}else{
			(atk16->bone).visible=false;
			if(next_flag)j = 1, cnt = 0, next_flag = 0, people->v_y = 0, wp->scale = { 1,1 },people->armature.set_opacity(255);
			else people->set_ms(people->default_ms);
		}

		if(cnt==4){
			auto idx = people->create_effect<W_Crescent_AE1_MS>({.bone = {.file_name = "weapon/crescent/atk11",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
			(static_cast<W_Crescent_AE1_MS*>(((People*)idx)->default_ms))->mx=6;
		}else if(cnt==10){
			auto idx = people->create_effect<W_Crescent_AE1_MS>({.bone = {.file_name = "weapon/crescent/atk12",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
			(static_cast<W_Crescent_AE1_MS*>(((People*)idx)->default_ms))->mx=6;
		}else if(cnt==16){
			auto idx = people->create_effect<W_Crescent_AE1_MS>({.bone = {.file_name = "weapon/crescent/atk13",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
			(static_cast<W_Crescent_AE1_MS*>(((People*)idx)->default_ms))->mx=6;
		}else if(cnt==22){
			auto idx = people->create_effect<W_Crescent_AE1_MS>({.bone = {.file_name = "weapon/crescent/atk14",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
			(static_cast<W_Crescent_AE1_MS*>(((People*)idx)->default_ms))->mx=6;
		}else if(cnt==28){
			auto idx = people->create_effect<W_Crescent_AE1_MS>({.bone = {.file_name = "weapon/crescent/atk15",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
			(static_cast<W_Crescent_AE1_MS*>(((People*)idx)->default_ms))->mx=7;
		}
	};

	auto j2 = [this]()
	{
		people->armature.set_opacity(0);
		if(cnt<=5){
			(atk21->bone).visible=true;
			atk21->set_opacity(255);
		}else if(cnt<=10){
			(atk21->bone).visible=false;
			(atk22->bone).visible=true;
			atk22->set_opacity(255);
		}else if(cnt<=16){
			(atk22->bone).visible=false;
			(atk23->bone).visible=true;
			atk23->set_opacity(255);
			if(cnt==15)people->find_and_attack({ {50,-200},{200,100} }, Damage(people->ATK() * 1.5), 200, {-300,0 }, 25, 50);
		}else if(cnt<=21){
			(atk23->bone).visible=false;
			(atk24->bone).visible=true;
			atk24->set_opacity(255);
			people->displace({6,0});
		}else if(cnt<=27){
			(atk24->bone).visible=false;
			(atk25->bone).visible=true;
			atk25->set_opacity(255);
			people->displace({10,0});
		}else if(cnt<=33){
			(atk25->bone).visible=false;
			(atk26->bone).visible=true;
			atk26->set_opacity(255);
			people->displace({6,0});
			if(cnt==30)people->find_and_attack({ {50,-100},{200,200} }, Damage(people->ATK() * 1.5), 200, {1200,0 }, 25, 50);
		}else if(cnt<=39){
			(atk26->bone).visible=false;
			(atk27->bone).visible=true;
			atk27->set_opacity(255);
		}else{
			(atk27->bone).visible=false;
			if(next_flag)j = 2, cnt = 0, next_flag = 0, people->v_y = 0, wp->scale = { 1,1 },people->armature.set_opacity(255);
			else people->set_ms(people->default_ms);
		}

		if(cnt==1){
			auto idx = people->create_effect<W_Crescent_AE1_MS>({.bone = {.file_name = "weapon/crescent/atk21",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
			(static_cast<W_Crescent_AE1_MS*>(((People*)idx)->default_ms))->mx=2;
		}else if(cnt==3){
			auto idx = people->create_effect<W_Crescent_AE1_MS>({.bone = {.file_name = "weapon/crescent/atk22",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
			(static_cast<W_Crescent_AE1_MS*>(((People*)idx)->default_ms))->mx=3;
		}else if(cnt==6){
			auto idx = people->create_effect<W_Crescent_AE1_MS>({.bone = {.file_name = "weapon/crescent/atk23",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
			(static_cast<W_Crescent_AE1_MS*>(((People*)idx)->default_ms))->mx=4;
		}else if(cnt==10){
			auto idx = people->create_effect<W_Crescent_AE1_MS>({.bone = {.file_name = "weapon/crescent/atk24",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
			(static_cast<W_Crescent_AE1_MS*>(((People*)idx)->default_ms))->mx=5;
		}else if(cnt==15){
			auto idx = people->create_effect<W_Crescent_AE1_MS>({.bone = {.file_name = "weapon/crescent/atk25",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
			(static_cast<W_Crescent_AE1_MS*>(((People*)idx)->default_ms))->mx=5;
		}else if(cnt==20){
			auto idx = people->create_effect<W_Crescent_AE1_MS>({.bone = {.file_name = "weapon/crescent/atk26",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
			(static_cast<W_Crescent_AE1_MS*>(((People*)idx)->default_ms))->mx=5;
		}else if(cnt==25){
			auto idx = people->create_effect<W_Crescent_AE1_MS>({.bone = {.file_name = "weapon/crescent/atk27",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
			(static_cast<W_Crescent_AE1_MS*>(((People*)idx)->default_ms))->mx=5;
		}else if(cnt==30){
			auto idx = people->create_effect<W_Crescent_AE1_MS>({.bone = {.file_name = "weapon/crescent/atk28",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
			(static_cast<W_Crescent_AE1_MS*>(((People*)idx)->default_ms))->mx=5;
		}else if(cnt==35){
			auto idx = people->create_effect<W_Crescent_AE1_MS>({.bone = {.file_name = "weapon/crescent/atk29",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
			(static_cast<W_Crescent_AE1_MS*>(((People*)idx)->default_ms))->mx=5;
		}
	};

	auto j3 = [this]()
	{
		people->armature.set_opacity(0);
		if(cnt<=5){
			(atk31->bone).visible=true;
			atk31->set_opacity(255);
		}else if(cnt<=12){
			(atk31->bone).visible=false;
			(atk32->bone).visible=true;
			if(cnt==10)people->find_and_attack({ {50,-200},{200,50} }, Damage(people->ATK() * 1.5), 200, { -100,0 }, 25, 50);
			atk32->set_opacity(255);
		}else if(cnt<=19){
			(atk32->bone).visible=false;
			(atk33->bone).visible=true;
			atk33->set_opacity(255);
			people->displace({15,10});
		}else if(cnt<=28){
			(atk33->bone).visible=false;
			(atk34->bone).visible=true;
			atk34->set_opacity(255);
			people->displace({18,23});
			if(cnt==25)people->find_and_attack({ {50,-50},{200,200} }, Damage(people->ATK() * 1.5), 200, { 500,0 }, 25, 50);
		}else if(cnt<=37){
			(atk34->bone).visible=false;
			(atk35->bone).visible=true;
			atk35->set_opacity(255);
			people->displace({1,-35});
			if(cnt==35)people->find_and_attack({ {50,-50},{200,200} }, Damage(people->ATK() * 1.5), 200, { 1000,-500 }, 25, 50);
		}else if(cnt<=45){
			(atk35->bone).visible=false;
			(atk36->bone).visible=true;
			atk36->set_opacity(255);
		}else{
			(atk36->bone).visible=false;
			people->set_ms(people->default_ms);
		}

		if(cnt==1){
			auto idx = people->create_effect<W_Crescent_AE1_MS>({.bone = {.file_name = "weapon/crescent/atk31",
				.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
			(static_cast<W_Crescent_AE1_MS*>(((People*)idx)->default_ms))->mx=7;
			
		}else if(cnt==8){
			auto idx = people->create_effect<W_Crescent_AE1_MS>({.bone = {.file_name = "weapon/crescent/atk32",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
			(static_cast<W_Crescent_AE1_MS*>(((People*)idx)->default_ms))->mx=7;
		}else if(cnt==15){
			auto idx = people->create_effect<W_Crescent_AE1_MS>({.bone = {.file_name = "weapon/crescent/atk33",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
			(static_cast<W_Crescent_AE1_MS*>(((People*)idx)->default_ms))->mx=7;
		}else if(cnt==22){
			auto idx = people->create_effect<W_Crescent_AE1_MS>({.bone = {.file_name = "weapon/crescent/atk34",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
			(static_cast<W_Crescent_AE1_MS*>(((People*)idx)->default_ms))->mx=6;
		}else if(cnt==28){
			auto idx = people->create_effect<W_Crescent_AE1_MS>({.bone = {.file_name = "weapon/crescent/atk35",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
			(static_cast<W_Crescent_AE1_MS*>(((People*)idx)->default_ms))->mx=4;
		}else if(cnt==32){
			auto idx = people->create_effect<W_Crescent_AE1_MS>({.bone = {.file_name = "weapon/crescent/atk36",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
			(static_cast<W_Crescent_AE1_MS*>(((People*)idx)->default_ms))->mx=4;
		}else if(cnt==36){
			auto idx = people->create_effect<W_Crescent_AE1_MS>({.bone = {.file_name = "weapon/crescent/atk37",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
			(static_cast<W_Crescent_AE1_MS*>(((People*)idx)->default_ms))->mx=4;
		}else if(cnt==40){
			auto idx = people->create_effect<W_Crescent_AE1_MS>({.bone = {.file_name = "weapon/crescent/atk38",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
			(static_cast<W_Crescent_AE1_MS*>(((People*)idx)->default_ms))->mx=4;
		}else if(cnt==44){
			auto idx = people->create_effect<W_Crescent_AE1_MS>({.bone = {.file_name = "weapon/crescent/atk39",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
			(static_cast<W_Crescent_AE1_MS*>(((People*)idx)->default_ms))->mx=6;
		}
	};

	if (j == 0)j1();
	else if (j == 1)j2();
	else j3();
}

void W_Crescent_Attack_MS::unload()
{
	uarm->rotation = 0;
	larm->rotation = 0;
	wp->rotation = 0;
	wp->scale = { 1,1 };
	body->rotation = 0;
	blarm->rotation = 0;
	fuleg->rotation =0;
	flleg->rotation =0;
	buleg->rotation =0;
	blleg->rotation =0;
	(atk11->bone).visible=false;
	(atk12->bone).visible=false;
	(atk13->bone).visible=false;
	(atk14->bone).visible=false;
	(atk15->bone).visible=false;
	(atk16->bone).visible=false;

	(atk21->bone).visible=false;
	(atk22->bone).visible=false;
	(atk23->bone).visible=false;
	(atk24->bone).visible=false;
	(atk25->bone).visible=false;
	(atk26->bone).visible=false;
	(atk27->bone).visible=false;

	(atk31->bone).visible=false;
	(atk32->bone).visible=false;
	(atk33->bone).visible=false;
	(atk34->bone).visible=false;
	(atk35->bone).visible=false;
	(atk36->bone).visible=false;
	(*people).armature.set_opacity(255);
}

void W_Crescent_Attack_MS::use_skill(s2 id,bool down,bool up)
{
	if (id == people_skill_num + 0)
	{
		if (j == 0)
		{
			next_flag = 1;

		}
		else if (j == 1)
		{
			next_flag = 1;
		}
	}
	else Move_State::use_skill(id,down,up);
}


W_Crescent_Attack::W_Crescent_Attack(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con) :
	Skill(scene, people, weapon, con),
	ms(scene, people)
{}

void W_Crescent_Attack::use(bool down,bool up)
{
	people->set_ms(&ms);
}

void w_crescent_attack_init()
{
	Config::Skill skill
	{
		.name = L"",
		.creator = [](const Config::Skill& con,Scene* scene,People* people,Weapon* weapon)->Skill*
		{
			return new W_Crescent_Attack(scene,people,weapon,con);
		}
	};

	skill_table["w_crescent_attack"] = std::move(skill);
}
