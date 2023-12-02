#pragma once

struct Object
{
	Scene* scene;
	s2 阵营;
	Pos pos;
	Object(Scene*scene,s2 阵营,Pos pos);
	virtual ~Object()=default;
};
