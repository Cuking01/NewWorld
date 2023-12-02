#pragma once

struct Empty_Progress:Progress
{
	int j=0;
	Empty_Progress(::Scene::Scene*scene);
};

void empty_init();