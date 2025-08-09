#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	float a=59.622f;
	float b=92.6327f;
	float o1,o2;										//定义输出结果o1,o2
	char dest[4];										//定义存储数组dest
	float max = fmaxf(fabsf(a),fabsf(b));				//比较找出a,b绝对值大小
	float scale = 32767.0f/max;							//利用绝对值较大的数找出scale的最大值，尽可能减小误差
	
	short m1=(short)(a*scale);
	short n1=(short)(b*scale);							//对a,b进行缩放再转换成short类型，提高精度
	
	memcpy(dest,&m1,2);
	memcpy(dest + 2,&n1,2);
	
	short m2,n2;
	memcpy(&m2,dest,2);
	memcpy(&n2,dest + 2,2);								//写入与读取数据
	
	o1=m2/scale;
	o2=n2/scale;										//将读取出的数据还原为float类型
	
	printf("原小数值为：\n%.9f，%.9f\n",a,b);
	printf("读取出的值为:\n%.6f，%.6f\n",o1,o2);		//输出
	
	return 0;
}