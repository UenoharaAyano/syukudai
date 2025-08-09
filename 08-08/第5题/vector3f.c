#include "vector3f.h"

vector3f vector_create(float x,float y,float z)			//创建一个三维向量结构体
{
	vector3f s;
	s.x = x;
	s.y = y;
	s.z = z;
	return s;
}

vector3f vector_add(vector3f a,vector3f b)				//向量和运算
{
	vector3f c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return c;
}

vector3f vector_sub(vector3f a,vector3f b)				//向量差运算
{
	vector3f c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return c;
}

float vector_dot(vector3f a,vector3f b)					//向量点乘运算
{
	return a.x*b.x+a.y*b.y+a.z*b.z;
}

vector3f vector_re(vector3f a)							//向量单位化运算
{
	float m=vector_length(a);
	if(m==0.0)
	{
		return vector_create(0.0,0.0,0.0);				//防止0作为分母
	}
	return vector_create(a.x/m , a.y/m , a.z/m);
}

float vector_length(vector3f a)							//向量模运算
{
	return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}

vector3f vector_cross(vector3f a,vector3f b)			//向量叉乘运算
{
	return vector_create(a.y*b.z - a.z*b.y , a.z*b.x - a.x*b.z , a.x*b.y - a.y*b.x);
}