#pragma once
#ifndef sprawdzarka_h
#define sprawdzarka_h
#include <string>
using namespace std;

bool podzial_na_stringi(int numer_linijki, string nazwa, ifstream &plik, string &kod, string &miasto, string &data, string &nazwisko, string &miejsce);
bool sprawdzenie_kodu(int linijka, string nazwa, string kod);
bool sprawdzenie_miasta(int linijka, string nazwa, string miasto);
bool sprawdzenie_daty(int linijka, string nazwa, string data);
bool sprawdzenie_nazwiska(int linijka, string nazwa, string nazwisko);
bool sprawdzenie_miejsca(int linijka, string nazwa, string miejsce);
bool sprawdzenie_poprawnosci_danych(int linijka, string nazwa, string kod, string miasto, string data, string nazwisko, string miejsce);
#endif
