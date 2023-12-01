#pragma once
/*==================================斜向上=============================================*/
W_Crescent_U_MS::W_Crescent_U_MS(Scene*scene,People*people):
	Move_State(scene, people, 100)
{}

void W_Crescent_U_MS::load()
{
	cnt=0;
	uarm = &people->armature["front_upper_arm"].bone;
	larm = &people->armature["front_upper_arm"]["front_lower_arm"].bone;
	wp = &people->armature["front_upper_arm"]["front_lower_arm"]["crescent"].bone;
	body =&people->armature.bone;
	blarm =&people->armature["back_upper_arm"].bone;
	fuleg=&people->armature["front_upper_leg"].bone;
	flleg=&people->armature["front_upper_leg"]["front_lower_leg"].bone;
	buleg=&people->armature["back_upper_leg"].bone;
	blleg=&people->armature["back_upper_leg"]["back_lower_leg"].bone;
	p1=&people->armature["front_upper_arm"]["front_lower_arm"]["crescent"]["u1"].bone;
	p2=&people->armature["front_upper_arm"]["front_lower_arm"]["crescent"]["u2"].bone;
	p3=&people->armature["front_upper_arm"]["front_lower_arm"]["crescent"]["u3"].bone;
}

void W_Crescent_U_MS::run()
{
	cnt++;

	if(cnt<=5){
		fuleg->rotation-=15;
		flleg->rotation+=15;
		buleg->rotation-=1;
		blleg->rotation+=1;
	}else if(5<cnt&&cnt<=25){
		body->rotation-=18;
		if(cnt<=10)p1->visible=true;
		else if(cnt<=20){
			p1->visible=false;
			p2->visible=true;
		}else if(cnt<=25){
			p2->visible=false;
			p3->visible=true;
		}

		people->displace({12,24});
		people->v_y=0;

		if(cnt%4==2)people->find_and_attack({{-75,-75},{75,75}},Damage(people->ATK()*1),200,{70,1100},25,50);
	}else if(25<cnt&&cnt<=30){
		p3->visible=false;
		fuleg->rotation+=15;
		flleg->rotation-=15;
		buleg->rotation+=1;
		blleg->rotation-=1;
	}else{
		people->set_ms(people->default_ms);
	}
}

void W_Crescent_U_MS::unload()
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
	p1->visible =false;
	p2->visible =false;
	p3->visible =false;
	cnt=0;
}


/*==================================竖直向上=============================================*/
W_Crescent_UW_MS::W_Crescent_UW_MS(Scene*scene,People*people):
	Move_State(scene, people, 100)
{}

void W_Crescent_UW_MS::load()
{
	cnt=0;
	uarm = &people->armature["front_upper_arm"].bone;
	larm = &people->armature["front_upper_arm"]["front_lower_arm"].bone;
	wp = &people->armature["front_upper_arm"]["front_lower_arm"]["crescent"].bone;
	body =&people->armature.bone;
	blarm =&people->armature["back_upper_arm"].bone;
	fuleg=&people->armature["front_upper_leg"].bone;
	flleg=&people->armature["front_upper_leg"]["front_lower_leg"].bone;
	buleg=&people->armature["back_upper_leg"].bone;
	blleg=&people->armature["back_upper_leg"]["back_lower_leg"].bone;
	p1=&people->armature["front_upper_arm"]["front_lower_arm"]["crescent"]["u1"].bone;
	p2=&people->armature["front_upper_arm"]["front_lower_arm"]["crescent"]["u2"].bone;
	p3=&people->armature["front_upper_arm"]["front_lower_arm"]["crescent"]["u3"].bone;
}

void W_Crescent_UW_MS::run()
{
	cnt++;

	if(cnt<=5){
		fuleg->rotation-=15;
		flleg->rotation+=15;
		buleg->rotation-=1;
		blleg->rotation+=1;
	}else if(5<cnt&&cnt<=25){
		body->rotation-=18;
		if(cnt<=10)p1->visible=true;
		else if(cnt<=20){
			p1->visible=false;
			p2->visible=true;
		}else if(cnt<=25){
			p2->visible=false;
			p3->visible=true;
		}

		people->displace({2,20});
		people->v_y=0;

		if(cnt%4==2)people->find_and_attack({{-75,-75},{75,75}},Damage(people->ATK()*1),200,{10,1000},25,50);
	}else if(25<cnt&&cnt<=30){
		p3->visible=false;
		fuleg->rotation+=15;
		flleg->rotation-=15;
		buleg->rotation+=1;
		blleg->rotation-=1;
	}else{
		people->set_ms(people->default_ms);
	}
}

