#include <stdio.h>
#include "MParam.h"

int main()
{
	unsigned int row, column;
	printf("请输入矩阵行数：");
	scanf("%u", &row);
	printf("请输入矩阵列数：");
	scanf("%u", &column);
	
	Matrix A=createMatrix((uint8_t)row,(uint8_t)column);
	printf("\n请输入矩阵的元素：\n");
	inputMatrix(A);
	
	printf("\n矩阵为：\n");
	printMatrix(A);
	
	Matrix transA=transMatrix(A);
	printf("\n矩阵的转置矩阵为：\n");
	printMatrix(transA);
	
	Matrix result=multiMatrix(A,transA);
	printf("\n该矩阵与其转置矩阵的乘积为：\n");
	printMatrix(result);
	
	freeMatrix(A);
	freeMatrix(transA);
	freeMatrix(result);
	
	return 0;
	getchar(); getchar();
}

