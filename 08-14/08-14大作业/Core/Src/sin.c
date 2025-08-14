#include "main.h"
#include <stdio.h>
#include <math.h>
#include "usart.h"

float t1=0,t2=0;

void print_sin(){
t1 += 0.1;
t2 += 0.5;
printf("simples:%f, %f\n", sin(t1), sin(t2)); 		
HAL_Delay(100);
}