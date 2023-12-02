#pragma once

Chapter10::Chapter10(::Scene::Scene*scene):Progress(scene){
	scene->people_max={9000,1500};
	scene->camera_min={0,0};
	scene->camera_max={7500,200};
	
	add_task(
	{
		true,
		[this]()
		{
			return j==0;
		},
		[this]()
		{
			// this->scene->background_file="background/room",
			this->scene->main->alive=false;
			this->scene->main->armature.bone.visible=false;
			this->scene->dialog_file="dialog10_0";
			this->scene->set_ss(&this->scene->dialog_ss);
			j=1;
		}
	});
	add_task(
	{
		true,
		[this]()
		{
			return j==1&&this->scene->ss!=&this->scene->dialog_ss;
		},
		[this]()
		{
			this->scene->dialog_file="dialog10_1";
			this->scene->set_ss(&this->scene->dialog_ss);
			j=2;
		}
	});
	add_task(
	{
		true,
		[this]()
		{
			return j==2&&this->scene->ss!=&this->scene->dialog_ss;
		},
		[this]()
		{
			this->scene->background_file="background/room";
			this->scene->dialog_file="dialog10_2";
			this->scene->set_ss(&this->scene->dialog_ss);
			j=3;
		}
	});

	add_task(
	{
		true,
		[this]()
		{
			return j==3&&this->scene->ss!=&this->scene->dialog_ss;
		},
		[this]()
		{
			
			this->scene->background_file="background/room_morning";
			this->scene->dialog_file="dialog10_3";
			this->scene->set_ss(&this->scene->dialog_ss);
			j=4;
		}
	});
	//监狱中：
	add_task(
	{
		true,
		[this]()
		{
			return j==4&&this->scene->ss!=&this->scene->dialog_ss;
		},
		[this]()
		{
			this->scene->background_file="background/test",
			this->scene->prospect_file="background/test_prospect",
			this->scene->prospect_scale=0.5,
			this->scene->bgm_file="music/out_of_darkness.mp3",

			this->scene->dialog_file="dialog10_4";
			this->scene->set_ss(&this->scene->dialog_ss);
			j=5;
		}
	});

	//战斗
	add_task(
	{
		true,
		[this]()
		{
			return j==5&&this->scene->ss!=&this->scene->dialog_ss;
		},
		[this]()
		{
			this->scene->main->alive=true;
			this->scene->main->armature.bone.visible=true;
			this->scene->dialog_file="";
			for(int i=0;i<2;i++)
			{
				auto*p=(::Scene::People*)this->scene->create_people("robot2",0);
				p->pos.x-=i*600;
			}
			j=6;
		}
	});

	add_task(
	{
		true,
		[this]()
		{
			return j==6&&this->scene->ss!=&this->scene->dialog_ss &&this->scene->peoples.size()==1&&this->scene->main->alive;
		},
		[this]()
		{
			for(int i=0;i<5;i++)
			{
				auto*p=(::Scene::People*)this->scene->create_people("robot2",0);
				p->pos.x-=i*300;
			}
			j=7;
		}
	});

	add_task(
	{
		true,
		[this]()
		{
			return j==7&&this->scene->ss!=&this->scene->dialog_ss &&this->scene->peoples.size()==1&&this->scene->main->alive;
		},
		[this]()
		{
			this->scene->create_people("robotboss",0);
			for(int i=0;i<3;i++)
			{
				auto*p=(::Scene::People*)this->scene->create_people("robot2",0);
				p->pos.x-=i*400;
			}
			j=8;
		}
	});
	//结束
	add_task
	({
		true,
		[this]()
		{
			return j==8&&this->scene->peoples.size()==1&&this->scene->main->alive&&this->scene->ss!=&this->scene->dialog_ss;
		},
		[this]()
		{
			this->scene->dialog_file="victory";
			this->scene->set_ss(&this->scene->dialog_ss);
			j=9;
		}
	});

	add_task
	({
		true,
		[this]()
		{
			return j==9&&this->scene->ss!=&this->scene->dialog_ss;
		},
		[this]()
		{
			this->scene->bgm_file="",
			this->scene->dialog_file="";
			this->scene->end();
		},
	});
}

void chapter10_init(){
	Config::Scene scene{
		.background_file="background/empty",
		.prospect_file="background/empty",
		.main="main",
		.initor=[](::Scene::Scene*scene){
			auto*p=new Chapter10(scene);
			scene->progress=p;
		}
	};
	scene_table["chapter10"]=std::move(scene);
}
