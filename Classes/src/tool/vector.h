#pragma once

struct Vector
{
	f3 x,y;

	Vector& operator+=(Vector b)
	{
		x+=b.x;
		y+=b.y;
		return *this;
	}

	Vector& operator-=(Vector b)
	{
		x-=b.x;
		y-=b.y;
		return *this;
	}
	Vector& operator*=(f3 b)
	{
		x*=b;
		y*=b;
		return *this;
	}
	Vector& operator/=(f3 b)
	{
		x/=b;
		y/=b;
		return *this;
	}

	Vector flipped_x() const
	{
		return {-x,y};
	}
};

Vector operator+(Vector a,Vector b)
{
	return a+=b;
}

Vector operator-(Vector a,Vector b)
{
	return a-=b;
}

Vector operator*(Vector a,f3 x)
{
	return a*=x;
}

Vector operator*(f3 x,Vector a)
{
	return a*=x;
}

Vector operator/(Vector a,f3 x)
{
	return a/=x;
}

Vector operator/(f3 x,Vector a)
{
	return a/=x;
}

bool operator!=(Vector a,Vector b)
{
	return fabs(a.x-b.x)>eps||fabs(a.y!=b.y)>eps;
}

double dis(Vector a,Vector b)
{
	a-=b;
	return std::sqrt(a.x*a.x+a.y*a.y);
}
