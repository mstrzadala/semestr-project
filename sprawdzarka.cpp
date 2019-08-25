#include "pch.h"
#include "Funkcje.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

/*48 - 57 -> cyfry, 65 - 90 -> duze litery, 97 - 122 -> male litery*/

bool podzial_na_stringi(int numer_linijki, string nazwa, ifstream &plik, string &kod, string &miasto, string &data, string &nazwisko, string &miejsce)
{

	for (string linia; getline(plik, linia);)
	{
		int licznik_spacji = 0;
		for (int i = 0; i < linia.size(); i++)
		{
			if (linia[i] == 32 && i != linia.size() - 1)
			{
				licznik_spacji++;
			}
		}
		if (licznik_spacji != 4)
		{
			cout << "W linijce " << numer_linijki << " pliku " << nazwa <<
				" znajduj¹ siê niekompletne lub niepoprawne dane. Linijka zosta³a pominiêta." << endl;
			return false;
		}
		unsigned int pole = 0;
		vector <string> dane;
		int pos = 0, end;
		while (true)
		{
			end = linia.find(' ', pos);
			if (end == string::npos)
			{
				dane.push_back(linia.substr(pos, linia.size()));
				break;
			}
			else
			{
				dane.push_back(linia.substr(pos, end - pos));
				pos = end + 1;
			}
		}
		kod = dane[pole], miasto = dane[pole + 1], data = dane[pole + 2], nazwisko = dane[pole + 3], miejsce = dane[pole + 4];
		return true;
	}
}

bool sprawdzenie_kodu(int linijka, string nazwa, string kod)
{
	if (kod.size() == 5)
	{
		for (int i = 0; i < kod.size(); i++)
		{
			if (!isalnum(kod[i]))
			{
				cout << "W linijce " << linijka << " pliku " << nazwa <<
					" kod lotu zawiera niedozwolone znaki. Linijka zosta³a pominiêta." << endl;
				return false;
			}
		}
	}
	else
	{
		cout << "W linijce " << linijka << " pliku " << nazwa <<
			" kod lotu jest niepoprawny. Linijka zosta³a pominiêta." << endl;
		return false;
	}
	return true;
}

bool sprawdzenie_miasta(int linijka, string nazwa, string miasto)
{
	for (int i = 0; i < miasto.size(); i++)
	{
		if (!isalpha(miasto[i]))
		{
			cout << "W linijce " << linijka << " pliku " << nazwa <<
				" nazwa miasta zawiera niedozwolone znaki. Linijka zosta³a pominiêta." << endl;
			return false;
		}
	}
	return true;
}

bool sprawdzenie_daty(int linijka, string nazwa, string data)
{
	if (data.size() == 10)
	{
		if (data[4] != 45 && data[7] != 45)
		{
			cout << "W linijce " << linijka << " pliku " << nazwa <<
				" data lotu zawiera niedozwolone znaki. Linijka zosta³a pominiêta." << endl;
			return false;
		}
		for (int i = 0; i < 4; i++)
		{
			if (!isdigit(data[i]))
			{
				cout << "W linijce " << linijka << " pliku " << nazwa <<
					" kod lotu zawiera niedozwolone znaki. Linijka zosta³a pominiêta." << endl;
				return false;
			}
		}
	}
	else
	{
		cout << "W linijce " << linijka << " pliku " << nazwa << " data lotu jest niepoprawny. Linijka zosta³a pominiêta." << endl;
		return false;
	}
	return true;
}

bool sprawdzenie_nazwiska(int linijka, string nazwa, string nazwisko)
{
	for (int i = 0; i < nazwisko.size(); i++)
	{
		if (!isalpha(nazwisko[i]))
		{
			cout << "W linijce " << linijka << " pliku " << nazwa <<
				" nazwisko zawiera niedozwolone znaki. Linijka zosta³a pominiêta." << endl;
			return false;
		}
	}
	return true;
}

bool sprawdzenie_miejsca(int linijka, string nazwa, string miejsce)
{
	for (int i = 0; i < miejsce.size(); i++)
	{
		if (!isdigit(miejsce[i]))
		{
			cout << "W linijce " << linijka << " pliku " << nazwa <<
				" numer miejsca zawiera niedozwolone znaki. Linijka zosta³a pominiêta." << endl;
			return false;
		}
	}
	return true;
}

bool sprawdzenie_poprawnosci_danych(int linijka, string nazwa, string kod, string miasto, string data, string nazwisko, string miejsce)
{
	if (!sprawdzenie_kodu(linijka, nazwa, kod))
	{
		return false;
	}
	if (!sprawdzenie_miasta(linijka, nazwa, miasto))
	{
		return false;
	}
	if (!sprawdzenie_daty(linijka, nazwa, data))
	{
		return false;
	}
	if (!sprawdzenie_nazwiska(linijka, nazwa, nazwisko))
	{
		return false;
	}
	if (!sprawdzenie_miejsca(linijka, nazwa, miejsce))
	{
		return false;
	}
}