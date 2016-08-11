#include "motor.h"
void Motor_InitConfig(void)
{	
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);	// πƒ‹∂® ±∆˜3 ±÷”
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA  | RCC_APB2Periph_AFIO, ENABLE);  // πƒ‹GPIOÕ‚…Ë∫ÕAFIO∏¥”√π¶ƒ‹ƒ£øÈ ±÷”
	
   //…Ë÷√∏√“˝Ω≈Œ™∏¥”√ ‰≥ˆπ¶ƒ‹, ‰≥ˆTIM3 CH1µƒPWM¬ˆ≥Â≤®–
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; //TIM3_CH1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //∏¥”√Õ∆ÕÏ ‰≥ˆ
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);//≥ı ºªØGPIO
 
	  //…Ë÷√∏√“˝Ω≈Œ™∏¥”√ ‰≥ˆπ¶ƒ‹, ‰≥ˆTIM3 CH2µƒPWM¬ˆ≥Â≤®–Œ
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7; //TIM3_CH2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE , ENABLE);  // πƒ‹GPIOÕ‚…Ë ±÷” πƒ‹
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
 
   //≥ı ºªØTIM3
	TIM_TimeBaseStructure.TIM_Period = 899; //…Ë÷√‘⁄œ¬“ª∏ˆ∏¸–¬ ¬º˛◊∞»ÎªÓ∂Øµƒ◊‘∂Ø÷ÿ◊∞‘ÿºƒ¥Ê∆˜÷‹∆⁄µƒ÷µ
	TIM_TimeBaseStructure.TIM_Prescaler =0; //…Ë÷√”√¿¥◊˜Œ™TIMx ±÷”∆µ¬ ≥˝ ˝µƒ‘§∑÷∆µ÷µ 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //…Ë÷√ ±÷”∑÷∏Ó:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIMœÚ…œº∆ ˝ƒ£ Ω
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //∏˘æ›TIM_TimeBaseInitStruct÷–÷∏∂®µƒ≤Œ ˝≥ı ºªØTIMxµƒ ±º‰ª˘ ˝µ•Œª
	
	//≥ı ºªØTIM3 Channel1 PWMƒ£ Ω	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //—°‘Ò∂® ±∆˜ƒ£ Ω:TIM¬ˆ≥ÂøÌ∂»µ˜÷∆ƒ£ Ω2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //±»Ωœ ‰≥ˆ πƒ‹
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; // ‰≥ˆº´–‘:TIM ‰≥ˆ±»Ωœº´–‘∏ﬂ
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);  //∏˘æ›T÷∏∂®µƒ≤Œ ˝≥ı ºªØÕ‚…ËTIM3 OC2

	//≥ı ºªØTIM3 Channel2 PWMƒ£ Ω	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //—°‘Ò∂® ±∆˜ƒ£ Ω:TIM¬ˆ≥ÂøÌ∂»µ˜÷∆ƒ£ Ω2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //±»Ωœ ‰≥ˆ πƒ‹
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; // ‰≥ˆº´–‘:TIM ‰≥ˆ±»Ωœº´–‘∏ﬂ
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);  //∏˘æ›T÷∏∂®µƒ≤Œ ˝≥ı ºªØÕ‚…ËTIM3 OC2

	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);  // πƒ‹TIM3‘⁄CCR2…œµƒ‘§◊∞‘ÿºƒ¥Ê∆˜
 	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);  // πƒ‹TIM3‘⁄CCR2…œµƒ‘§◊∞‘ÿºƒ¥Ê∆˜
 TIM_CtrlPWMOutputs(TIM3,ENABLE);	//MOE ÷˜ ‰≥ˆ πƒ‹
 
	TIM_Cmd(TIM3, ENABLE);  // πƒ‹TIM3
}
void move(int a,int b)
{
	if(a>0)
	{
		GPIO_SetBits(GPIOE,GPIO_Pin_7);//∏ﬂµÁ—π
		GPIO_ResetBits(GPIOE,GPIO_Pin_8);//µÕµÁ—π
		 TIM_SetCompare1(TIM3,a);
	}
	
		if(a<0)
	{
		GPIO_SetBits(GPIOE,GPIO_Pin_8);//∏ﬂµÁ—π
		GPIO_ResetBits(GPIOE,GPIO_Pin_7);//µÕµÁ—π
		 TIM_SetCompare1(TIM3,a);
	}
	
		if(b>0)
	{
		GPIO_SetBits(GPIOE,GPIO_Pin_9);//∏ﬂµÁ—π
		GPIO_ResetBits(GPIOE,GPIO_Pin_10);//µÕµÁ—π
		 TIM_SetCompare2(TIM3,b);
	}
	
		if(b<0)
	{
		GPIO_SetBits(GPIOE,GPIO_Pin_10);//∏ﬂµÁ—π
		GPIO_ResetBits(GPIOE,GPIO_Pin_9);//µÕµÁ—π
		 TIM_SetCompare2(TIM3,b);
	}
		
}

