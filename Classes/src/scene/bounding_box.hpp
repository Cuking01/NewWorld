#pragma once

struct Bounding_Box
{
	Vector l,r;
	Bounding_Box(Vector l,Vector r);
	Bounding_Box(Vector p);
	Bounding_Box();
	Bounding_Box flipped_x() const;
};

bool has_intersection(Bounding_Box a,Bounding_Box b)
{
	return std::max(a.l.x,b.l.x)<=std::min(a.r.x,b.r.x)&&std::max(a.l.y,b.l.y)<=std::min(a.r.y,b.r.y);
}

Bounding_Box operator+(Bounding_Box a,Vector b)
{
	return {a.l+b,a.r+b};
}

Bounding_Box operator+(Vector b,Bounding_Box a)
{
	return {a.l+b,a.r+b};
}

bool operator!=(Bounding_Box a,Bounding_Box b)
{
	return a.l!=b.l||a.r!=b.r;
}

