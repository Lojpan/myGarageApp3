#include "Garage.hpp"

void Bicycle::output() {
    std::cout << "\n Vehicle: \t" << vehicleType << "\n Model: \t" << vehicleModel << "\n Reg.nr: \t" << vehicleRegNr << "\n Colour: \t" << vehicleColour
    << "\n Manufacturer: \t" << vehicleManufacturer << "\n Seats:  \t" << vehicleSeats << "\n Frame:  \t" << frame << "\n Wheels: \t" << wheels << std::endl;
}

void MotorCycle::output() {
    std::cout << "\n Vehicle:: \t" << vehicleType << "\n Model: \t" << vehicleModel << "\n Reg.nr: \t" << vehicleRegNr << "\n Colour: \t" << vehicleColour
    << "\n Manufacturer: \t" << vehicleColour << "\n Seats:  \t" << vehicleSeats << "\n Weght class: \t" << lightHeavy << "\n Gears: \t" << gears << std::endl;
}

void Car:: output() {
    std::cout << "\n Vehicle:: \t" << vehicleType << "\n Model: \t" << vehicleModel << "\n Reg.nr: \t" << vehicleRegNr << "\n Colour: \t" << vehicleColour
    << "\n Manufacturer: \t" << vehicleColour << "\n Seats:  \t" << vehicleSeats << "\n Nr of doors: \t" << doors
    << "\n Fuel: \t " << electric << std::endl;
}

void Bus::output() {
    std::cout << "\n Vehicle:: \t" << vehicleType << "\n Model: \t" << vehicleModel << "\n Reg.nr: \t" << vehicleRegNr << "\n Colour: \t" << vehicleColour
    << "\n Manufacturer: \t" << vehicleColour << "\n Seats:  \t" << vehicleSeats << "\n Hight: \t" << hight << " meters" << "\n length: \t" << length << std::endl;
}

void Truck:: output() {
    std::cout << "\n Vehicle:: \t" << vehicleType << "\n Model: \t" << vehicleModel << "\n Reg.nr: \t" << vehicleRegNr << "\n Colour: \t" << vehicleColour
    << "\n Manufacturer: \t" << vehicleColour << "\n Seats:  \t" << vehicleSeats << "\n Number of truckbeds: \t" << truckbed << " meters" << "\n Weight: \t" << weight << std::endl;
}

void Garage::demoVehicles() {
    
    Vehicle* bicycle = new Bicycle("", "Cresent", "Mountain bike", "ABC123", "Male", 1, "Red", 2);
    addVehicle(bicycle);
    
    Vehicle* motorcycle = new MotorCycle("", "Kawasaki", "Crouser", "ABC234", "Black", 1, 6, 1);
    addVehicle(motorcycle);
    
    Vehicle* car = new Car("", "Volvo", "V70", "ABC345", "Blue", 5, 4, "Electric Powered");
    addVehicle(car);
    
    Vehicle* bus = new Bus("", "Scania", "x90", "ABC456", "Metallic Grey", 3, 23.5, 3.4);
    addVehicle(bus);
    
    Vehicle* truck = new Truck("", "Ford", "X", "ABC567", "White", 3, 2, 10);
    addVehicle(truck);
    
    newGarage = 5;
}

void Garage::display_CurrentData() {
    std::cout << "\nMaximun Capacity: " << newGarage << "\t Current Number of Vehicles: " << get_garageSize();
}

void Garage::display_Counter() {
    std::cout << "\nNumber of " << findType << " Is Currently: " << vehicleCount << std::endl;
}

int Garage::createGarage(int nLots) {
    garage.reserve(nLots);
    return nLots;
}

int Garage::set_Counter(std::string input) {
    int count = 0;
    if (input == "Bicycle")
        count = bicycle;
    if (input == "Motorcycle")
        count = car;
    if (input == "Car")
        count = motorcycle;
    if (input == "Bus")
        count = bus;
    if (input == "Truck")
        count = truck;
    
    return count;
}

