//KEYES040 ROTARY ENCODER
//header file for rotary encoder arduino

#ifndef __ENCODER_HPP
#define __ENCODER_HPP

#include<Arduino.h>

enum direction {CW, CCW};
int chA_last_state, chA, chB;

/*
@info:
	2 channesls:
	clk - CHANNEL A // reference channel
	dt - CHANNEL B

*/
class encoder{
	public:
	
		uint8_t clk_pin, dt_pin, count;
		const int ticks_per_rev = 40;
		direction rotation;
	
		encoder(){
			this->clk_pin = 2;
			this->dt_pin = 3;
			this->count = 0;
		}
		encoder(uint8_t channelA, uint8_t channelB){
			this->clk_pin = channelA;
			this->dt_pin = channelB;
			this->count = 0;
		}

		void init();		
		
};

void callback(encoder* enc);
void custom_addon_ISR();


#endif //__ENCODER_HPP
