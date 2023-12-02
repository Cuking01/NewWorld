#pragma once

struct Buff_Helper
{
    f3 add;
    f3 sub;
    f3 addp;
    f3 subp;
    Buff_Helper();
    f3 operator()(f3 x) const;
};

struct Buff
{
	std::function<s2(f3,Buff_Helper&)> buff;
	
	s2 operator()(f3 x,Buff_Helper&);
};
