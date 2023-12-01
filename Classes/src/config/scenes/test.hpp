#pragma once

struct Test_Progress:Progress
{
	int j=0;
	Test_Progress(::Scene::Scene*scene);
};

void test_init();
