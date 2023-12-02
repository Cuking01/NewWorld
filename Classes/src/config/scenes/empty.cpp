#pragma once

Empty_Progress::Empty_Progress(::Scene::Scene*scene):
	Progress(scene)
{
	scene->people_max={9000,1500};
	scene->camera_min={0,0};
	scene->camera_max={7500,200};

	add_task
	({
		true,
		[this]()
		{
			return j==0;
		},
		[this]()
		{
			this->scene->main->alive=false;
			this->scene->main->armature.bone.visible=false;
			this->scene->dialog_file="continued";
			this->scene->set_ss(&this->scene->dialog_ss);
			j=1;
		}
	});

	add_task
	({
		true,
		[this]()
		{
			return j==1&&this->scene->ss!=&this->scene->dialog_ss;
		},
		[this]()
		{
			this->scene->dialog_file="";
			this->scene->end();
		},
	});

}

void empty_init()
{
	Config::Scene scene
	{
		.background_file="background/empty",
		.prospect_file="background/empty",
		.bgm_file="",
		.prospect_scale=0.6,
		.main="main",
		// .peoples={"redlizard"},
		.initor=[](::Scene::Scene*scene)
		{
			auto*p=new Empty_Progress(scene);
			scene->progress=p;
		}
	};

	scene_table["empty"]=std::move(scene);
}