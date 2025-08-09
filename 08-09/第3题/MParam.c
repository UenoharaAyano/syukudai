#include "MParam.h"
#include <stdio.h>
#include <stdlib.h>

Matrix createMatrix(uint8_t row, uint8_t column)
{
	Matrix m = malloc(sizeof(struct MParam));
	
	m->row = row;
	m->column = column;
	m->data = malloc(row * sizeof(float*));
	
	for(int i=0;i<row;i++)
	{
		m->data[i] = malloc(column * sizeof(float));
	}
	
	return m;
}

void inputMatrix(Matrix m)
{
	//printf("[DEBUG] row=%d, col=%d\n", m->row, m->column);			//调试用，因为之前一直报错。。。
	for(int i=0 ; i<m->row ; i++)
	{
		for(int j=0 ; j<m->column ; j++)
		{
			printf("请输入矩阵[%d][%d]元素：",i,j);
			scanf("%f", &m->data[i][j]);
		}
	}
}

void printMatrix(Matrix m)
{
	for(int i=0 ; i<m->row ; i++)
	{
		for(int j=0 ; j<m->column ; j++)
		{
			printf("%7.2f ",m->data[i][j]);
		}
		printf("\n");
	}
}

Matrix transMatrix(Matrix m)
{
	Matrix t = createMatrix(m->column,m->row);
	for(int i=0 ; i<m->row ; i++)
	{
		for(int j=0 ; j<m->column ; j++)
		{
			t->data[j][i] = m->data[i][j];
		}
	}
	
	return t;
}

Matrix multiMatrix(Matrix m1,Matrix m2)
{
	Matrix result = createMatrix(m1->row , m2->column);
	
	for(int i=0 ; i<m1->row ; i++)
	{
		for(int j=0 ; j<m2->column ; j++)
		{
			result->data[i][j]=0.0f;
			for(int k=0 ; k<m1->column ; k++)
			{
				result->data[i][j] += m1->data[i][k]*m2->data[k][j];
			}
		}
	}
	
	return result;
}

void freeMatrix(Matrix m)
{
	if(!m) return;
	
	for(int i=0 ; i<m->row ; i++)
	{
		free(m->data[i]);
	}
	free(m->data);
	free(m);
}
