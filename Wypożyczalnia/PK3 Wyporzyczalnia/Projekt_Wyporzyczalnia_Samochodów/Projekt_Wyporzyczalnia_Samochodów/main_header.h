#pragma once
#include <iostream>
#include<conio.h>
#include<dos.h>
#include <windows.h>
#include<time.h>
#include <string>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <vector>
#include<time.h>
#include <iomanip>
#include <map>
#include <algorithm>

using namespace std;
#define SCREEN_WIDTH 90		
#define SCREEN_HEIGHT 26			
#define WIN_WIDTH 70

void gotoxy(int x, int y);


class glowne_funkcje {
public:
	/**Funkcja login_screen jest odpowiedzialna za poprawne dzia³anie ekranu logowania*/
	void login_screen();
	/**Funkcja instrukcja jest odpowiedzialna za wyswietlenie instrukcji*/
	void instrukcja();
	/**Funkcja ustaw_kursor jest odpowiedzialna za ustawienie kursora*/
	void ustaw_kursor(bool widoczny, DWORD rozmiar);	
	/**Funkcja menu jest odpowiedzialna za wyswietlenie menu*/
	void menu();
	void rent_a_car();
	void logowanie();
	void rejestracja();
	void lista_aut();
	void rent();


	int tmp;
	int carnumber = 0;
	int days = 0;
	string carname;
	string name;
	int cena;
	void danewynajmu();
	string fileName = "cennik_samochodow.txt";

	template <typename T>
	T calculateRentalCost(const string& fileName, const string& carName, const T& days) {
		map<string, T> rentalPrices;
		ifstream file(fileName);

		if (!file.is_open()) {
			cout << "Nie mo¿na otworzyæ pliku " << fileName << endl;
			return 0;
		}

		string line;
		while (getline(file, line)) {
			int spaceIndex = line.find(' ');
			string car = line.substr(0, spaceIndex);
			T price = stod(line.substr(spaceIndex + 1));
			rentalPrices[car] = price;
		}

		file.close();

		T rentalCost = rentalPrices[carName] * days;
		return rentalCost;
	}

};


