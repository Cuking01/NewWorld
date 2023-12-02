#pragma once

W_Crescent_OE_MS::W_Crescent_OE_MS(Scene*scene,People*people):Move_State(scene,people){cnt=0;}
W_Crescent_OE2_MS::W_Crescent_OE2_MS(Scene*scene,People*people):Move_State(scene,people){cnt=0;}
void W_Crescent_OE_MS::run(){
	cnt++;
	people->armature.set_opacity(0);
	people->displace({35,0});
	auto update = [this](std::string s1, std::string s2)
		{
			people->armature[s1].bone.visible = false;
			people->armature[s2].bone.visible = true;
			people->armature[s2].set_opacity(255);
		};
	if(cnt<=8){
		people->armature["o0"].set_opacity(255);
	}else if(cnt<=16){
		update("o0","o1");
	}else if(cnt<=20){
		update("o1","o2");
	}else if(cnt<=24){
		update("o2","o3");
	}else if(cnt<=28){
		update("o3","o4");
	}else if(cnt<=32){
		update("o4","o5");
	}else if(cnt<=35){
		update("o5","o6");
	}else if(cnt<=38){
		update("o6","o7");
	}else if(cnt<=41){
		update("o7","o8");
	}else{
		people->erase_effect(people->handle);
		return;
	}
	if(cnt%4==3)people->find_and_attack({ {-100,-100},{100,100} }, Damage(people->ATK() * 1.5), 200, {250,0 }, 25, 50);
}

void W_Crescent_OE2_MS::run(){
	cnt++;
	people->armature.bone.rotation--;
	if(cnt>mx){
		people->erase_effect(people->handle);
		return;
	}
}

W_Crescent_O_MS::W_Crescent_O_MS(Scene*scene,People*people):Move_State(scene, people, 10){}

void W_Crescent_O_MS::load(){
	cnt=0;
	
	o1=&people->armature["atk11"];
	o2=&people->armature["atk12"];
	o3=&people->armature["atk13"];
	o4=&people->armature["atk14"];
	o5=&people->armature["atk15"];

	o6=&people->armature["crescent_o6"];
	o7=&people->armature["crescent_o7"];
	o8=&people->armature["crescent_o8"];
	o9=&people->armature["crescent_o9"];
}

