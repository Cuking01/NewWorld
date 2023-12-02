#pragma once

struct Attribute
{
    Scene*scene;
    f3 x;
    f3 min,max;
    Trigger<Buff> buffes;
    Attribute(Scene*scene);
    Attribute(Scene*scene,f3 x);
    Attribute(Scene*scene,f3 x,f3 min,f3 max);
    u2 add(const Buff&buff);
    void erase(u2 key);
    Buff* find(u2 key);
    f3 operator()();

};

struct Attributes
{
    Attribute HP_lim,ATK,DEF,HARD,SPEED;
    Attribute max_jump_cnt;

    Attributes(Scene*scene,const Config::Attributes&con,s2 level);
};
