#ifndef MPARAM_H
#define MPARAM_H

#include <stdint.h>

typedef struct MParam
 {
 uint8_t row;
 uint8_t column;
 float **data;
 }*Matrix;

Matrix createMatrix(uint8_t row, uint8_t column);		//创建矩阵

void freeMatrix(Matrix m);								//释放矩阵

void inputMatrix(Matrix m);								//输入矩阵

void printMatrix(Matrix m);								//打印矩阵

Matrix transMatrix(Matrix m);							//矩阵转置

Matrix multiMatrix(Matrix m1,Matrix m2);				//矩阵乘法

#endif