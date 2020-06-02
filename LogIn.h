#ifndef LOGIN_H
#define LOGIN_H
#include <string>//klasa koja omogućava naprednije kontrolisanje teksta u odnosu na char varijablu
#include <iostream>//input/output biblioteka
class LogIn
{
	private:
		/*Definisanje privatnih varijabli koje će služiti za login
		Sve što je definisano ovdje u ovom dokumentu je prototip
		Prototip je način da definišemo sve potrebne metode(funkcije) i konstruktore,
		ali da ih ne inicijaliziramo. 
		Zašto to?
		Jer u količini koda koji ćemo pisati često se zagubimo i sve postane previše
		masivno, tako da je najbolje definisati sve elemente na početku, a kasnije ih
		razraditi.
		Da li će to uticati da dobijemo error?
		Ne, jer će program znati da postoji tako definisan element, te će ga pretražiti u
		ostatku koda.
		*/
		const std::string username = "Dzenan";
		const std::string password = "drss12345";
	public:
		void set_UserName(std::string usname);
		std::string get_UserName(std::string usname);
		void set_Password(std::string passwd);
		std::string get_Password();
		LogIn();
		~LogIn();
};

#endif
