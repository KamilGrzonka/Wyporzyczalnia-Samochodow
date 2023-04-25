#include "main_header.h"

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Pozycja_Kursora;

void glowne_funkcje::menu() {
	ustaw_kursor(0, 0);
	while (1) {												
		system("cls");
		system("color A");									
		gotoxy(45, 5); cout << " ----------------------------- ";
		gotoxy(45, 6); cout << " | Wyporzyczalnia Samochodow | ";
		gotoxy(45, 7); cout << " ----------------------------- ";
		gotoxy(45, 9); cout << " 	1.Wyporzycz auto      	   ";
		gotoxy(45, 10); cout <<" 	2.Instrukcja	           ";
		gotoxy(45, 11); cout <<" 	3.WYJDZ			           ";
		gotoxy(45, 13); cout <<">>> WYBOR:		               ";
		char op = _getch();

		switch (op) {
		case '1':
			rent_a_car();
			break;

		case '2':
			instrukcja();
			break;

		case '3':
			exit(0);
			break;

		default:
			cout << "Blad! Sprobuj ponowownie";
			break;
		}

	}
}

void gotoxy(int x, int y) {
	Pozycja_Kursora.X = x;
	Pozycja_Kursora.Y = y;
	SetConsoleCursorPosition(console, Pozycja_Kursora);
}

void glowne_funkcje::ustaw_kursor(bool widoczny, DWORD rozmiar) {
	if (rozmiar == 0) {
		rozmiar = 20;
	}
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = widoczny;
	lpCursor.dwSize = rozmiar;
	SetConsoleCursorInfo(console, &lpCursor);
}

void glowne_funkcje::instrukcja() {
	system("cls");
	gotoxy(45, 5); cout << " ----------------------------- ";
	gotoxy(45, 6); cout << " | Wyporzyczalnia Samochodow |";
	gotoxy(45, 7); cout << " ----------------------------- ";
	gotoxy(25, 9); cout << "Obok kazdej z dostêpnych w menu opcji widnieja numerki np. 1., 2. itd." << endl;
	gotoxy(15, 10); cout << "Aby skorzystac z wybranej funkcji nalezy nacisnac na klawiaturze odpowiadajacy jej numerek" << endl;
	gotoxy(40, 12); cout << "Nacisnij dowolny przycisk by kontynuowac";
	_getch();
}