#pragma once

W_Crescent_IE_MS::W_Crescent_IE_MS(Scene*scene,People*people):Move_State(scene,people){cnt=0;}
void W_Crescent_IE_MS::run(){
	cnt++;
	if(cnt>mx){
		people->erase_effect(people->handle);
		return;
	}
}

W_Crescent_I_MS::W_Crescent_I_MS(Scene*scene,People*people):
	Move_State(scene, people, 10)
{}

void W_Crescent_I_MS::load()
{
	cnt=0;
	atk21=&people->armature["atk21"];
	atk22=&people->armature["atk22"];
	atk23=&people->armature["atk23"];
	atk24=&people->armature["atk24"];
	atk25=&people->armature["atk25"];
	atk26=&people->armature["atk26"];
	atk27=&people->armature["atk27"];
}

void W_Crescent_I_MS::run()
{
	cnt++;
	people->armature.set_opacity(0);
	if(cnt<=5){
		(atk21->bone).visible=true;
		atk21->set_opacity(255);
	}else if(cnt<=10){
		(atk21->bone).visible=false;
		(atk22->bone).visible=true;
		atk22->set_opacity(255);
	}else if(cnt<=15){
		(atk22->bone).visible=false;
		(atk23->bone).visible=true;
		atk23->set_opacity(255);
		if(cnt==12)people->find_and_attack({ {50,-200},{200,100} }, Damage(people->ATK() * 1.5), 200, {-500,0 }, 25, 50);
	}else if(cnt<=20){
		(atk23->bone).visible=false;
		(atk24->bone).visible=true;
		atk24->set_opacity(255);
		people->displace({6,0});
	}else if(cnt<=25){
		(atk24->bone).visible=false;
		(atk25->bone).visible=true;
		atk25->set_opacity(255);
		people->displace({10,0});
	}else if(cnt<=30){
		(atk25->bone).visible=false;
		(atk26->bone).visible=true;
		atk26->set_opacity(255);
		people->displace({6,0});
		if(cnt==28)people->find_and_attack({ {50,-100},{200,200} }, Damage(people->ATK() * 1.5), 200, {200,0 }, 25, 50);
	}else if(cnt<=35){
		(atk26->bone).visible=false;
		(atk21->bone).visible=true;
		atk21->set_opacity(255);
	}else if(cnt<=40){
		(atk21->bone).visible=false;
		(atk22->bone).visible=true;
		atk22->set_opacity(255);
	}else if(cnt<=45){
		(atk22->bone).visible=false;
		(atk23->bone).visible=true;
		atk23->set_opacity(255);
		if(cnt==43)people->find_and_attack({ {50,-200},{200,100} }, Damage(people->ATK() * 1.5), 200, {-400,0 }, 25, 50);
	}else if(cnt<=50){
		(atk23->bone).visible=false;
		(atk24->bone).visible=true;
		atk24->set_opacity(255);
	}else if(cnt<=55){
		(atk24->bone).visible=false;
		(atk25->bone).visible=true;
		atk25->set_opacity(255);
	}else if(cnt<=60){
		(atk25->bone).visible=false;
		(atk26->bone).visible=true;
		atk26->set_opacity(255);
		if(cnt==58)people->find_and_attack({ {50,-100},{200,200} }, Damage(people->ATK() * 1.5), 200, {1200,0 }, 25, 50);
	}else if(cnt<=70){
		(atk26->bone).visible=false;
		(atk27->bone).visible=true;
		atk27->set_opacity(255);
	}else{
		people->set_ms(people->default_ms);
	}

	if(cnt==1){
		auto idx = people->create_effect<W_Crescent_IE_MS>({.bone = {.file_name = "weapon/crescent/atk21",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
		(static_cast<W_Crescent_IE_MS*>(((People*)idx)->default_ms))->mx=2;
	}else if(cnt==3){
		auto idx = people->create_effect<W_Crescent_IE_MS>({.bone = {.file_name = "weapon/crescent/atk22",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
		(static_cast<W_Crescent_IE_MS*>(((People*)idx)->default_ms))->mx=3;
	}else if(cnt==6){
		auto idx = people->create_effect<W_Crescent_IE_MS>({.bone = {.file_name = "weapon/crescent/atk23",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
		(static_cast<W_Crescent_IE_MS*>(((People*)idx)->default_ms))->mx=4;
	}else if(cnt==10){
		auto idx = people->create_effect<W_Crescent_IE_MS>({.bone = {.file_name = "weapon/crescent/atk24",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
		(static_cast<W_Crescent_IE_MS*>(((People*)idx)->default_ms))->mx=4;
	}else if(cnt==14){
		auto idx = people->create_effect<W_Crescent_IE_MS>({.bone = {.file_name = "weapon/crescent/atk25",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
		(static_cast<W_Crescent_IE_MS*>(((People*)idx)->default_ms))->mx=4;
	}else if(cnt==18){
		auto idx = people->create_effect<W_Crescent_IE_MS>({.bone = {.file_name = "weapon/crescent/atk26",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
		(static_cast<W_Crescent_IE_MS*>(((People*)idx)->default_ms))->mx=4;
	}else if(cnt==22){
		auto idx = people->create_effect<W_Crescent_IE_MS>({.bone = {.file_name = "weapon/crescent/atk27",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
		(static_cast<W_Crescent_IE_MS*>(((People*)idx)->default_ms))->mx=4;
	}else if(cnt==26){
		auto idx = people->create_effect<W_Crescent_IE_MS>({.bone = {.file_name = "weapon/crescent/atk28",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
		(static_cast<W_Crescent_IE_MS*>(((People*)idx)->default_ms))->mx=4;
	}else if(cnt==30){
		auto idx = people->create_effect<W_Crescent_IE_MS>({.bone = {.file_name = "weapon/crescent/atk29",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
		(static_cast<W_Crescent_IE_MS*>(((People*)idx)->default_ms))->mx=3;
	}else if(cnt==33){
		auto idx = people->create_effect<W_Crescent_IE_MS>({.bone = {.file_name = "weapon/crescent/atk21",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
		(static_cast<W_Crescent_IE_MS*>(((People*)idx)->default_ms))->mx=3;
	}else if(cnt==36){
		auto idx = people->create_effect<W_Crescent_IE_MS>({.bone = {.file_name = "weapon/crescent/atk22",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
		(static_cast<W_Crescent_IE_MS*>(((People*)idx)->default_ms))->mx=4;
	}else if(cnt==40){
		auto idx = people->create_effect<W_Crescent_IE_MS>({.bone = {.file_name = "weapon/crescent/atk23",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
		(static_cast<W_Crescent_IE_MS*>(((People*)idx)->default_ms))->mx=4;
	}else if(cnt==44){
		auto idx = people->create_effect<W_Crescent_IE_MS>({.bone = {.file_name = "weapon/crescent/atk24",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
		(static_cast<W_Crescent_IE_MS*>(((People*)idx)->default_ms))->mx=4;
	}else if(cnt==48){
		auto idx = people->create_effect<W_Crescent_IE_MS>({.bone = {.file_name = "weapon/crescent/atk25",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
		(static_cast<W_Crescent_IE_MS*>(((People*)idx)->default_ms))->mx=3;
	}else if(cnt==51){
		auto idx = people->create_effect<W_Crescent_IE_MS>({.bone = {.file_name = "weapon/crescent/atk26",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
		(static_cast<W_Crescent_IE_MS*>(((People*)idx)->default_ms))->mx=3;
	}else if(cnt==54){
		auto idx = people->create_effect<W_Crescent_IE_MS>({.bone = {.file_name = "weapon/crescent/atk27",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
		(static_cast<W_Crescent_IE_MS*>(((People*)idx)->default_ms))->mx=3;
	}else if(cnt==57){
		auto idx = people->create_effect<W_Crescent_IE_MS>({.bone = {.file_name = "weapon/crescent/atk28",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
		(static_cast<W_Crescent_IE_MS*>(((People*)idx)->default_ms))->mx=3;
	}else if(cnt==60){
		auto idx = people->create_effect<W_Crescent_IE_MS>({.bone = {.file_name = "weapon/crescent/atk29",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
		(static_cast<W_Crescent_IE_MS*>(((People*)idx)->default_ms))->mx=4;
	}
}

void W_Crescent_I_MS::unload()
{	
	(atk21->bone).visible=false;
	(atk22->bone).visible=false;
	(atk23->bone).visible=false;
	(atk24->bone).visible=false;
	(atk25->bone).visible=false;
	(atk26->bone).visible=false;
	(atk27->bone).visible=false;
	(*people).armature.set_opacity(255);
}

W_Crescent_I::W_Crescent_I(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con):
	Skill(scene, people, weapon, con),
	ms(scene, people)
{}

void W_Crescent_I::use(bool down,bool up)
{
	if(people->on_floor())people->set_ms(&ms);
}

bool W_Crescent_I::can_use(bool down,bool up)
{
	return people->on_floor();
}

void w_crescent_i_init()
{
	Config::Skill skill
	{
		.name = L"",
		.creator = [](const Config::Skill& con,Scene* scene,People* people,Weapon* weapon)->Skill*
		{
			return new W_Crescent_I(scene,people,weapon,con);
		}
	};

	skill_table["w_crescent_i"] = std::move(skill);
}