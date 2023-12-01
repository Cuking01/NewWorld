#include "../all.h"


int main()
{
	Config::init();
	auto*p=Config::create_scene("test");
	printf("%p\n",p);
}
