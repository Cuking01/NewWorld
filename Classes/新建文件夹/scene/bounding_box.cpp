#pragma once

Bounding_Box::Bounding_Box(Vector l,Vector r):l(l),r(r){}
Bounding_Box::Bounding_Box(Vector p):l(p),r(p){}
Bounding_Box::Bounding_Box():Bounding_Box({0.0,0.0}){}

Bounding_Box Bounding_Box::flipped_x() const
{
	return {{-r.x,l.y},{-l.x,r.y}};
}
