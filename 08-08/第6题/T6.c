#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

int main()
{
	uint32_t result=0;							//定义一个uint32_t类型的整数
	int numbers[32];							//用数组表示随机数
	int i;
	
	srand((unsigned)time(NULL));				//以时间设定随机数生成种子
	
	for(i=0;i<32;i++)
	{
		numbers[i]=rand()%101;					//生成0~100的随机整数
		if(numbers[i]>50)
		{
			result=result|(1u<<i);				//用左移运算与按位或运算得出result的值
		}
	}
	printf("最终的32为整数为:%u\n",result);		//输出result的值
	
	return 0;
}