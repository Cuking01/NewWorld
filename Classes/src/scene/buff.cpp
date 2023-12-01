#pragma once

Buff_Helper::Buff_Helper():add(0),sub(0),addp(1),subp(1){}
f3 Buff_Helper::operator()(f3 x) const
{
	return x*addp*subp+add-sub;
}


s2 Buff::operator()(f3 x,Buff_Helper&bh)
{
	return buff(x,bh);
}
