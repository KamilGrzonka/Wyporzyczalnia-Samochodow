#include "main_header.h"
#include "car.h"
void glowne_funkcje::lista_aut()
{

    ustaw_kursor(0, 0);
    while (1) {
        system("cls");
        system("color A");
        gotoxy(45, 5); cout << "----------------------------- ";
        gotoxy(45, 6); cout << "|     Lista Samochodow      | ";
        gotoxy(45, 7); cout << "----------------------------- ";
        gotoxy(25, 9); cout << " 	Wybierz jedna z opcji aby dowiedziec sie wiecej na temat danego samochodu     ";
        gotoxy(45, 10); cout << " 	1.Tesla         ";
        gotoxy(45, 11); cout << " 	2.Audi          ";
        gotoxy(45, 12); cout << " 	3.Porsche       ";
        gotoxy(45, 13); cout << " 	4.Fiat          ";
        gotoxy(45, 14); cout << " 	5.Opel          ";
        gotoxy(45, 15); cout << " 	6.Mazda         ";
        gotoxy(45, 16); cout << " 	7.Citroen       ";
        gotoxy(45, 17); cout << " 	8.Honda         ";
        gotoxy(45, 18); cout << " 	9.Jeep          ";
        gotoxy(45, 19); cout << " 	0.POWROT                    ";
        gotoxy(45, 20); cout << ">>> WYBOR:		               ";
        char op = _getch();
        switch (op) {
        case '1':
            showTesla();
            break;
        case '2':
            showAudi();
            break;
        case '3':
            showPorsche();
            break;
        case '4':
            showFiat();
            break;
        case '5':
            showOpel();
            break;
        case '6':
            showMazda();
            break;
        case '7':
            showCitroen();
            break;
        case '8':
            showHonda();
            break;
        case '9':
            showJeep();
            break;
        case '0':
            rent_a_car();
            break;
        }
    }
}



