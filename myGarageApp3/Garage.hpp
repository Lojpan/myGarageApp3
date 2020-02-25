#ifndef Garage_h
#define Garage_h


#endif /* Garage_h */

#include <iostream>
#include <string>
#include <vector>


class Vehicle {
protected:
    std::string vehicleType, vehicleModel, vehicleRegNr, vehicleManufacturer, vehicleColour;
    int vehicleSeats;
public:
    std::string in_vehicleType, in_vehicleManufacturer, in_vehicleModel, in_vehicleRegNr, in_vehicleColour;
    int in_vehicleSeats, in_bikeFrame, in_bikeWheels;
    
    Vehicle(){}
    
    Vehicle(std::string t, std::string m, std::string r, std::string c, std::string manu, int s) :
    vehicleType(t), vehicleModel(m), vehicleRegNr(r), vehicleColour(c), vehicleManufacturer(manu), vehicleSeats(s) {}
    
    virtual ~Vehicle() {};
    
    std::string get_vehicleType() { return vehicleType;}
    std::string get_vehicleRegNr() { return vehicleRegNr;}
    
//    virtual void set_vehicle() = 0;
    virtual void output() = 0;
};

class Bicycle : public Vehicle {
protected:
    std::string frame;
    int wheels;
public:
    
    Bicycle(){}
    
    Bicycle(std::string t, std::string m, std::string r, std::string c, std::string manu, int s, std::string in_bikeFrame, int in_bikeWheels) : Vehicle(t, m, r, c, manu, s)
    {vehicleType = "Bicycle"; frame = in_bikeFrame; wheels = in_bikeWheels;}
    
    ~Bicycle() {};
    
//    void set_vehicle()
//    {
//
//    }
    
    void output();
};
class MotorCycle : public Vehicle {
protected:
    int gears;
    int lightHeavy;
public:
    //    MotorCycle(){} // default constructor
    MotorCycle(std::string t, std::string m, std::string r, std::string c, std::string manu, int s, int in_gears, int in_motorClass) : Vehicle(t, m, r, c, manu, s)
    {vehicleType = "Motorcycle"; gears = in_gears; lightHeavy = in_motorClass;}
    ~MotorCycle() {}
    
//    void set_vehicle()
//    {
//
//    }
    void output();
};
class Car : public Vehicle {
protected:
    int doors;
    std::string electric;
public:
    //    Car(){}
    Car(std::string t, std::string m, std::string r, std::string c, std::string manu, int s, int in_carDoors, std::string in_electric) : Vehicle(t, m, r, c, manu, s)
    {vehicleType = "Car"; doors = in_carDoors; electric = in_electric;}
    ~Car() {}
    
//    void set_vehicle()
//    {
//
//    }
    void output();
};
class Bus : public Vehicle {
protected:
    float hight;
    float length;
public:
    //    Bus(){}
    Bus(std::string t, std::string m, std::string r, std::string c, std::string manu, int s, float in_height, float in_length) : Vehicle(t, m, r, c, manu, s)
    {vehicleType = "Bus"; length = in_length; hight = in_height;}
    ~Bus() {}
    
//    void set_vehicle()
//    {
//
//    }
    void output();
};
class Truck : public Vehicle {
protected:
    int truckbed;
    float weight;
public:
    //    Truck(){}
    Truck(std::string t, std::string m, std::string r, std::string c, std::string manu, int s, int in_truckBed, float in_weight) : Vehicle(t, m, r, c, manu, s)
    {vehicleType = "Truck"; truckbed = in_truckBed; weight = in_weight;}
    ~Truck() {}
    
//    void set_vehicle()
//    {
//
//    }
    
    void output();
};

class Garage {
protected:
    std::vector<Vehicle*>garage;
public:
    std::string findType;
    Vehicle* foundVehicle;
    int garageSize, newGarage, bicycle, motorcycle, car, bus, truck, vehicleCount, parkingLot;
    
    //    Garage(){}
    virtual ~Garage() {};
    
    int get_parkingLot() {return parkingLot;}
    int get_garageSize();
    int get_Vacancy() {return newGarage - get_garageSize();}
    
    int createGarage(int nLots);
    
    void addVehicle(Vehicle* v) { garage.push_back(v); }
    void check_out(std::string str);
    int searchRegNr(std::string search);
    void listVehicles(int choice);
    
    int set_Counter(std::string input);
    void display_Counter();
    void display_CurrentData();
    
    void demoVehicles();
    
    void full_Garage();
    
    void start_Menu();
    void main_Menu();
    void park_Menu();
    void list_vehicle_Menu();
    void garage_data_Menu();
};