void W_Crescent_UW_MS::unload()
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
	p1->visible =false;
	p2->visible =false;
	p3->visible =false;
	cnt=0;
}
/*==================================斜向下=============================================*/
W_Crescent_US_MS::W_Crescent_US_MS(Scene*scene,People*people):
	Move_State(scene, people, 100)
{}

void W_Crescent_US_MS::load()
{
	cnt=0;
	uarm = &people->armature["front_upper_arm"].bone;
	larm = &people->armature["front_upper_arm"]["front_lower_arm"].bone;
	wp = &people->armature["front_upper_arm"]["front_lower_arm"]["crescent"].bone;
	body =&people->armature.bone;
	blarm =&people->armature["back_upper_arm"].bone;
	fuleg=&people->armature["front_upper_leg"].bone;
	flleg=&people->armature["front_upper_leg"]["front_lower_leg"].bone;
	buleg=&people->armature["back_upper_leg"].bone;
	blleg=&people->armature["back_upper_leg"]["back_lower_leg"].bone;
	p1=&people->armature["front_upper_arm"]["front_lower_arm"]["crescent"]["u1"].bone;
	p2=&people->armature["front_upper_arm"]["front_lower_arm"]["crescent"]["u2"].bone;
	p3=&people->armature["front_upper_arm"]["front_lower_arm"]["crescent"]["u3"].bone;
}

void W_Crescent_US_MS::run()
{
	cnt++;

	if(cnt<=5){
		fuleg->rotation-=15;
		flleg->rotation+=15;
		buleg->rotation-=1;
		blleg->rotation+=1;
	}else if(5<cnt&&cnt<=25){
		body->rotation+=18;
		if(cnt<=10)p1->visible=true;
		else if(cnt<=20){
			p1->visible=false;
			p2->visible=true;
		}else if(cnt<=25){
			p2->visible=false;
			p3->visible=true;
		}

		people->displace({24,-24});
		people->v_y=0;

		if(cnt%4==2)people->find_and_attack({{-75,-75},{75,75}},Damage(people->ATK()*1),200,{400,-400},30,50);
	}else if(25<cnt&&cnt<=30){
		p3->visible=false;
		fuleg->rotation+=15;
		flleg->rotation-=15;
		buleg->rotation+=1;
		blleg->rotation-=1;
	}else{
		people->set_ms(people->default_ms);
	}
}

void W_Crescent_US_MS::unload()
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
	p1->visible =false;
	p2->visible =false;
	p3->visible =false;
	cnt=0;
}
//
/*==================================U=============================================*/
W_Crescent_U::W_Crescent_U(Scene* scene, People* people, Weapon* weapon, const ::Config::Skill& con):
	Skill(scene, people, weapon, con),
	ms(scene, people),ms_us(scene,people),ms_uw(scene,people)
{}

void W_Crescent_U::use(bool down,bool up){
	if(!people->on_floor()){
		if(down){
			// if(up)work(),U+W+S
			people->set_ms(&ms_us);//U+S
		}
	}else{
		if(up)people->set_ms(&ms_uw);
		else people->set_ms(&ms);
	}
}

bool W_Crescent_U::can_use(bool down,bool up)
{
	if(!people->on_floor()){
		if(down){
			// if(up)work(),U+W+S
			return true;
		}else{
			return false;
		}
	}else{
		return true;
	}
}

void w_crescent_u_init()
{
	Config::Skill skill
	{
		.name = L"",
		.creator = [](const Config::Skill& con,Scene* scene,People* people,Weapon* weapon)->Skill*
		{
			return new W_Crescent_U(scene,people,weapon,con);
		}
	};

	skill_table["w_crescent_u"] = std::move(skill);
}