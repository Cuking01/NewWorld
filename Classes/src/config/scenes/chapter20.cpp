#pragma once

Chapter20::Chapter20(::Scene::Scene*scene):Progress(scene){
	scene->people_max={7800,1500};
	scene->camera_min={0,0};
	scene->camera_max={7000,200};
	add_task(
	{
		true,
		[this]()
		{
			return j==0;
		},
		[this]()
		{
			this->scene->main->armature.bone.visible=false;
			this->scene->main->alive=false;
			this->scene->dialog_file="dialog20_1";
			this->scene->set_ss(&this->scene->dialog_ss);
			j=1;
		}
	});

	//战斗
	add_task(
	{
		true,
		[this]()
		{
			return j==1&&this->scene->ss!=&this->scene->dialog_ss;
		},
		[this]()
		{
			this->scene->main->armature.bone.visible=true;
			this->scene->main->alive=true;
			this->scene->dialog_file="";
			for(int i=0;i<3;i++)
			{
				auto*p=(::Scene::People*)this->scene->create_people("bear",0);
				p->pos.x-=i*400;
			}
			j=2;
		}
	});
	add_task(
	{
		true,
		[this]()
		{
			return j==2&& this->scene->peoples.size()==1&&this->scene->main->alive;
		},
		[this]()
		{
			this->scene->main->armature.bone.visible=false;
			this->scene->dialog_file="dialog20_3";
			this->scene->set_ss(&this->scene->dialog_ss);
			j=3;
		}
	});
	//蜥蜴！
	add_task(
	{
		true,
		[this]()
		{
			return j==3&& this->scene->ss!=&this->scene->dialog_ss &&this->scene->peoples.size()==1&&this->scene->main->alive;
		},
		[this]()
		{
			this->scene->main->armature.bone.visible=true;
			for(int i=0;i<4;i++)
			{
				auto*p=(::Scene::People*)this->scene->create_people("redlizard",0);
				p->pos.x-=i*400;
			}
			for(int i=0;i<2;i++)
			{
				auto*p=(::Scene::People*)this->scene->create_people("bear",0);
				p->pos.x-=i*500;
			}
			j=4;
		}
	});
	//和商人对话
	add_task(
	{
		true,
		[this]()
		{
			return j==4&& this->scene->peoples.size()==1&&this->scene->main->alive;
		},
		[this]()
		{
			this->scene->main->armature.bone.visible=false;
			this->scene->dialog_file="dialog20_2";
			this->scene->set_ss(&this->scene->dialog_ss);
			j=5;
		}
	});
	//结束
	add_task
	({
		true,
		[this]()
		{
			return j==5&&this->scene->peoples.size()==1&&this->scene->main->alive&&this->scene->ss!=&this->scene->dialog_ss;
		},
		[this]()
		{
			this->scene->main->armature.bone.visible=true;
			this->scene->dialog_file="victory";
			this->scene->set_ss(&this->scene->dialog_ss);
			j=6;
		}
	});

	add_task
	({
		true,
		[this]()
		{
			return j==6&&this->scene->ss!=&this->scene->dialog_ss;
		},
		[this]()
		{
			this->scene->bgm_file="",
			this->scene->dialog_file="";
			this->scene->end();
		},
	});
	
}

void chapter20_init(){
	Config::Scene scene{
		.background_file="background/mine0",
		.prospect_file="background/mine1",
		.prospect_scale=0.25,
		.main="main",
		.initor=[](::Scene::Scene*scene){
			auto*p=new Chapter20(scene);
			scene->progress=p;
		}
	};
	scene_table["chapter20"]=std::move(scene);
}
