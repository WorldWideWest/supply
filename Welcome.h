#ifndef WELCOME_H
#define WELCOME_H
#include <string>
#include <iostream>
class Welcome
{
	
	public:
		std::string input;
		Welcome();
		void set_Input(std::string inp);
		std::string get_Input();
		~Welcome();
};

#endif
