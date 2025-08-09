#include <stdio.h>

int judge_endian()
{
	unsigned int x=1;
	return *((unsigned char*)&x)==1;
}

unsigned int swap32(unsigned int val) 
{
    return ((val & 0x000000FF) << 24) |
           ((val & 0x0000FF00) << 8)  |
           ((val & 0x00FF0000) >> 8)  |
           ((val & 0xFF000000) >> 24);
}

int main()
{
	unsigned int num = 0x12253647;
	
	if(judge_endian())
	{
		printf("Current system is Little Endian.\n");
	}
	else
	{
		printf("Current system is Big Endian.\n");
	}
	
	printf("Original number: 0x%X\n",num);
	
	unsigned int swap=swap32(num);
	printf("Swapped number: 0x%X\n",swap);
	
	return 0;
}