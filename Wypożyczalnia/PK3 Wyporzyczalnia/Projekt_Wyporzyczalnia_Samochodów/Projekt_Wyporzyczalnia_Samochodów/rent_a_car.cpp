#include "main_header.h"
#include "lista.h"
#include "cena_i_moc.h"

void glowne_funkcje::rent_a_car()
{

    ustaw_kursor(0, 0);
    while (1) {
        VechiclePrice vprice;
        VechiclePower vpower;
        auto_cena ac;
        system("cls");
        system("color A");
        gotoxy(45, 5); cout << "----------------------------- ";
        gotoxy(45, 6); cout << "| Wyporzyczalnia Samochodow | ";
        gotoxy(45, 7); cout << "----------------------------- ";
        gotoxy(45, 9); cout << " 	1.Lista samochodow         ";
        gotoxy(45, 10); cout << " 	2.Sortuj cena, rosnaco     ";
        gotoxy(45, 11); cout << " 	3.Sortuj cena, malejaco    ";
        gotoxy(45, 12); cout << " 	4.Pokaz samochodu ponizej wybranej ceny ";
        gotoxy(45, 13); cout << " 	5.Pokaz samochodu ponizej wybranej mocy ";
        gotoxy(45, 14); cout << " 	6.Wyporzycz auto ";
        gotoxy(45, 15); cout << " 	7.Instrukcja               ";
        gotoxy(45, 16); cout << " 	8.WYJDZ                    ";
        gotoxy(45, 17); cout << ">>> WYBOR:		               ";
        char op = _getch();
        switch (op) {
        case '1':
            lista_aut();
            break;
        case '2':
            sortowanieup();
            //vprice.LoadPricesFromFile("cennik_samochodow");
            break;

        case '3':
            sortowaniedown();
            //vprice.LoadPricesFromFile("cennik_samochodow");
            break;

        case '4':
            ponizejcena();
           // vprice.LoadPricesFromFile("cennik_samochodow");                 // dokonczyc te funkcje
            break;

        case '5':
            ponizejmoc();
            //vpower.LoadPowerFromFile("moc_samochodow");
            break;

        case '6':
            rent();
            break;

        case '7':
            instrukcja();
            break;

        case '8':
            exit(0);
            break;

        default:
            cout << "Blad! Sprobuj ponowownie";
            break;
        }
    }
}
