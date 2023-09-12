#ifndef button_h
#define button_h

class Botao{

	private:
		unsigned char btn; // estado do botao
		unsigned char last_btn; // ultimo estado
		unsigned long last_bounce; // ultimo mudanca
		unsigned char n_pin; // numero do pino
		unsigned short t_debouce; // tempo de debouce

	public:
		Botao(unsigned char pin, unsigned short debouce_time);
		bool debouce();

};

#endif
