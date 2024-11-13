#include <bits/stdc++.h>
using namespace std;


class Vehicle {
protected:
    string licensePlate;
    string manufacturer;
    double carriageSize;

public:
    Vehicle(string license, string manu, double carrS)
        : licensePlate(license), manufacturer(manu), carriageSize(carrS) {}


    virtual void performMaintenance() = 0;

    virtual void displayInfo() {
        cout << "License Plate: " << licensePlate
             << "\nManufacturer: " << manufacturer
             << "\nCarriage Size: " << carriageSize << endl;
    }
    double getCarriageSize() {
        return carriageSize;
    }

    virtual ~ Vehicle() {}
};

class Gasoline : virtual public Vehicle {
protected:
    double fuelCapacity;
    string fuelType;

public:
    Gasoline(string license, string manu, double carrS, string fuel, double fuelCap)
        : Vehicle(license, manu, carrS), fuelCapacity(fuelCap), fuelType(fuel) {}

    virtual double calculateFuelConsumption(double distance) {
        return fuelCapacity / distance;
    }
    void performMaintenance() override {
        cout << "Gasoline - Maintenance" << endl;
    }
    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "Fuel Type: " << fuelType 
             << "\nFuel Capacity: " << fuelCapacity << endl;
    }
};

class Electric : virtual public Vehicle {
protected:
    double batteryCapacity;
    double chargingTime;

public:
    Electric(string license, string manu, double carrS, double batteryCap, double chargeTime)
        : Vehicle(license, manu, carrS), batteryCapacity(batteryCap), chargingTime(chargeTime) {}

    void performMaintenance() override {
        cout << "Electric - Maintenance" << endl;
    }
    double calculateFuelConsumption(double distance) {
        return batteryCapacity / distance;
    }
    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "Battery Capacity: " << batteryCapacity
             << "\nCharging Time: " << chargingTime << endl;
    }
};

class Motorcycle : public Gasoline {
public:
    Motorcycle(string license, string manu, double carrS, double fuelCap, string fuel)
        : Vehicle(license, manu, carrS), Gasoline(license, manu, carrS, fuel, fuelCap) {}

    void performMaintenance() override {
        cout << "Motorcycle - Maintenance" << endl;
    }
    double calculateFuelConsumption(double distance) override{
        return (fuelCapacity / distance)*100;
    }
};

class Car : public Gasoline {
protected:
    int passCapacity;

public:
    Car(string license, string manu, double carrS, double fuelCap, string fuel, int passC)
        : Vehicle(license, manu, carrS), Gasoline(license, manu, carrS, fuel, fuelCap), passCapacity(passC) {}

    void performMaintenance() override {
        cout << "Car - Maintenance" << endl;
    }
    void displayInfo() override {
        Gasoline::displayInfo();
        cout << "Passenger Capacity: " << passCapacity << endl;
    }
    double calculateFuelConsumption(double distance)override {
        return (fuelCapacity / distance)*100;
    }
};

class Truck : public Gasoline {
protected:
    double cargoCapacity;

public:
    Truck(string license, string manu, double carrS, double fuelCap, string fuel, double cargoC)
        : Vehicle(license, manu, carrS), Gasoline(license, manu, carrS, fuel, fuelCap), cargoCapacity(cargoC) {}

    void performMaintenance() override {
        cout << "Truck - Maintenance" << endl;
    }
    void displayInfo() override {
        Gasoline::displayInfo();
        cout << "Cargo Capacity: " << cargoCapacity << endl;
    }
    double calculateFuelConsumption(double distance)override {
        return (fuelCapacity / distance)*100;
    }
};

class Hybrid :  public Gasoline,  public Electric {
protected:
    double energyRegenerationEfficiency;

public:
    Hybrid(string license, string manu, double carrS, double fuelCap, string fuel,
           double batteryCap, double chargeTime, double regenEfficiency)
        : Vehicle(license, manu, carrS), Gasoline(license, manu, carrS, fuel, fuelCap),
          Electric(license, manu, carrS, batteryCap, chargeTime), energyRegenerationEfficiency(regenEfficiency) {}

    void performMaintenance() override {
        cout << "Hybrid - Maintenance" << endl;
    }
    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "Fuel Type: " << fuelType
             << "\nFuel Capacity: " << fuelCapacity 
             << "\nBattery Capacity: " << batteryCapacity 
             << "\nCharging Time: " << chargingTime 
             << "\nEnergy Regeneration Efficiency: " << energyRegenerationEfficiency << endl;
    }
};


void sort_vehicles_by_capacity(Vehicle** ve, int n) {
    sort(ve, ve + n, [](Vehicle* a, Vehicle* b) {
        return a->getCarriageSize() > b->getCarriageSize();
    });
}


int main() {
    vector<Vehicle*> ve;

    ve.push_back(new Car("ABC-123", "Toyota", 10, 20, "Petrol", 5));
    ve.push_back(new Truck("DEF-456", "Ford", 30, 40, "Diesel", 500));
    ve.push_back(new Motorcycle("GHI-789", "Honda", 2, 15, "Petrol"));
    ve.push_back(new Hybrid("JKL-123", "Tesla", 20, 30, "Petrol", 100, 2, 0.5));


    sort_vehicles_by_capacity(ve.data(), ve.size());
    for (auto v : ve) {
        v->displayInfo();
        cout << endl;
    }

    vector <Hybrid*> h;
    h.push_back(new Hybrid("JKL012", "Tesla", 20, 40, "Petrol", 100, 2, 0.5));
    h.push_back(new Hybrid("JKL094", "Toyota", 30, 90, "Electric", 100, 2, 0.5));

    for (auto v : h) {
        v->displayInfo();
        cout << endl;
    }

    for (auto v : ve) delete v;
    for (auto v : h) delete v;

    return 0;
}
