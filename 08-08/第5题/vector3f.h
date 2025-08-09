#ifndef VECTOR3F_H
#define VECTOR3F_H

#include <math.h>

typedef struct {				//定义三维向量结构体
	float x;
	float y;
	float z;
} vector3f;

vector3f vector_create(float x,float y,float z);

vector3f vector_add(vector3f a,vector3f b);

vector3f vector_sub(vector3f a,vector3f b);

float vector_dot(vector3f a,vector3f b);

vector3f vector_re(vector3f a);

float vector_length(vector3f a);

vector3f vector_cross(vector3f a,vector3f b);

#endif