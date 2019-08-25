#pragma once
#ifndef Funkcje_h
#define Funkcje_h
#include <string>
using namespace std;
struct odloty
{
	string kod;
	string miasto;
	string data;
	string nazwisko;
	string miejsce;
	bool obecnosc_pliku;
	odloty *nastêpny;
};

odloty *stworz_odlot(string kod, string miasto, string data, string nazwisko, string miejsce);
void dodaj_odlot(odloty *&glowa, string kod, string miasto, string data, string nazwisko, string miejsce);
void wczytywanie(string nazwa, odloty *&glowa);
void zapisz_pasazerow(ofstream &plik, odloty *akt_odloty);
void zapisywanie(odloty *glowa);
void zwolnij(odloty *&glowa);
#endif