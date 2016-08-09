//类人非标程序2016
/*
  引脚说明：
          光电中断：PE2，PE3，PE4，PE5 (PE2:左前 PE3：右前)
          红外测距：PC0 PC1 PC2 PC3 分别对应ADC1_IN10 ADC1_IN11 ADC1_IN12 ADC1_IN13 (PC2：右 PC3：左)
          电机：PA6 PA7  分别控制TIM3_CH1 TIM3_CH2(PA6：左 PA7：右)
               PE7 PE8 PE9 PE10 控制机器人电机正反转(接线：PE7：A1 PE8：A2 PE9：B1 PE10：B2)
               PWM：TIM3
  主要函数说明：
          move(int a,int b); 控制电机 左:a 右:b 速度为（-900——900）
          chess(void); 推棋子程序
          Get_Adc_Average(u8 ch,u32 times); 红外检测程序 ch：通道 times：采样次数
*/
#include "stm32f10x.h" //stm32官方头文件
#include "delay.h"  //延时函数
#include "motor.h"  //电机
#include "adc.h"   //AD
#include "exti.h" //中断
#include "tool.h" //一些工具
#include "uart5.h"
#include "jushou.h"
// #include "tim.h"  //TIM2配置
void chess(void);
void hand(void);
void jushou(void);
void init(void);
/**************************************主函数****************************************/
int main(void)
{


	while(1)
	{

	}
	return 0;
}

/***************************************中断*******************************************/
void EXTI2_IRQHandler(void)
{
	
}
void EXTI3_IRQHandler(void)
{


}
void EXTI4_IRQHandler(void) //右上角中断
{

}

//测速中断
void EXTI9_5_IRQHandler(void)
{

}
//定时器4中断服务程序
void TIM4_IRQHandler(void)
{

}
//定时器3中断服务程序
void TIM3_IRQHandler(void)
{

}
void USART1_IRQHandler(void)
{
}

void USART3_IRQHandler(void)
{

}
/***********************************推棋子*************************************/
void chess()
{
	
}
/************************************手臂***********************************/
void hand(void)
{		

}



/**************************END OF FILE*************************/
