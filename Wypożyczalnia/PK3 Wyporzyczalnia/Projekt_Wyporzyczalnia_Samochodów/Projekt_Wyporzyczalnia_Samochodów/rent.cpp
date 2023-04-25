#include "main_header.h"


void glowne_funkcje::rent() {
    ustaw_kursor(0, 0);
    while (1) {
        system("cls");
        system("color A");
        gotoxy(45, 5); cout << "----------------------------- ";
        gotoxy(45, 6); cout << "|    Wyporzycz samochod     | ";
        gotoxy(45, 7); cout << "----------------------------- ";
        gotoxy(35, 9); cout << "Wybierz jedna z opcji do wyporzyczenia     ";
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
            tmp = 1;
            danewynajmu();
            break;
        case '2':
            tmp = 2;
            danewynajmu();
            break;
        case '3':
            tmp = 3;
            danewynajmu();
            break;
        case '4':
            tmp = 4;
            danewynajmu();
            break;
        case '5':
            tmp = 5;
            danewynajmu();
            break;
        case '6':
            tmp = 6;
            danewynajmu();
            break;
        case '7':
            tmp = 7;
            danewynajmu();
            break;
        case '8':
            tmp = 8;
            danewynajmu();
            break;
        case '9':
            tmp = 9;
            danewynajmu();
            break;
        case '0':
            rent_a_car();
            break;
        }
    }
}



