#include <iostream>
#include "main_header.h"


using namespace std;
string login;
string user;
int login_times;
string password_login;
string password;
string command;

void glowne_funkcje::login_screen() {
    
    ustaw_kursor(0, 0);
    while (1) {
        system("cls");
        system("color C");
        gotoxy(45, 5); cout << " ----------------------------- ";
        gotoxy(45, 6); cout << " | Wyporzyczalnia Samochodow | ";
        gotoxy(45, 7); cout << " ----------------------------- ";
        gotoxy(45, 9); cout << " 	1.Logowanie      	       ";
        gotoxy(45, 10); cout << " 	2.Rejestracja      	       ";
        gotoxy(45, 11); cout << " 	3.Instrukcja	           ";
        gotoxy(45, 12); cout << " 	4.WYJDZ			           ";
        gotoxy(45, 13); cout << ">>> WYBOR:		               ";
        char op = _getch();
        switch (op) {
        case '1':
            logowanie();
            break;

        case '2':
            rejestracja();
            break;

        case '3':
            instrukcja();
            break;

        case '4':
            exit(0);
            break;

        default:
            cout << "Blad! Sprobuj ponowownie";
            break;
        }
    }
}
    void glowne_funkcje::rejestracja() {
        system("cls");
        cout << "\n\n" << endl;
        cout << "Rejestracja" << endl << "----------------" << endl;
        cout << "login: ";
        cin >> user;
        cout << "haslo: ";
        cin >> password;

        cout << "\n\n";
        cout << "Zarejestrowano pomyslnie!" << endl;
        glowne_funkcje gf;
        gf.login_screen();
    }

    void glowne_funkcje::logowanie() {
        system("cls");
        login_times = 3;
        while (login_times > 0) {


            cout << "\n\n";
            cout << "Login" << endl << "_____";
            cout << "\n";

            cout << "login: ";
            cin >> login;
            cout << "haslo: ";
            cin >> password_login;





            if (login == user && password_login == password) {
                cout << "Zalogowano pomyslnie!" << endl;
                cout << "Witamy" << user << "!";
                glowne_funkcje gf;
                gf.menu();
                break;

            }
            else if (login != user && password_login == password) {

                cout << "Bledna nazwa uzytkownika!" << endl;
                login_times--;

            }

            else if (login == user && password_login != password) {

                cout << "Bledne haslo!" << endl;
                login_times--;

            }
            else {
                cout << "Wszystko jest bledne!" << endl;
                login_times--;
            }
            





        }     
    }


