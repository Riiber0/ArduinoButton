#include "button.h"
#include "Arduino.h"



Botao::Botao(unsigned char pin, unsigned short debouce_time){
	n_pin = pin;
	btn = LOW; //estado do botao
	last_btn = LOW; // ultimo estado
	last_bounce = 0; // ultimo mudanca
	t_debouce = debouce_time; // tempo de debounce
	
}

bool Botao::debouce(){
	unsigned char btn_input = digitalRead(n_pin);
	bool ret = false;

	if (btn_input != last_btn) 
		last_bounce = millis();

	if ((millis() - last_bounce) > t_debouce) {
		if (btn_input != btn){
			btn = btn_input;

			if(btn == HIGH)
				ret = true;
		}
	}
	last_btn = btn_input;
	return ret;
}