void glowne_funkcje :: danewynajmu() {
    system("cls");
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Prosze podazaj za instrukcja: " << endl;
    cout << "Podaj swoje imie:" << endl;
    cin >> name;
    cout << "Podaj liczbe dni na ile chcesz dane auto wyporzczyc: ";
    cin >> days;
    cout << endl;
    if (tmp == 1) {
        carname = "Tesla";
        double rentalCost = calculateRentalCost<double>(fileName, carname, days);

        cout << "\n\t\t   Wyporzyczalnia samochodow - wszystkie dane dt zamowienia             " << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	| Imie klienta:" << "------------------|" << setw(10) << name << " |" << endl;
        cout << "\t\t	| Marka Auta :" << "-------------------|" << setw(10) << carname << " |" << endl;
        cout << "\t\t	| Ilosc dni :" << "--------------------|" << setw(10) << days << " |" << endl;
        cout << "\t\t	 ________________________________________________________" << endl;
        cout << "\n";
        cout << "\t\t	| Calosc do zaplaty :" << "------------|" << setw(10) << rentalCost << " |" << endl;
        cout << "\t\t	 ________________________________________________________" << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	Kwote nalezy uiscic przed uplywem terminu" << endl;
        cout << "\t\t	W przeciwnym wypadku zostanie nalozona kara pieniezna" << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;

        _getch();
        exit(0);
    }
    else if (tmp == 2) {
        carname = "Audi";
        double rentalCost = calculateRentalCost<double>(fileName, carname, days);

        cout << "\n\t\t   Wyporzyczalnia samochodow - wszystkie dane dt zamowienia             " << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	| Imie klienta:" << "------------------|" << setw(10) << name << " |" << endl;
        cout << "\t\t	| Marka Auta :" << "-------------------|" << setw(10) << carname << " |" << endl;
        cout << "\t\t	| Ilosc dni :" << "--------------------|" << setw(10) << days << " |" << endl;
        cout << "\t\t	 ________________________________________________________" << endl;
        cout << "\n";
        cout << "\t\t	| Calosc do zaplaty :" << "------------|" << setw(10) << rentalCost << " |" << endl;
        cout << "\t\t	 ________________________________________________________" << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	Kwote nalezy uiscic przed uplywem terminu" << endl;
        cout << "\t\t	W przeciwnym wypadku zostanie nalozona kara pieniezna" << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;

        _getch();
        exit(0);
    }
    else if (tmp == 3) {
        carname = "Porsche";
        double rentalCost = calculateRentalCost<double>(fileName, carname, days);

        cout << "\n\t\t   Wyporzyczalnia samochodow - wszystkie dane dt zamowienia             " << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	| Imie klienta:" << "------------------|" << setw(10) << name << " |" << endl;
        cout << "\t\t	| Marka Auta :" << "-------------------|" << setw(10) << carname << " |" << endl;
        cout << "\t\t	| Ilosc dni :" << "--------------------|" << setw(10) << days << " |" << endl;
        cout << "\t\t	 ________________________________________________________" << endl;
        cout << "\n";
        cout << "\t\t	| Calosc do zaplaty :" << "------------|" << setw(10) << rentalCost << " |" << endl;
        cout << "\t\t	 ________________________________________________________" << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	Kwote nalezy uiscic przed uplywem terminu" << endl;
        cout << "\t\t	W przeciwnym wypadku zostanie nalozona kara pieniezna" << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;

        _getch();
        exit(0);
    }
    else if (tmp == 4) {
        carname = "Fiat";
        double rentalCost = calculateRentalCost<double>(fileName, carname, days);

        cout << "\n\t\t   Wyporzyczalnia samochodow - wszystkie dane dt zamowienia             " << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	| Imie klienta:" << "------------------|" << setw(10) << name << " |" << endl;
        cout << "\t\t	| Marka Auta :" << "-------------------|" << setw(10) << carname << " |" << endl;
        cout << "\t\t	| Ilosc dni :" << "--------------------|" << setw(10) << days << " |" << endl;
        cout << "\t\t	 ________________________________________________________" << endl;
        cout << "\n";
        cout << "\t\t	| Calosc do zaplaty :" << "------------|" << setw(10) << rentalCost << " |" << endl;
        cout << "\t\t	 ________________________________________________________" << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	Kwote nalezy uiscic przed uplywem terminu" << endl;
        cout << "\t\t	W przeciwnym wypadku zostanie nalozona kara pieniezna" << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;

        _getch();
        exit(0);
    }
    else if (tmp == 5) {
        carname = "Opel";
        double rentalCost = calculateRentalCost<double>(fileName, carname, days);

        cout << "\n\t\t   Wyporzyczalnia samochodow - wszystkie dane dt zamowienia             " << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	| Imie klienta:" << "------------------|" << setw(10) << name << " |" << endl;
        cout << "\t\t	| Marka Auta :" << "-------------------|" << setw(10) << carname << " |" << endl;
        cout << "\t\t	| Ilosc dni :" << "--------------------|" << setw(10) << days << " |" << endl;
        cout << "\t\t	 ________________________________________________________" << endl;
        cout << "\n";
        cout << "\t\t	| Calosc do zaplaty :" << "------------|" << setw(10) << rentalCost << " |" << endl;
        cout << "\t\t	 ________________________________________________________" << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	Kwote nalezy uiscic przed uplywem terminu" << endl;
        cout << "\t\t	W przeciwnym wypadku zostanie nalozona kara pieniezna" << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;

        _getch();
        exit(0);
    }
    else if (tmp == 6) {
        carname = "Mazda";
        double rentalCost = calculateRentalCost<double>(fileName, carname, days);

        cout << "\n\t\t   Wyporzyczalnia samochodow - wszystkie dane dt zamowienia             " << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	| Imie klienta:" << "------------------|" << setw(10) << name << " |" << endl;
        cout << "\t\t	| Marka Auta :" << "-------------------|" << setw(10) << carname << " |" << endl;
        cout << "\t\t	| Ilosc dni :" << "--------------------|" << setw(10) << days << " |" << endl;
        cout << "\t\t	 ________________________________________________________" << endl;
        cout << "\n";
        cout << "\t\t	| Calosc do zaplaty :" << "------------|" << setw(10) << rentalCost << " |" << endl;
        cout << "\t\t	 ________________________________________________________" << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	Kwote nalezy uiscic przed uplywem terminu" << endl;
        cout << "\t\t	W przeciwnym wypadku zostanie nalozona kara pieniezna" << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;

        _getch();
        exit(0);
    }
    else if (tmp == 7) {
        carname = "Citroen";
        double rentalCost = calculateRentalCost<double>(fileName, carname, days);

        cout << "\n\t\t   Wyporzyczalnia samochodow - wszystkie dane dt zamowienia             " << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	| Imie klienta:" << "------------------|" << setw(10) << name << " |" << endl;
        cout << "\t\t	| Marka Auta :" << "-------------------|" << setw(10) << carname << " |" << endl;
        cout << "\t\t	| Ilosc dni :" << "--------------------|" << setw(10) << days << " |" << endl;
        cout << "\t\t	 ________________________________________________________" << endl;
        cout << "\n";
        cout << "\t\t	| Calosc do zaplaty :" << "------------|" << setw(10) << rentalCost << " |" << endl;
        cout << "\t\t	 ________________________________________________________" << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	Kwote nalezy uiscic przed uplywem terminu" << endl;
        cout << "\t\t	W przeciwnym wypadku zostanie nalozona kara pieniezna" << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;

        _getch();
        exit(0);
    }
    else if (tmp == 8) {
        carname = "Honda";
        double rentalCost = calculateRentalCost<double>(fileName, carname, days);

        cout << "\n\t\t   Wyporzyczalnia samochodow - wszystkie dane dt zamowienia             " << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	| Imie klienta:" << "------------------|" << setw(10) << name << " |" << endl;
        cout << "\t\t	| Marka Auta :" << "-------------------|" << setw(10) << carname << " |" << endl;
        cout << "\t\t	| Ilosc dni :" << "--------------------|" << setw(10) << days << " |" << endl;
        cout << "\t\t	 ________________________________________________________" << endl;
        cout << "\n";
        cout << "\t\t	| Calosc do zaplaty :" << "------------|" << setw(10) << rentalCost << " |" << endl;
        cout << "\t\t	 ________________________________________________________" << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	Kwote nalezy uiscic przed uplywem terminu" << endl;
        cout << "\t\t	W przeciwnym wypadku zostanie nalozona kara pieniezna" << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;

        _getch();
        exit(0);
    }
    else if (tmp == 9) {
        carname = "Jeep";
        double rentalCost = calculateRentalCost<double>(fileName, carname, days);

        cout << "\n\t\t   Wyporzyczalnia samochodow - wszystkie dane dt zamowienia             " << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	| Imie klienta:" << "------------------|" << setw(10) << name << " |" << endl;
        cout << "\t\t	| Marka Auta :" << "-------------------|" << setw(10) << carname << " |" << endl;
        cout << "\t\t	| Ilosc dni :" << "--------------------|" << setw(10) << days << " |" << endl;
        cout << "\t\t	 ________________________________________________________" << endl;
        cout << "\n";
        cout << "\t\t	| Calosc do zaplaty :" << "------------|" << setw(10) << rentalCost << " |" << endl;
        cout << "\t\t	 ________________________________________________________" << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;
        cout << "\t\t	Kwote nalezy uiscic przed uplywem terminu" << endl;
        cout << "\t\t	W przeciwnym wypadku zostanie nalozona kara pieniezna" << endl;
        cout << "\t\t	///////////////////////////////////////////////////////////" << endl;

        _getch();
        exit(0);
    }
    
    
}