#pragma once

Chapter11::Chapter11(::Scene::Scene*scene):Progress(scene){
	scene->people_max={3800,1500};
	scene->camera_min={0,0};
	scene->camera_max={3300,200};
	add_task(
	{
		true,
		[this]()
		{
			return j==0;
		},
		[this]()
		{
			this->scene->main->alive=false;
			this->scene->main->armature.bone.visible=false;
			this->scene->dialog_file="dialog11_0";
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
			this->scene->main->armature.bone.visible=true;
			this->scene->main->alive=true;
			j=2;
		}
	});

	add_task(
	{
		false,
		[this]()
		{
			return true;
		},
		[this]()
		{
			if(550<=this->scene->main->pos.x&&this->scene->main->pos.x<=750){
				this->scene->dialog_file="dialog11_1";
			}else if(1050<=this->scene->main->pos.x&&this->scene->main->pos.x<=1450){
				if(cnt==0){
					this->scene->dialog_file="paper01";
					cnt=1;
				}else if(cnt==1){
					this->scene->dialog_file="paper02";
					cnt=0;
				}else if(cnt==2){
					this->scene->dialog_file="paper03";
					cnt=0;
				}
			}else if(2400<=this->scene->main->pos.x&&this->scene->main->pos.x<=2550){
				this->scene->dialog_file="dialog11_2";
			}else if(1850<=this->scene->main->pos.x&&this->scene->main->pos.x<=2000){
				this->scene->dialog_file="author01";
			}else{
				this->scene->dialog_file="";
			}
		}
	});

	add_task(
	{
		true,
		[this]()
		{
			return this->scene->main->pos.x>3550;
		},
		[this]()
		{	
			this->scene->dialog_file="";
			this->scene->end();
		}
	});
	
}

void chapter11_init(){
	Config::Scene scene{
		.background_file="background/beacon0",
		.prospect_file="background/beacon1",
		.prospect_scale=0.2,
		.main="main",
		.initor=[](::Scene::Scene*scene){
			auto*p=new Chapter11(scene);
			scene->progress=p;
		}
	};
	scene_table["chapter11"]=std::move(scene);
}
