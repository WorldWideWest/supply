#include "Supply.h"
#include "Welcome.h"
#include <iostream>
#include <string>
#include <memory>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <direct.h>//biblioteka koja služi za dobijanje informacija o putevima za dokumente
#include <stdlib.h>/*standardna c biblioteka, koristi se za dinamičnu alokaciju memorije,
stringove, matematičke operacije*/
#include <sys/stat.h>// biblioteka za specifičnu vrstu podataka vrijeme i datum
#include <stdio.h>//služi za specifčnu alokaciju memorije i takođe dolazi iz grupe C Standard I/O LIbrary
#include <windows.h>// biblioteka koja služi za kreiranje 32x i 64x aplikacija
#include <vector>// specijalna klasa koja unapređuje array

//enkapsulacija inputa

void Welcome::set_Input(std::string inp)
{
	input == inp;
}
std::string Welcome::get_Input()
{
	return input;
}

//metoda za kreiranje i cekiranje foldera

Supply::dirExists(const char *path)
{
	struct stat info;
	
	/*Čekiranje da li folderi postoje ukoliko postoje onda će da preskoči proces,
	ukoliko ne postoje onda će da ih kreira*/

	if(stat (path, &info) != 0)
	{
		//definisanje puteva do mjesta gdje će folder biti kreiran
		mkdir("C:\\Users\\Dzenan\\Documents\\C++\\Trade_software/Fakture");
		mkdir("C:\\Users\\Dzenan\\Documents\\C++\\Trade_software\\Fakture/meta");
	}
	else
	{
	}
}
Supply::Supply()
{
	//kroz funkciju dirExists provjeravmo da li postoji flode 'Fakture', ukoliko ne postoji onda ga kreiramo
	
	const char *path = "./Fakture/";
	const char *pathh = "./meta/";
	printf("", dirExists(path));
	printf("", dirExists(pathh));
	
	std::cout << "========================================================================================================================================================================" << std::endl;
	std::cout << "Dobro dosli u odsijek za nabavku\n Odaberite komandu:\n 1. Ulazne fakture (inpf)\n 2. Historija nabavki (hn)\n 3. Historija faktura (Fakture)" << std::endl;
	while(true){
		std::cout << "========================================================================================================================================================================" << std::endl;
		std::string input, decision_2;
		std::cout << ">> sup >> ";
		std::cin >> input;

		//čekiranje varijable input se vrši na više mjesta ovo je prvo

		if (input == "inpf")
		{
			std::cout << "Dobro dosli u odsijek za kreiranje faktura" << std::endl;
			do{
				//osnovne informacije koje ce da se pohranjuju kao security... u file
				std::string dob, brf, name, JM, NP, decision;
				double vol{0}, PRC{0}, SPDV{0.17};
				double VRD{0}, PDV{0}, VSPDV{0}, VRD_IS{0}, PDV_IS{0}, VSPDV_IS{0};
				int counter{1};
				//_______________________________________________________________________________________
				//definisanje inputa za fakturu
				std::cout << "========================================================================================================================================================================" << std::endl;
				std::cout << std::setw(30) << std::left;
				std::cout << "Faktura br: ";
				std::cin.ignore(10, '\n');
				std::cout << std::setw(30) << std::left;
				std::getline(std::cin, brf);
				//fname je string preko kojeg usmjeravamo gdje ce se spasavati fajl uz ekstenziju ".txt"
				std::string fname = "./Fakture/" + brf + ".txt";			
				std::cout << std::endl;
				
				//definisanje imputa za dobavljaca
				std::cout << std::setw(30) << std::left;
				std::cout << "Unsite naziv dobavljaca: ";
				std::cout << std::setw(30) << std::left;
				std::getline(std::cin, dob);
				
				//dobijanje trenutnog vremena i datuma
				time_t ttime = time(0);
				char* dt = ctime(&ttime);
				std::cout << std::setw(30) << std::left;
				std::cout << "Datum primanja fakture: " << "  " << std::setw(20) << dt;
				
				//kasnijem dijelu ovaj dio bi trebao biti automatizovan kada linkamo login account na ovu varijablu, za sada je user input potreban
				std::cout << std::setw(30) << std::left;
				std::cout << "Ovlasteno lice: ";
				std::cout << std::setw(30) << std::left;
				std::getline(std::cin, name);
				
				//ovdje provjeravamo postojanje "his_nabavke" ukoliko ne postoji onda ga kreiramo, ukoliko postoji onda pisemo u njega
				std::ofstream out_file_write;
				std::ifstream out_file_read("his_nabavke.txt");
				if(out_file_read.fail())
				{
					//ukoliko je if utvrdio da fajl nepostoji kreira ga i daje mu zaglavlje
					out_file_write.open("his_nabavke.txt");
					out_file_write << std::setw(20) << std::left << "Ovlasteno lice";
					out_file_write << " " << std::setw(15) << std::left << "Broj fakture";
					out_file_write << " " << std::setw(30) << std::left << "Dobavljac";
					out_file_write << " " << std::setw(30) << std::left << "Datum i vrijeme" << std::endl;
					out_file_write.close();
					//nakon toga ide u novi red i unosi podatke koje je user dao
					out_file_write.open("his_nabavke.txt", std::ios::app);
					out_file_write << std::setw(20) << std::left << name;
					out_file_write << " " << std::setw(15) << std::left << brf;
					out_file_write << " " << std::setw(30) << std::left << dob;
					out_file_write << " " << std::setw(30) << std::left << dt;
					out_file_write.close();
				}
				else
				{
					//ukoliko je utvrdjeno da fajl postoji onda ga otvara i nastavlja pisati u novi red
					out_file_write.open("his_nabavke.txt", std::ios::app);
					out_file_write << std::setw(20) << std::left << name;
					out_file_write << " " << std::setw(15) << std::left << brf;
					out_file_write << " " << std::setw(30) << std::left << dob;
					out_file_write << " " << std::setw(30) << std::left << dt;
					out_file_write.close();
				}
				//sadr�aj fakture
				do{	
					std::cout << "________________________________________________________________________________________________________________________________________________________________________" << std::endl;
					//definisanje naziva proizvoda
					std::cout << std::setw(30) << std::left;
					std::cin.ignore(1, '\n');				
					std::cout << "Naziv proizvoda: ";
					std::cout << std::setw(30) << std::left;
					std::getline(std::cin, NP);
					
					//definisanje jedinice mjere
					std::cout << std::setw(30) << std::left;
					std::cout << "Jedinica mjere: ";
					std::cout << std::setw(30) << std::left;
					std::getline(std::cin, JM);
					
					//definisanje kolicine
					std::cout << std::setw(30) << std::left;
					std::cout << "Kolicina: ";
					std::cout << std::setw(30) << std::left;
					std::cin >> vol;
					
					//definisanje cijene
					std::cout << std::setw(30) << std::left;
					std::cout << "Cijena: ";
					std::cout << std::setw(30) << std::left;
					std::cin >> PRC;
					
					//utvrdjivanje vrijednosti
					VRD = PRC * vol;
					double VRD_1 = VRD;
					std::cout << std::setw(30) << std::left;
					std::cout << "Vrijednost proizvoda iznosi " << std::fixed << std::setprecision(2) << std::setw(30) << std::left << VRD;
					VRD_IS +=VRD;
					//udvrdjivanje PDV-a na osnovu stope koju smo inicijalizirali u gornjem dijelu koda 
					PDV = VRD * SPDV;
					std::cout << std::endl;
					std::cout << std::setw(30) << std::left;
					std::cout << "PDV iznosi: " << std::fixed << std::setprecision(2) << std::setw(30) << std::left << PDV;
					PDV_IS +=PDV;
					
					//definisanje vrijednosti sa PDV-om odnosno bruto vrijednosti artikla
					VSPDV = PDV + VRD;
					std::cout << std::endl;
					std::cout << std::setw(30) << std::left;
					std::cout << "Vrijednost sa PDV-om iznosi: " << std::fixed << std::setprecision(2) << std::setw(30) << std::left << VSPDV;
					VSPDV_IS +=VSPDV;
					std::cout << std::endl;
					//provjera postojanja fakture, ukoliko ne postoji onda je kreiramo i dajemo joj zaglavlje
					std::string f_meta = "C:\\Users\\Dzenan\\Documents\\C++\\Trade_software\\Fakture\\meta/" + brf + ".txt";
					std::ofstream prod_off_write;
					std::ifstream prod_off_read(fname);
					if(prod_off_read.fail()){
						prod_off_write.open(fname);
						//zaglavlje
						prod_off_write << std::setw(3) << std::left << "R/B";
						prod_off_write << " " << std::setw(50) << std::left << "Naziv proizvoda";
						prod_off_write << " " << std::setw(7) << std::left << "J/M";
						prod_off_write << " " << std::setw(15) << std::left << "Kolicina";
						prod_off_write << " " << std::setw(15) << std::left << "Cijena";
						prod_off_write << " " << std::setw(15) << std::left << "Vrijednost";
						prod_off_write << " " << std::setw(15) << std::left << "PDV";
						prod_off_write << " " << std::setw(20) << std::left << "Vrijednost sa PDV-om" << std::endl;
	 					prod_off_write.close();
	 					//nakon zaglavlja pisemo u fakturu
	 					prod_off_write.open(fname, std::ios::app);
			 			prod_off_write << std::setw(3) << std::left << counter++;
			 			prod_off_write << " " << std::setw(50) << std::left << NP;//"Naziv proizvoda";
						prod_off_write << " " << std::setw(7) << std::left << JM; //"J/M";
						prod_off_write << " " << std::setw(15) << std::left << std::fixed << std::setprecision(3) << vol;//"Kolicina";
						prod_off_write << " " << std::setw(15) << std::left << std::fixed << std::setprecision(2) << PRC;//"Cijena";
						prod_off_write << " " << std::setw(15) << std::left << std::fixed << std::setprecision(2) << VRD;//"Vrijednost";
						prod_off_write << " " << std::setw(15) << std::left << std::fixed << std::setprecision(2) << PDV;//"PDV";
						prod_off_write << " " << std::setw(20) << std::left << std::fixed << std::setprecision(2) << VSPDV << std::endl;//"Vrijednost sa PDV-om";
			 			prod_off_write.close();
			 			
						//ovaj dio koda spasava samo brojeve koji su bitni za izracunavanje ukupnog dijela
						std::ofstream sec_meta_file_write;
						std::ifstream sec_meta_file_read(f_meta);
						if(sec_meta_file_read.fail()){
				 			sec_meta_file_write.open(f_meta, std::ios::app);
				 			sec_meta_file_write << std::setw(15) << std::left << std::fixed << std::setprecision(3) << vol;
				 			sec_meta_file_write << std::setw(15) << std::left << std::fixed << std::setprecision(2) << PRC;
				 			sec_meta_file_write << std::setw(15) << std::left << std::fixed << std::setprecision(2) << VRD;
				 			sec_meta_file_write << std::setw(15) << std::left << std::fixed << std::setprecision(2) << PDV;
				 			sec_meta_file_write << std::setw(15) << std::left << std::fixed << std::setprecision(2) << VSPDV << std::endl;
				 			sec_meta_file_write.close();
				 		}
				 		
			 			//importer koji je pod uslovom da samo dodamo jedan proizvod - predstoji
					}
					else
					{
						//ukoliko dodajemo naredni proizvod prethodni kod se preskace i ispunjava se ovaj dole
						prod_off_write.open(fname, std::ios::app);
			 			prod_off_write << std::setw(3) << std::left << counter++;
			 			prod_off_write << " " << std::setw(50) << std::left << NP;//"Naziv proizvoda";
						prod_off_write << " " << std::setw(7) << std::left << JM; //"J/M";
						prod_off_write << " " << std::setw(15) << std::left << std::fixed << std::setprecision(3) << vol;//"Kolicina";
						prod_off_write << " " << std::setw(15) << std::left << std::fixed << std::setprecision(2) << PRC;//"Cijena";
						prod_off_write << " " << std::setw(15) << std::left << std::fixed << std::setprecision(2) << VRD;//"Vrijednost";
						prod_off_write << " " << std::setw(15) << std::left << std::fixed << std::setprecision(2) << PDV;//"PDV";
						prod_off_write << " " << std::setw(20) << std::left << std::fixed << std::setprecision(2) << VSPDV << std::endl;//"Vrijednost sa PDV-om";
			 			prod_off_write.close();
			 			
			 			//ovaj dio koda spasava samo brojeve koji su bitni za izracunavanje ukupnog dijela
			 			//security
			 			std::ofstream sec_meta_file_write;
						std::ifstream sec_meta_file_read(f_meta);
						if(sec_meta_file_read.fail()){
				 			std::cout << "Error 404 - file not found" << std::endl;
				 		}
						 else
				 		{
				 			sec_meta_file_write.open(f_meta, std::ios::app);
				 			sec_meta_file_write << std::setw(15) << std::left << std::fixed << std::setprecision(3) << vol;
				 			sec_meta_file_write << std::setw(15) << std::left << std::fixed << std::setprecision(2) << PRC;
				 			sec_meta_file_write << std::setw(15) << std::left << std::fixed << std::setprecision(2) << VRD;
				 			sec_meta_file_write << std::setw(15) << std::left << std::fixed << std::setprecision(2) << PDV;
				 			sec_meta_file_write << std::setw(15) << std::left << std::fixed << std::setprecision(2) << VSPDV << std::endl;
				 			sec_meta_file_write.close();
						}
				 		
			 			//importer za kreiranje ukupnog rezultata - predstoji
		 			}
		 			//kad je program zavrsio unos proizvoda u fajl da bi nastavili ili okoncali petlju morate da date odgovor
		 			std::cout << "Da li zelite unijeti jos proizvoda: (DA/NE): ";
					std::cin >> decision;
//					std::string decision_rep;
//					decision_rep = decision;
					if(decision == "DA" || decision == "da" || decision == "Da" || decision == "dA")
					{
						
					}
					else
					{
						prod_off_write.open(fname, std::ios::app);
						prod_off_write << " " << std::setw(53) << std::left << "____________________________________________________________________________________________________________________________________________" << std::endl;
			 			prod_off_write << " " << std::setw(53) << std::left << "Ukupno";//"Naziv proizvoda";
						prod_off_write << " " << std::setw(7) << std::left << "-"; //"J/M";
						prod_off_write << " " << std::setw(15) << std::left << std::fixed << std::setprecision(3) << "-";//"Kolicina";
						prod_off_write << " " << std::setw(15) << std::left << std::fixed << std::setprecision(2) << "-";//"Cijena";
						prod_off_write << " " << std::setw(15) << std::left << std::fixed << std::setprecision(2) << VRD_IS;//"Vrijednost";
						prod_off_write << " " << std::setw(15) << std::left << std::fixed << std::setprecision(2) << PDV_IS;//"PDV";
						prod_off_write << " " << std::setw(20) << std::left << std::fixed << std::setprecision(2) << VSPDV_IS << std::endl;//"Vrijednost sa PDV-om";
			 			prod_off_write.close();
					}

				}while(decision == "DA" || decision == "da" || decision == "Da" || decision == "dA");			
				//sada mozemo zavrsiti i narednu petlju ukoliko nemamo vise fakturi da dodamo i program nas vraca u petlju supply klase
				std::cout << "Da li zelite unijeti jos faktura (DA/NE): ";
				std::cin >> decision_2;
				std::cout << std::endl;
			}while(decision_2 == "DA" || decision_2 == "da" || decision_2 == "Da" || decision_2 == "dA");
		}

		//Drugo mjesto gdje se provjerava varijabla input ukoliko nije tačna na prvom provjeravanju

		else if (input == "hn")
		{
			std::string odluka;
			std::cout << "Dobro dosli u historiju nabavki" << std::endl;
			std::cout << "Unesite naziv fakture koji zelite vidjeti: ";
			std::cin >> odluka;
			std::cout << std::endl;
			std::cout << "========================================================================================================================================================================" << std::endl;
			std::string path = "C:\\Users\\Dzenan\\Documents\\C++\\Trade_software\\Fakture/" + odluka + ".txt";
			std::ifstream my_file_read(path);
			if(my_file_read.fail()){
				std::cout << "Error 404 - file not found!" << std::endl;
			}
			else
			{
				std::string line;
				while(getline(my_file_read, line))
				{
					std::cout << line << std::endl;
				}
				my_file_read.close();
			}
		}
		// Treće mjesto gdje se provjerava varijabla input ukoliko na prethodna dva mjeta nije tačna
		else if (input == "back"){
			std::unique_ptr<Welcome> wel {new Welcome()};
		}

		//Četvrto mjesto gdje se provjerava varijabla input ukoliko na prethodna dva mjeta nije tačna

		else if (input == "help"){
			std::cout << "Dobro dosli u odsijek za nabavku\n Odaberite komandu:\n 1. Ulazne fakture (inpf)\n 2. Historija nabavki (hn)\n 3. Historija faktura (Fakture)" << std::endl;
			std::cout << "========================================================================================================================================================================" << std::endl;
		}

		// Peto mjesto gdje se provjerava varijabla input ukoliko na prethodna dva mjeta nije tačna

		else if (input == "Fakture" || input == "fakture")
		{
			std::cout << "Dobro dosli u historiju nabavki" << std::endl;
			std::cout << std::endl;
			std::cout << "========================================================================================================================================================================" << std::endl;
			std::string path = "C:\\Users\\Dzenan\\Documents\\C++\\Trade_software/his_nabavke.txt";
			std::ifstream my_file_read(path);
			if(my_file_read.fail()){
				std::cout << "Error 404 - file not found!" << std::endl;
			}
			else
			{
				std::string line;
				while(getline(my_file_read, line))
				{
					std::cout << line << std::endl;
				}
				my_file_read.close();
			}
		}

		//Šesto mjesto gdje se provjerava varijabla input ukoliko na prethodna dva mjeta nije tačna

		else if(input == "LogInTrue")
		{
			std::cout << "Dobro dosli u historiju uspjesne prijave u sistem" << std::endl;
			std::cout << std::endl;
			std::cout << "========================================================================================================================================================================" << std::endl;
			std::string path = "C:\\Users\\Dzenan\\Documents\\C++\\Trade_software/history_h.txt";
			std::ifstream my_file_read(path);
			if(my_file_read.fail()){
				std::cout << "Error 404 - file not found!" << std::endl;
			}
			else
			{
				std::string line;
				while(getline(my_file_read, line))
				{
					std::cout << line << std::endl;
				}
				my_file_read.close();
			}
		}

		//Sedmo mjesto gdje se provjerava varijabla input ukoliko na prethodna dva mjeta nije tačna

		else if(input == "LogInFalse")
		{
			std::cout << "Dobro dosli u historiju neuspjesne prijave u sistem" << std::endl;
			std::cout << std::endl;
			std::cout << "========================================================================================================================================================================" << std::endl;
			std::string path = "C:\\Users\\Dzenan\\Documents\\C++\\Trade_software/history_failed.txt";
			std::ifstream my_file_read(path);
			if(my_file_read.fail()){
				std::cout << "Error 404 - file not found!" << std::endl;
			}
			else
			{
				std::string line;
				while(getline(my_file_read, line))
				{
					std::cout << line << std::endl;
				}
				my_file_read.close();
			}
		}

		//ukoliko niti na jednom prethodnom mjestu varijabla nije tačna onda će se ispistati kod ispod

		else
		{
			std::cout << "Error code 0x02 - komanda koju ste unijeli nije poznata" << std::endl;
		}
}
	
}

Supply::~Supply()
{
}