void Garage::listVehicles(int choice) {
    //        bicycle = 0; motorcycle = 0; car = 0; bus = 0; truck = 0;
    if (choice == 1)
        findType = "Bicycle";
        bicycle++;
    if (choice == 2)
        findType = "Motorcycle";
        car++;
    if (choice == 3)
        findType = "Car";
        motorcycle++;
    if (choice == 4)
        findType = "Bus";
        bus++;
    if (choice == 5)
        findType = "Truck";
        truck++;
    
    if (choice != 6) {
        for (int i = 0; i < garage.size(); i++) {
            if (garage[i]->get_vehicleType() == findType) {
                garage[i]->output();
                parkingLot = i + 1;
            }
            {
                //                    if (findType == "Bicycle")
                //                        bicycle++;
                //                    if (findType == "Motorcycle")
                //                        car++;
                //                    if (findType == "Car")
                //                        motorcycle++;
                //                    if (findType == "Bus")
                //                        bus++;
                //                    if (findType == "Truck")
                //                        truck++;
            }
        }
        vehicleCount = set_Counter(findType);
        std::cout
        << "\n--------------------------------"
        << "\nYour Vehicle Is Parked At\n Parkinglot Number: ";
        std::cout << parkingLot
        << "\n--------------------------------"
        << std::endl;
    }
    else {
        for (int i = 0; i < garage.size(); i++) {
            garage[i]->output();
            parkingLot = i + 1;
        }
    }
}

void Garage::check_out(std::string str)
{
    int x = -1;
    x = searchRegNr(str);
    if (x != -1)
    {
        delete garage[x];
        garage.erase(remove(garage.begin(), garage.end(), garage[x]), garage.end());

        vehicleCount--;
        std::cout << "\n\t\t\t\t\t You're checked out successfully! \n";
    }
}

int Garage:: searchRegNr(std::string search) {
    findType = search;
    for (int i = 0; i < garage.size(); i++) {
        if (garage[i]->get_vehicleRegNr() == findType) {
            garage[i]->output();
            return i;
        }
    }
    return 0;
}

int Garage::get_garageSize() {
    for (int i = 0; i != garage.size(); i++) {
        garageSize = i + 1;
    }
    return garageSize;
    }


void Garage::start_Menu(){
    std::cout << "\n \t \t<< Welcome >>"
    << "\n \tLet's Get Started!"
    << "\n--------------------------"
    << "\n \tOptions"
    << "\n--------------------------"
    << "\nPlease Enter Your Choice\n"
    << "\n1. Create Garage"
    << "\n2. Remove Garage"
    << "\n3. Skip To Main Menu"
    << "\n4. Exit"
    << std::endl;
    }

void Garage::main_Menu(){
    std::cout
    << "\n \tMAIN MENU"
    << "\n--------------------------"
    << "\n \tOptions"
    << "\n--------------------------"
    << "\nPlease enter your choice\n"
    << "\n1. Park Vehicle"
    << "\n2. Remove Vehicle"
    << "\n3. Search Vehicle"
    << "\n4. Retrieve Vehicle Registration"
    << "\n5. Garage Data"
    << "\n6. Back To Start"
    << "\n7. Exit"
    << std::endl;
    }

void Garage::park_Menu(){
    std::cout
    << "\n \t \tPARK VEHICLE MENU"
    << "\n--------------------------"
    << "\n \tOptions"
    << "\n--------------------------"
    << "\nPlease enter your choice\n"
    << "\n1. Park Bicycle"
    << "\n2. Park Motorcycle"
    << "\n3. Park Car"
    << "\n4. Park Bus"
    << "\n5. Park Truck"
    << "\n6. Back To Main Menu"
    << "\n7. Exit"
    << std::endl;
}

void Garage::list_vehicle_Menu(){
    std::cout
    << "\n \t LIST VEHICLES MENU"
    << "\n--------------------------"
    << "\n \tOptions"
    << "\n--------------------------"
    << "\nPlease Enter Your Choice\n"
    << "\n1. List Bicycles"
    << "\n2. List Motorcycles"
    << "\n3. List Cars"
    << "\n4. List Buses"
    << "\n5. List Trucks"
    << "\n6. List All Vehicles"
    << "\n7. Back To Main Menu"
    << "\n8. Exit"
    << std::endl;
    }


void Garage::garage_data_Menu(){
    std::cout
    << "\n\t GARAGE DATA MENU"
    << "\n--------------------------"
    << "\n \tOptions"
    << "\n--------------------------"
    << "\nPlease Enter Your Choice\n"
    << "\n1. Retrieve Garage Size"
    << "\n2. Retrieve Number of Vacant parking lots"
    << "\n3. Retrieve Number of Occupied parking lots"
    << "\n4. Back To Main Menu"
    << "\n5. Exit"
    << std::endl;
    }
