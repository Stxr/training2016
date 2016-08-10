<<<<<<< HEAD
=======
//串口3 波特率9600 8位数据位 停止位1 不用校验  
//TX:PD8 RX:PD9
//串口中断优先级 抢占优先级2 子优先级0
//定时器4功能：定时10ms，如果10ms内串口3没有接收到数据，则表示数据接收结束
>>>>>>> master
#ifndef __USART_H_
#define __USART_H_
#include "stm32f10x.h"
#include <stdio.h>
#include <string.h>
#define LEN 20
u16 usart3_buffer[64],usart3_rx;//usart3_rx:计数状态
void USART_Config(void);
void TIM4_Set(u8 sta);
void TIM4_Init(u16 arr,u16 psc);
#endif
