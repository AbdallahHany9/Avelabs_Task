#include "Timer.h"
static void(*pf_ovf0)(void)=NULLPTR;
static void(*pf_oc0)(void)=NULLPTR;
static void(*pf_ovf1)(void)=NULLPTR;
static void(*pf_oc1a)(void)=NULLPTR;
static void(*pf_oc1b)(void)=NULLPTR;
static void(*pf_icu)(void)=NULLPTR;
void Timer0_init(Timer0_Mode_type mode,Timer0_Prescaling_type p,OC0Mode_type oc0_mode){
	
		// TIMER0_NORMAL_MODE:
		CLEAR_BIT(TCCR0,WGM00);
		CLEAR_BIT(TCCR0,WGM01);
		
	
		
		// TIMER0_SCALER_8:
		TCCR0=TCCR0&0xF8;
		TCCR0=TCCR0|(0x02);
		
		
	
		// OC0_DISCONNECTED:
		CLEAR_BIT(TCCR0,COM00);
		CLEAR_BIT(TCCR0,COM01);
		
}
void Timer0_OV_InterruptEnable(void){
	SET_BIT(TIMSK,TOIE0);

}
void Timer0_OV_InterruptDisable(void){
	CLEAR_BIT(TIMSK,TOIE0);
}

ISR(TIMER0_OVF_vect){
	if (pf_ovf0!=NULLPTR)
	{
		pf_ovf0();
	}
	
}
I
