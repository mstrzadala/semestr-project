// projekt_loty.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Funkcje.h"
#include <iostream>
#include <windows.h>
using namespace std;

int main(int argc, char* argv[])
{
	SetConsoleOutputCP((1250));
	if (argc > 2 && strcmp(argv[1], "-i") == 0)
	{
		odloty *glowa = nullptr;
		wczytywanie(argv[2], glowa);
		zapisywanie(glowa);
		zwolnij(glowa);
		return 0;
	}
	else if (argc > 2 && strcmp(argv[1], "-h") == 0)
	{
		cout << "W celu poprawnego uruchomienia programu nale¿y u¿yæ prze³¹cznika"
			"''-i'' oraz podaæ nazwê pliku z odlotami, o rozszerzeniu .txt i znajduj¹cym siê w folderze roboczym. "
			"W momencie poprawnego wywo³ania programu zwróci on wartoœæ ''0''." << endl;
		return 1;
	}
	else
	{
		cout << "Niepoprawne wywo³anie programu! W celu poprawnego uruchomienia programu nale¿y u¿yæ prze³¹cznika"
			"''-i'' oraz podaæ nazwê pliku z odlotami, o rozszerzeniu .txt i znajduj¹cym siê w folderze roboczym. "
			"W momencie poprawnego wywo³ania programu zwróci on wartoœæ ''0''." << endl;
		return 2;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
