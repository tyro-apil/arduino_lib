#include "encoder.hpp"

void encoder::init(){
	pinMode(this->clk_pin, INPUT_PULLUP);
	pinMode(this->dt_pin, INPUT);
	chA_last_state = digitalRead(this->clk_pin);
	attachInterrupt(digitalPinToInterrupt(this->clk_pin), callback(this), CHANGE);	
}

void callback(){
	chA = digitalRead(encoder.clk_pin);
	chB = digitalRead(enc.dt_pin);

	if (chA != chB){
		encoder.rotation = CW;
		encoder.count++;
	}
	else{
		encoder.rotation = CCW;
		encoder.count--;
	}
	custom_addon_ISR();	
}
