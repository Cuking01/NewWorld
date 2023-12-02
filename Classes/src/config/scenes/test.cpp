#pragma once

Test_Progress::Test_Progress(::Scene::Scene*scene):
	Progress(scene)
{
	scene->people_max={9000,1500};
	scene->camera_min={0,0};
	scene->camera_max={7500,200};
	add_task(
	{
		true,
		[this]()
		{
			return j==0&&this->scene->peoples.size()==1&&this->scene->main->alive;
		},
		[this]()
		{
			this->scene->dialog_file="";
			this->scene->create_people("robot2",0);
		}
	});

	add_task
	({
		true,
		[this]()
		{
			return j==1&&this->scene->peoples.size()==1&&this->scene->main->alive;
		},
		[this]()
		{
			this->scene->dialog_file="victory";
			this->scene->set_ss(&this->scene->dialog_ss);
			j=2;
		}
	});

	add_task
	({
		true,
		[this]()
		{
			return j==2&&this->scene->ss!=&this->scene->dialog_ss;
		},
		[this]()
		{
			this->scene->end();
		},
	});

}

void test_init()
{
	Config::Scene scene
	{
		.background_file="background/test",
		.prospect_file="background/test_prospect",
		.bgm_file="music/out_of_darkness.mp3",
		.prospect_scale=0.6,
		.main="main",
		// .peoples={"redlizard"},
		.initor=[](::Scene::Scene*scene)
		{
			auto*p=new Test_Progress(scene);
			scene->progress=p;
		}
	};

	scene_table["test"]=std::move(scene);
}
