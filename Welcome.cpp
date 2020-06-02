#include "Welcome.h"
#include "Supply.h"
#include <iostream>
#include <string>
#include <memory>// mrmory klasa služi kako bi se implementirali pametni pointeri
#include <iomanip>


Welcome::Welcome()
{
	
	std::cout << "Dobro dosli u softver za vodjenje nabavke:\n 1. Nabavka (sup)\n " << std::endl;
	while(true){
		std::string sup = "sup";
		std::string hel = "help";
		std::cout << ">> ";
		std::cin >> input;
		if(input != sup){
			std::cout << "Error code 0x02 - komanda koju ste unijeli nije poznata" << std::endl;
		}
		else if(input == sup)
		{
			//pametni pointer koji pokazuje na klasu Supply

			std::unique_ptr<Supply> sup {new Supply()};

			//std::cout << "Dobro dosli u odsijek za nabavku" << std::endl;
		}
}
}

Welcome::~Welcome()
{
}
