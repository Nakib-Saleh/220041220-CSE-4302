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
        return (fuelCapacity / distance);
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
        return (batteryCapacity / distance);
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



class Employee{
protected:
    string name;
    int id;

public:
    Employee(string Name, int Id) : name(Name), id(Id) {}
    virtual void introduce()=0;
    virtual ~Employee(){}
};



class Manager : public Employee{
public:
    Manager(string Name, int Id) : Employee(Name, Id) {}

    void introduce(){
        cout << "Mr. " << name << endl;
    }
};


class Driver : public Employee{
public:
    Driver(string Name, int Id) : Employee(Name, Id) {}

    void introduce(){
        cout << name << endl;
    }
};

class Branch{
    vector<Vehicle*> vehi;
    vector<Employee* > employ;

public:
    void addVehicle( Vehicle* v){
        vehi.push_back(v);
    }
    void addEmployee( Employee* v){
        employ.push_back(v);
    }

    void maintenance_all_vehicle(){
        for(auto &i: vehi){
            i->performMaintenance();
        }
    }

    void IntroEmployee(){
        for(auto &i: employ){
            i->introduce();
        }
    }

    ~Branch(){
        for(auto &i: vehi){
            delete i;
        }
        for(auto &i: employ){
            delete i;
        }
    }


};




int main() {
    Branch branch;

    
    branch.addVehicle(new Car("ABCD", "Toyota", 4.5, 50, "Gasoline", 5));
    branch.addVehicle(new Motorcycle("EFGH", "Honda", 2.0, 15, "Gasoline"));
    branch.addVehicle(new Truck("IJKL", "Volvo", 12.0, 150, "Diesel", 20));
    branch.addVehicle(new Hybrid("MNOP", "Toyota", 12.0, 150, "Diesel", 20));

    
    branch.addEmployee(new Manager("Mahin", 2002));
    branch.addEmployee(new Driver("Nakib", 1990));

    
    branch.IntroEmployee();

    
    branch.maintenance_all_vehicle();

    return 0;
}
