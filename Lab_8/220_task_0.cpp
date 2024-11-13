#include <bits/stdc++.h>
using namespace std;

class Vehicle
{
protected:
    string licensePlate;
    string manuacturer;
    int carriageSize;

public:
    Vehicle(string license, string manu, int carrS)
        : licensePlate(license), manuacturer(manu), carriageSize(carrS) {}
};







class Gasoline : public Vehicle
{
protected:
    int fuelCapacity;
    string fuelType;

public:
    Gasoline(string license, string manu, int carrS, string fuel, int fuelCap)
        : Vehicle(license, manu, carrS), fuelCapacity(fuelCap), fuelType(fuel) {}
};





class Electric : public Vehicle
{
protected:
    int batteryCapacity;
    int chargingTime;

public:
    Electric(string license, string manu, int carrS, int batteryCap, int chargeTime)
        : Vehicle(license, manu, carrS), batteryCapacity(batteryCap), chargingTime(chargeTime) {}

    virtual void maintanance(){
        cout<<"Electric - maintanance"<<endl;
    }
};




class Motorcycle : public Gasoline
{
public:
    Motorcycle(string license, string manu, int carrS, int fuelCap, string fuel)
        : Gasoline(license, manu, carrS, fuel, fuelCap) {}

    void maintanance(){
        cout<<"Motorcycle - maintanance"<<endl;
    }
};




class Car : public Gasoline
{
protected:
    int passCapacity;

public:
    Car(string license, string manu, int carrS, int fuelCap, string fuel, int passC)
        : Gasoline(license, manu, carrS, fuel, fuelCap), passCapacity(passC) {}
    
    void maintanance(){
        cout<<"Car - maintanance"<<endl;
    }
};




class Truck : public Gasoline
{
protected:
    int cargoCapacity;

public:
    Truck(string license, string manu, int carrS, int fuelCap, string fuel, int cargoC)
        : Gasoline(license, manu, carrS, fuel, fuelCap), cargoCapacity(cargoC) {}

    void maintanance(){
        cout<<"Truck - maintanance"<<endl;
    }
};




class Hybrid :  virtual public Gasoline, virtual public Electric
{
protected:
    float energy_Regeneration_Efficiency;

public:
    Hybrid(string license, string manu, int carrS, int fuelCap, string fuel,
           int batteryCap, int chargeTime, float regenEfficiency)
        : Gasoline(license, manu, carrS, fuel, fuelCap),
          Electric(license, manu, carrS, batteryCap, chargeTime), energy_Regeneration_Efficiency(regenEfficiency) {}

     void maintanance(){
        cout<<"Hybrid - maintanance"<<endl;
    }
};




class Employee
{
protected:
    string name;
    int id;

public:
    Employee(string Name, int Id) : name(Name), id(Id) {}
};



class Manager : public Employee
{
public:
    Manager(string Name, int Id) : Employee(Name, Id) {}

    void introduce()
    {
        cout << "Mr. " << name << endl;
    }
};





class Driver : public Employee
{
public:
    Driver(string Name, int Id) : Employee(Name, Id) {}

    void introduce()
    {
        cout << name << endl;
    }
};





class Branch
{

    vector<Motorcycle> motorcycles;
    vector<Car> cars;
    vector<Truck> trucks;
    vector<Electric> electric;
    vector<Hybrid> hybrid;
    vector<Manager> managers;
    vector<Driver> drivers;

public:
    void IntroEmployee(){
        for(auto i: managers){
            i.introduce();
        }

        for(auto j: drivers){
            j.introduce();
        }
    }

    void VehicleMaintanance(){
        for(auto i: motorcycles){
            i.maintanance();
        }
        for(auto i: cars){
            i.maintanance();
        }
        for(auto i: trucks){
            i.maintanance();
        }
        for(auto i: electric){
            i.maintanance();
        }
        for(auto i: hybrid){
            i.maintanance();
        }
    }
};




int main()
{

}