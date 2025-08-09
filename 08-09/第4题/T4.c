#include <stdio.h>
#include <stdlib.h>

int compare(const void *a,const void *b)
{
	if (*(float *)a < *(float *)b) return -1;				// 从小到大排序。
    else if (*(float *)a > *(float *)b) return 1;
    else return 0;
}

int main()
{
	float num[114];											//数组最大值为114。
	int n=0;
	
	printf("请输入若干个浮点数（输入字母结束）：\n");
	
	while(scanf("%f",&num[n])==1)							//若成功读取到一个匹配的数据，scanf会返回1。
	{														//若读取不到数字，返回值不是1，循环终止。
		n++;
		if(n>=114)
		{
			printf("以达到最大限制！\n");
			break;
		}
	}
	
	qsort(num,n,sizeof(float),compare);						//排序。
	
	printf("排序结果为：\n");								//对排序结果进行输出。
	for(int i=0;i<n;i++)
	{
		printf("%f ",num[i]);
	}
	printf("\n");
	
	return 0;
}