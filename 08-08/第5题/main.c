#include <stdio.h>
#include <stdlib.h>
#include "vector3f.h"

int main()
{
	vector3f v1,v2,result,dv1,dv2;
	float resultf;
	float leg1,leg2;
	
	printf("请输入第一个向量的x,y,z:\n");
	scanf("%f %f %f",&v1.x,&v1.y,&v1.z);
	
	printf("请输入第二个向量的x,y,z:\n");
	scanf("%f %f %f",&v2.x,&v2.y,&v2.z);
	
	printf("\n你输入的向量：\n");
    printf("v1 = (%.2f, %.2f, %.2f)\n", v1.x, v1.y, v1.z);
    printf("v2 = (%.2f, %.2f, %.2f)\n", v2.x, v2.y, v2.z);
    
    result = vector_add(v1,v2);
    printf("\nv1 + v2 = (%.2f, %.2f, %.2f)\n", result.x, result.y, result.z);
    
    result = vector_sub(v1,v2);
    printf("\nv1 - v2 = (%.2f, %.2f, %.2f)\n", result.x, result.y, result.z);
    
    resultf = vector_dot(v1,v2);
    printf("\nv1 · v2 = %.2f\n", resultf);
    
    leg1 = vector_length(v1);
    leg2 = vector_length(v2);
    printf("\n|v1| = %.2f, |v2| = %.2f\n", leg1, leg2);
    
    dv1 = vector_re(v1);
    dv2 = vector_re(v2);
	printf("\n单位化v1 -> (%.2f, %.2f, %.2f)\n", dv1.x, dv1.y, dv1.z);
	printf("单位化v2 -> (%.2f, %.2f, %.2f)\n", dv2.x, dv2.y, dv2.z);
	
	result = vector_cross(v1,v2);
	printf("\nv1 × v2 = (%.2f, %.2f, %.2f)\n", result.x, result.y, result.z);
}