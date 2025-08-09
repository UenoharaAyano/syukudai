#include <stdio.h>
#include <string.h>
int main()
{
	float a=3.1415926f;
	float b=1.145141919f;
	float o1,o2,o3,o4,o5,o6;
	char dest[8];
	int i;
	
	
	memcpy(dest,&a,sizeof(a));
	memcpy(dest + sizeof(a),&b,sizeof(b));
	memcpy(&o1,dest,sizeof(o1));
	memcpy(&o2,dest + sizeof(o1),sizeof(o2));
	
	
	*(float*)dest=a;
	*(float*)(dest+sizeof(a))=b;
	o3=*(float*)dest;
	o4=*(float*)(dest+sizeof(a));
	
	
	unsigned char *p=(unsigned char*)&a;
	for(i=0;i<sizeof(a);i++)
	{
		dest[i]=p[i];
	}
	p=(unsigned char*)&b;
	for(i=0;i<sizeof(b);i++)
	{
		dest[i+sizeof(a)]=p[i];
	}
	p=(unsigned char*)&o5;
	for(i=0;i<sizeof(a);i++)
	{
		p[i]=dest[i];
	}
	p=(unsigned char*)&o6;
	for(i=0;i<sizeof(b);i++)
	{
		p[i]=dest[i+sizeof(a)];
	}
	
	printf("原小数值为：\n%.9f，%.9f\n",a,b);
	printf("方法一(memcpy):\n%.6f，%.6f\n",o1,o2);
	printf("方法二(强制转换):\n%.6f，%.6f\n",o3,o4);
	printf("方法三(逐一存读):\n%.6f，%.6f\n",o5,o6);
	
	return 0;
}