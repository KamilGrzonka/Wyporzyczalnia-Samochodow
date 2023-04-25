#pragma once
#include "main_header.h"
#include "lista.h"

/*class Vehicle {
public:
    int price;
    int power;

    Vehicle(int price, int power) : price(price), power(power) {}
};

class VehicleByPrice : public Vehicle {
public:
    VehicleByPrice(int price, int power) : Vehicle(price, power) {}

    bool operator<(const VehicleByPrice& other) const {
        return price < other.price;
    }
};

class VehicleByPower : public Vehicle {
public:
    VehicleByPower(int price, int power) : Vehicle(price, power) {}

    bool operator<(const VehicleByPower& other) const {
        return power < other.power;
    }
};

typedef List<VehicleByPrice> VehicleListByPrice;
typedef List<VehicleByPower> VehicleListByPower;

VehicleListByPrice readAutaCena(const string& fileName) {
    VehicleListByPrice vehicles;
    ifstream file(fileName);
    int price, power;
    while (file >> price >> power) {
        vehicles.PushBack(VehicleByPrice(price, power));
    }                                                                                                           nie patrzec smieci
    return vehicles;
}

VehicleListByPower readAutaMoc(const string& fileName) {
    VehicleListByPower vehicles;
    ifstream file(fileName);
    int price, power;
    while (file >> price >> power) {
        vehicles.PushBack(VehicleByPower(price, power));
    }
    return vehicles;
}

void displayVehiclesWithPriceLessThan(const VehicleListByPrice& vehicles, int price) {
    cout << "Auta, ktore kosztuja mniej niz " << price << ":" << endl;
    for (const auto& vehicle : vehicles) {
        if (vehicle.price < price) {
            cout << vehicle.price << " " << vehicle.power << endl;
        }
    }
}

void displayVehiclesWithPowerLessThan(const VehicleListByPower& vehicles, int power) {
    cout << "Auta, ktora maja moc mniejsza niz " << power << ":" << endl;
    for (const auto& vehicle : vehicles) {
        if (vehicle.power < power) {
            cout << vehicle.price << " " << vehicle.power << endl;
        }
    }
}*/


class VechiclePrice : public List <int>, public glowne_funkcje {
public:
    void LoadPricesFromFile(const string& file_name);
};

class VechiclePower : public List <int>, public glowne_funkcje {
public:
    void LoadPowerFromFile(const string& file_name);
};

class auto_cena {
public:
    string marka;
    int cena;
    int moc;
};

vector<auto_cena> readcarsFromFile(const string& fileName);
vector<auto_cena> readcarsFromFilepower(const string& fileName);
bool compareByPower(const auto_cena& car1, const auto_cena& car2);
bool compareByPriceup(const auto_cena& car1, const auto_cena& car2);
bool compareByPricedown(const auto_cena& car1, const auto_cena& car2);
void sortAndDisplaycarsup(vector<auto_cena>& cars);
void sortAndDisplaycarsuppower(vector<auto_cena>& cars);
void sortAndDisplaycarsdown(vector<auto_cena>& cars);
void displaycarsBelowPrice(vector<auto_cena>& cars, int cena);
void displaycarsBelowPower(vector<auto_cena>& cars, int moc);
void sortowanieup();
void sortowaniedown();
void ponizejcena();
void ponizejmoc();

