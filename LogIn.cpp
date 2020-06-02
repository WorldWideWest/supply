#include "LogIn.h"/*kada se klase definišu u različitim fajlovima potrebno je 
includat fajl u kome su definisani prozotipi klase*/
#include <iostream>
#include <string>
#include <ctime>//klasa koja služi da bi se dobilo trenurno vrijeme od sistema
#include <fstream>//filestream - koristi se za manipulaciju sa fajlovima(datotekama)
#include <iomanip>//input/output manipulation - formatiranje(manipuliranje) teksta 
//proces enkapsulacije za username
void LogIn::set_UserName(std::string usname)
{
	username == usname;
}
std::string LogIn::get_UserName(std::string usname)
{
	return username;
}
//proces enkapsulacije za password
void LogIn::set_Password(std::string passwd)
{
	password == passwd;
}
std::string LogIn::get_Password()
{
	return password;
}

LogIn::LogIn()//konstruktor(onaj koji stvara program)
{
	std::string name, pass;
	//definisanje do - while koja će tražiti podatke kako bi se prijavili u sistem
	do{
		std::cout << "Molimo unesite Vase korisnicko ime: ";
		std::cin >> name;
		std::cout << "Molimo unesite Vasu lozinku: ";
		std::cin >> pass;
		std::cout << std::endl;

		//kada su podaci unešeni slijedi njihova provjera
		
		if(name == username && pass == password){
			std::cout << "Dobro dosli " << name << "e" <<std:: endl;
			time_t ttime = time(0);
			char* dt = ctime(&ttime);
			
			//bilježenje podatka kada je uspješno prijavljen user

			std::ofstream out_file;
			out_file.open("history_h.txt", std::ios::app);
			out_file << std::setw(20) << name << "  " << std::setw(50) << dt;
			out_file.close();
		}
		else{

			//Ukoliko podaci nisu tačni, ovaj dio koda slijedi

			std::cout << "Error code 0x01 - uneseni parametri nisu tacni, molimo pokusajte ponovo! " << std::endl;
			time_t ttime = time(0);
			char* dt = ctime(&ttime);
			std::ofstream out_file_err;

			//Takođe ukoliko niste unijeli tačne podatke to će biti zapisano

			out_file_err.open("history_failed.txt", std::ios::app);
			out_file_err << std::setw(20)<< name << "  " << std::setw(10) << dt;
			out_file_err.close();
		}
		//Ova petlja će se vrtiti sve dok parametri koje program traži ne budu tačni
	}while(name != username || pass != password);
}
//Destruktor (onaj koji razvaljuje program) oslobađa memoriju
	LogIn::~LogIn()
	{
	}

