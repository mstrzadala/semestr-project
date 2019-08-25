#include "pch.h"
#include "sprawdzarka.h"
#include "Funkcje.h"
#include <iostream> 
#include <string>
#include <list>
#include <fstream>
#include <map>
#include <iomanip>

using namespace std;

odloty *stworz_odlot(string kod, string miasto, string data, string nazwisko, string miejsce)
{
	odloty *nowy = new odloty;
	nowy->kod = kod;
	nowy->miasto = miasto;
	nowy->data = data;
	nowy->nazwisko = nazwisko;
	nowy->miejsce = miejsce;
	nowy->obecnosc_pliku = false;
	nowy->nastêpny = nullptr;
	return nowy;
}

void dodaj_odlot(odloty *&glowa, string kod, string miasto, string data, string nazwisko, string miejsce)
{
	if (glowa == nullptr)
	{
		glowa = stworz_odlot(kod, miasto, data, nazwisko, miejsce);
		return;
	}
	else
	{
		odloty *akt_odlot = glowa;
		while (akt_odlot)
		{
			if (akt_odlot->nastêpny == nullptr)
			{
				akt_odlot->nastêpny = stworz_odlot(kod, miasto, data, nazwisko, miejsce);
				return;
			}
			akt_odlot = akt_odlot->nastêpny;
		}
	}
}

void wczytywanie(string nazwa, odloty *&glowa)
{
	ifstream plik(nazwa);
	string linijka, kd, mo, da, no, m;
	int numer_linijki = 1;
	if (!plik)
	{
		cout << "Plik nie istnieje lub znajduje siê poza folderem roboczym!";
		return;
	}
	while (!plik.eof())
	{
		if (podzial_na_stringi(numer_linijki, nazwa, plik, kd, mo, da, no, m))
		{
			if (sprawdzenie_poprawnosci_danych(numer_linijki, nazwa, kd, mo, da, no, m))
			{
				dodaj_odlot(glowa, kd, mo, da, no, m);
			}
		}
		numer_linijki++;
	}
}

void zapisz_pasazerow(ofstream &plik, odloty *akt_odloty)
{
	map<int, string> pasazerowie;
	string lot = akt_odloty->kod;
	while (akt_odloty)
	{
		if (akt_odloty->miejsce != "")
		{
			int miejsce = stoi(akt_odloty->miejsce);
			if (akt_odloty->kod == lot)
			{
				pasazerowie[miejsce] = akt_odloty->nazwisko;
				akt_odloty->obecnosc_pliku = true;
			}
		}
		akt_odloty = akt_odloty->nastêpny;
	}
	for (auto iter = pasazerowie.begin(); iter != pasazerowie.end(); ++iter)
	{
		plik << setfill('0') << setw(2) << iter->first << " " << iter->second << endl;
	}
	plik << endl << "Liczba rezerwacji: " << pasazerowie.size();
}

void zapisywanie(odloty *glowa)
{
	odloty *akt_odloty = glowa;
	string nazwa;
	while (akt_odloty)
	{
		if (akt_odloty->obecnosc_pliku == false)
		{
			nazwa = akt_odloty->kod + ".txt";
			ofstream plik(nazwa);
			plik << "Symbol lotu: " << akt_odloty->kod << endl << "lotnisko: " << akt_odloty->miasto << endl
				<< "data lotu: " << akt_odloty->data << endl << endl << "Lista pasa¿erów: " << endl;
			zapisz_pasazerow(plik, akt_odloty);
		}
		akt_odloty = akt_odloty->nastêpny;
	}
}

void zwolnij(odloty *&glowa)
{
	odloty *akt_odlot = glowa;
	while (akt_odlot)
	{
		odloty *temp = akt_odlot->nastêpny;
		delete akt_odlot;
		akt_odlot = temp;
	}
}