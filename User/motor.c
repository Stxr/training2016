#include "motor.h"
void Motor_InitConfig(void)
{	
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);	//ʹ�ܶ�ʱ��3ʱ��
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA  | RCC_APB2Periph_AFIO, ENABLE);  //ʹ��GPIO�����AFIO���ù���ģ��ʱ��
	
   //���ø�����Ϊ�����������,���TIM3 CH1��PWM���岨�
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; //TIM3_CH1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIO
 
	  //���ø�����Ϊ�����������,���TIM3 CH2��PWM���岨��
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7; //TIM3_CH2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE , ENABLE);  //ʹ��GPIO����ʱ��ʹ��
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
 
   //��ʼ��TIM3
	TIM_TimeBaseStructure.TIM_Period = 899; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ
	TIM_TimeBaseStructure.TIM_Prescaler =0; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
	
	//��ʼ��TIM3 Channel1 PWMģʽ	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM3 OC2

	//��ʼ��TIM3 Channel2 PWMģʽ	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM3 OC2

	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);  //ʹ��TIM3��CCR2�ϵ�Ԥװ�ؼĴ���
 	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);  //ʹ��TIM3��CCR2�ϵ�Ԥװ�ؼĴ���
 TIM_CtrlPWMOutputs(TIM3,ENABLE);	//MOE �����ʹ��
 
	TIM_Cmd(TIM3, ENABLE);  //ʹ��TIM3
}
void move(int a,int b)
{
	if(a>0)
	{
		GPIO_SetBits(GPIOE,GPIO_Pin_7);//�ߵ�ѹ
		GPIO_ResetBits(GPIOE,GPIO_Pin_8);//�͵�ѹ
		 TIM_SetCompare1(TIM3,a);
	}
	
		if(a<0)
	{
		GPIO_SetBits(GPIOE,GPIO_Pin_8);//�ߵ�ѹ
		GPIO_ResetBits(GPIOE,GPIO_Pin_7);//�͵�ѹ
		 TIM_SetCompare1(TIM3,a);
	}
	
		if(b>0)
	{
		GPIO_SetBits(GPIOE,GPIO_Pin_9);//�ߵ�ѹ
		GPIO_ResetBits(GPIOE,GPIO_Pin_10);//�͵�ѹ
		 TIM_SetCompare2(TIM3,b);
	}
	
		if(b<0)
	{
		GPIO_SetBits(GPIOE,GPIO_Pin_10);//�ߵ�ѹ
		GPIO_ResetBits(GPIOE,GPIO_Pin_9);//�͵�ѹ
		 TIM_SetCompare2(TIM3,b);
	}
		
}

