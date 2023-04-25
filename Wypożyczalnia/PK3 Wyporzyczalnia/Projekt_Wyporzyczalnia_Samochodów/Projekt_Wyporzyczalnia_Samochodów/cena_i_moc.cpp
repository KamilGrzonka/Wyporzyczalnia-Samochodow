#include "main_header.h"
#include "lista.h"
#include "cena_i_moc.h"


void VechiclePrice :: LoadPricesFromFile(const string& file_name) {
        ifstream file(file_name);
        if (file.is_open()) {
            int cena;
            while (file >> cena) {
                PushBack(cena);
            }
            file.close();
        }
        else {
            cout << "Error opening file" << endl;
        }
    }
;


void VechiclePower :: LoadPowerFromFile(const string& file_name) {
        ifstream file(file_name);
        if (file.is_open()) {
            int power;
            while (file >> power) {
                PushBack(power);
            }
            file.close();
        }
        else {
            cout << "Error opening file" << endl;
        }
    }
;

/*void DisplayVehiclesBelowPrice(double max_cena) {
    cout << "Vehicles below " << max_cena << ":" << endl;
    for (const auto& cena : vehicles) {
        if (cena < max_cena) {
            cout << cena << endl;
        }
    }
}*/

vector<auto_cena> readcarsFromFile(const string& fileName) {
    vector<auto_cena> cars;
    ifstream file(fileName);
    if (file.is_open()) {
        while (!file.eof()) {
            auto_cena car;
            file >> car.marka >> car.cena;
            cars.push_back(car);
        }
        file.close();
    }
    else {
        cerr << "Error opening file: " << fileName << endl;
    }
    return cars;
}

vector<auto_cena> readcarsFromFilepower(const string& fileName) {
    vector<auto_cena> cars;
    ifstream file(fileName);
    if (file.is_open()) {
        while (!file.eof()) {
            auto_cena car;
            file >> car.marka >> car.moc;
            cars.push_back(car);
        }
        file.close();
    }
    else {
        cerr << "Error opening file: " << fileName << endl;
    }
    return cars;
}

bool compareByPriceup(const auto_cena& car1, const auto_cena& car2) {
    return car1.cena < car2.cena;
}

bool compareByPower(const auto_cena& car1, const auto_cena& car2) {
    return car1.moc < car2.moc;
}

bool compareByPricedown(const auto_cena& car1, const auto_cena& car2) {
    return car2.cena < car1.cena;
}
void sortAndDisplaycarsup(vector<auto_cena>& cars) {
    sort(cars.begin(), cars.end(), compareByPriceup);
    cout << "Samochody cena rosnaco:" << endl;
    for (const auto_cena& car : cars) {
        cout << car.marka << " " << car.cena << endl;
    }
}

void sortAndDisplaycarsuppower(vector<auto_cena>& cars) {
    sort(cars.begin(), cars.end(), compareByPower);
    cout << "Samochody moc rosnaco:" << endl;
    for (const auto_cena& car : cars) {
        cout << car.marka << " " << car.moc << endl;
    }
}

void sortAndDisplaycarsdown(vector<auto_cena>& cars) {
    sort(cars.begin(), cars.end(), compareByPricedown);
    cout << "Samochody cena malejaco:" << endl;
    for (const auto_cena& car : cars) {
        cout << car.marka << " " << car.cena << endl;
    }
}

void displaycarsBelowPrice(vector<auto_cena>& cars, int cena) {
    cout << "Samochody ponizej ceny " << cena << ":" << endl;
    for (const auto_cena& car : cars) {
        if (car.cena < cena) {
            cout << car.marka << " " << car.cena << endl;
        }
    }
}

void displaycarsBelowPower(vector<auto_cena>& cars, int moc) {
    cout << "Samochody ponizej mocy " << moc << ":" << endl;
    for (const auto_cena& car : cars) {
        if (car.moc < moc) {
            cout << car.marka << " " << car.moc << endl;
        }
    }
}

void sortowanieup() {
    system("cls");
    string fileName = "cennik_samochodow.txt";
    vector<auto_cena> cars = readcarsFromFile(fileName);
    sortAndDisplaycarsup(cars);
    _getch();
}

void sortowaniedown() {
    system("cls");
    string fileName = "cennik_samochodow.txt";
    vector<auto_cena> cars = readcarsFromFile(fileName);
    sortAndDisplaycarsdown(cars);
    _getch();
}

void ponizejcena() {
    system("cls");
    string fileName = "cennik_samochodow.txt";
    vector<auto_cena> cars = readcarsFromFile(fileName);
    sortAndDisplaycarsup(cars);
    int cena;
    cout << "Podaj cene ";
    cin >> cena;
    displaycarsBelowPrice(cars, cena);
    _getch();
}

void ponizejmoc() {
    system("cls");
    string fileName = "moc_samochodow.txt";
    vector<auto_cena> cars = readcarsFromFilepower(fileName);
    sortAndDisplaycarsuppower(cars);
    int moc;
    cout << "Podaj moc ";
    cin >> moc;
    displaycarsBelowPower(cars, moc);
    _getch();
}