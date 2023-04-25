#pragma once
#include "main_header.h"

template <typename T>
void show(const T& fileName) {
    system("cls");
    ifstream inA(fileName);
    char str[200];
    while (inA) {
        inA.getline(str, 200);
        if (inA) cout << str << endl;
    }
}

void showTesla() {
    show("Tesla.txt");
    _getch();
}

void showAudi() {
    show("Audi.txt");
    _getch();
}


void showPorsche() {
    show("Porsche.txt");
    _getch();
}

void showFiat() {
    show("Fiat.txt");
    _getch();
}

void showOpel() {
    show("Opel.txt");
    _getch();
}

void showMazda() {
    show("Mazda.txt");
    _getch();
}

void showCitroen() {
    show("Citroen.txt");
    _getch();
}

void showHonda() {
    show("Honda.txt");
    _getch();
}

void showJeep() {
    show("Jeep.txt");
    _getch();
}

