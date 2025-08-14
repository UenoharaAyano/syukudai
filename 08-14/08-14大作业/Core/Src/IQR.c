#include "main.h"
#include "usart.h"
#include "dma.h"
#include <string.h>

uint8_t rx_Data[SIZE] = {0};

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
    if(huart->Instance == USART2){
        if(rx_Data[0] == HEAD && rx_Data[SIZE - 1] == TAIL){
            HAL_UART_Transmit_DMA(&huart2, &rx_Data[1], SIZE - 2);
        }
        HAL_UART_Receive_DMA(&huart2, rx_Data, sizeof(rx_Data));
    }
}