void W_Crescent_O_MS::run()
{
	cnt++;
	people->armature.set_opacity(0);
	auto update = [](auto* o1, auto* o2)
		{
			o1->bone.visible = false;
			o2->bone.visible = true;
			o2->set_opacity(255);
		};
	if(cnt<=4){
		(o1->bone).visible=true;
		o1->set_opacity(255);
	}else if(cnt<=8){
		update(o1,o2);
	}else if(cnt<=13){
		update(o2,o3);
	}else if(cnt<=18){
		update(o3,o4);
	}else if(cnt<=22){
		update(o4,o5);
		people->displace({4,20});
		if(cnt==20)people->find_and_attack({ {10,-100},{200,100} }, Damage(people->ATK() * 1.5), 200, {250,0 }, 25, 50);
	}else if(cnt<=26){
		update(o5,o6);
		people->displace({0,30});
	}else if(cnt<=29){
		update(o6,o7);
		people->displace({0,35});
	}else if(cnt<=32){
		update(o7,o8);
		if(cnt==30){
			scene->pause_for(20);
			scene->shake(50);
		}
		people->displace({0,30});
	}else if(cnt<=50){
		update(o8,o9);
		people->displace({5,-80});
		o9->set_opacity(255);
		if(cnt==40){
			scene->shake(50);
			
			auto idx = people->create_effect<W_Crescent_OE_MS>(Armature{
				.bone = 
				{
					.file_name = "weapon/crescent/empty",
					.pos = {people->pos.x-50,people->pos.y+100},
					.zorder=100,
				},
				.sons = {
						{
							"o0",
							Armature
							{
								.bone =
								{
									.file_name = "weapon/crescent/o0",
									.anchor={0.5,0.5},
									.pos = {0,0},
									.visible=false,
									.opacity = 0,
								}
							}
						},
						{
							"o1",
							Armature
							{
								.bone =
								{
									.file_name = "weapon/crescent/o1",
									.anchor={0.5,0.5},
									.pos = {0,0},
									.visible=false,
									.opacity = 0,
								}
							}
						},
						{
							"o2",
							Armature
							{
								.bone =
								{
									.file_name = "weapon/crescent/o2",
									.anchor={0.5,0.5},
									.pos = {0,0},
									.visible=false,
									.opacity = 0,
								}
							}
						},
						{
							"o3",
							Armature
							{
								.bone =
								{
									.file_name = "weapon/crescent/o3",
									.anchor={0.5,0.5},
									.pos = {0,0},
									.visible=false,
									.opacity = 0,
								}
							}
						},
						{
							"o4",
							Armature
							{
								.bone =
								{
									.file_name = "weapon/crescent/o4",
									.anchor={0.5,0.5},
									.pos = {0,0},
									.visible=false,
									.opacity = 0,
								}
							}
						},
						{
							"o5",
							Armature
							{
								.bone =
								{
									.file_name = "weapon/crescent/o5",
									.anchor={0.5,0.5},
									.pos = {0,0},
									.visible=false,
									.opacity = 0,
								}
							}
						},
						{
							"o6",
							Armature
							{
								.bone =
								{
									.file_name = "weapon/crescent/o6",
									.anchor={0.5,0.5},
									.pos = {0,0},
									.visible=false,
									.opacity = 0,
								}
							}
						},
						{
							"o7",
							Armature
							{
								.bone =
								{
									.file_name = "weapon/crescent/o7",
									.anchor={0.5,0.5},
									.pos = {0,0},
									.visible=false,
									.opacity = 0,
								}
							}
						},
						{
							"o8",
							Armature
							{
								.bone =
								{
									.file_name = "weapon/crescent/o8",
									.anchor={0.5,0.5},
									.pos = {0,0},
									.visible=false,
									.opacity = 0,
								}
							}
						},
					}
			});
		}
	}else{
		people->set_ms(people->default_ms);
	}

	if(cnt==5){
		auto idx = people->create_effect<W_Crescent_OE2_MS>({.bone = {.file_name = "weapon/crescent/eo0",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
		(static_cast<W_Crescent_OE2_MS*>(((People*)idx)->default_ms))->mx=5;
	}else if(cnt==10){
		auto idx = people->create_effect<W_Crescent_OE2_MS>({.bone = {.file_name = "weapon/crescent/eo1",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
		(static_cast<W_Crescent_OE2_MS*>(((People*)idx)->default_ms))->mx=6;
	}else if(cnt==16){
		auto idx = people->create_effect<W_Crescent_OE2_MS>({.bone = {.file_name = "weapon/crescent/eo2",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
		(static_cast<W_Crescent_OE2_MS*>(((People*)idx)->default_ms))->mx=6;
	}else if(cnt==22){
		auto idx = people->create_effect<W_Crescent_OE2_MS>({.bone = {.file_name = "weapon/crescent/eo3",.anchor={0.5,0.5},.pos = people->pos,.zorder=100}});
		(static_cast<W_Crescent_OE2_MS*>(((People*)idx)->default_ms))->mx=5;
	}

	if(cnt==23){
		auto idx = people->create_effect<W_Crescent_OE2_MS>({.bone = {.file_name = "weapon/crescent/fire0",.anchor={0.5,0.5},.pos = {people->pos.x+120,people->pos.y+100},.zorder=101}});
		(static_cast<W_Crescent_OE2_MS*>(((People*)idx)->default_ms))->mx=3;
	}else if(cnt==26){
		auto idx = people->create_effect<W_Crescent_OE2_MS>({.bone = {.file_name = "weapon/crescent/fire1",.anchor={0.5,0.5},.pos = {people->pos.x+120,people->pos.y+100},.zorder=101}});
		(static_cast<W_Crescent_OE2_MS*>(((People*)idx)->default_ms))->mx=3;
	}else if(cnt==29){
		auto idx = people->create_effect<W_Crescent_OE2_MS>({.bone = {.file_name = "weapon/crescent/fire2",.anchor={0.5,0.5},.pos = {people->pos.x+120,people->pos.y+100},.zorder=101}});
		(static_cast<W_Crescent_OE2_MS*>(((People*)idx)->default_ms))->mx=4;
	}
}

void W_Crescent_O_MS::unload()
{
	(o1->bone).visible=false;
	(o2->bone).visible=false;
	(o3->bone).visible=false;
	(o4->bone).visible=false;
	(o5->bone).visible=false;
	(o6->bone).visible=false;
	(o7->bone).visible=false;
	(o8->bone).visible=false;
	(o9->bone).visible=false;
	(*people).armature.set_opacity(255);
}

W_Crescent_O::W_Crescent_O(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con):
	Skill(scene, people, weapon, con),
	ms(scene, people)
{}

void W_Crescent_O::use(bool down,bool up)
{
	if(people->on_floor())people->set_ms(&ms);
}

bool W_Crescent_O::can_use(bool down,bool up)
{
	return people->on_floor();
}

void w_crescent_o_init()
{
	Config::Skill skill
	{
		.name = L"",
		.creator = [](const Config::Skill& con,Scene* scene,People* people,Weapon* weapon)->Skill*
		{
			return new W_Crescent_O(scene,people,weapon,con);
		}
	};

	skill_table["w_crescent_o"] = std::move(skill);
}