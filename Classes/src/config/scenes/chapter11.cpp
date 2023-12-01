#pragma once

Chapter11::Chapter11(::Scene::Scene*scene):Progress(scene){
	scene->people_max={3500,1500};
	scene->camera_min={0,0};
	scene->camera_max={3000,200};
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
			j=2;
		}
	});

	add_task(
	{
		true,
		[this]()
		{
			return true;
			// return j!=0;
		},
		[this]()
		{
			if(550<=this->scene->main->pos.x&&this->scene->main->pos.x<=750){
				this->scene->dialog_file="dialog11_1";
				// this->scene->main->armature.bone.visible=false;
			}else{
				this->scene->dialog_file="";
			}
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
