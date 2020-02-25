#include "Garage.hpp"


int main(int argc, const char* argv[]) {
    // Global variables
    std::string temp_vehicleType, temp_vehicleManufacturer, temp_vehicleModel, temp_vehicleRegNr, temp_vehicleColour, temp_bikeFrame;
    int temp_vehicleSeats, temp_bikeWheels; int sizeOfGarage = 0, choice;
    
    //creating a garage object for access to garage functions
    Garage g;
    
    // Demo vehiclea
    g.demoVehicles();
    
    bool b;
    bool c;
    
    do {
        b = true;
        c = true;
        g.display_CurrentData();
        g.start_Menu();
        
        std::cin >> choice;
        
        switch (choice) {
            case 1: {
                std::cout
                << "\nTo Create A New Garage, Please Enter Number of Parkinglots To Create. "
                << std::endl;
                std::cin >> sizeOfGarage;
                
                g.newGarage = g.createGarage(sizeOfGarage);
                std::cout << "A Garage With The Capacity of " << g.newGarage << " Vehicles Created." << std::endl;
                break;
            }
            case 2: {
                break;
            }
            case 3: {
                break;
            }
            case 4: {
                c = false;
                break;
            }
            default: {
                std::cout << "\nInvalid input! \n  " << std::endl;
                break;
            }
        }
        if (choice != 4) {
            do {
                g.display_CurrentData();
                
                g.main_Menu();
                
                std::cin >> choice;
                
                switch (choice) {

                    case 1: {
                           do {
                            g.display_CurrentData();
                            g.park_Menu();
                    
                            std::cin >> choice;
                            // If Garage is full - warning/message - return to main menu
                            if (g.get_garageSize() == g.newGarage) {
                                std::cout
                                << "\n \t \t \t << GARAGE IS FULL >>"
                                << "\n \t Go To >> Create Garage << To Resize Garage"
                                << "\n \t \t Returning To Start Menu"
                                << std::endl;
                                choice = 6;
                                b = false;
                            }
                            switch (choice) {
                                case 1: {
                                    //Park/Register Bicycle
                                    int in_bikeWheels;
                                    std::string in_bikeFrame;
                                    
                                    std::cout << "\tPlease enter brand >> \t";
                                    std::cin >> temp_vehicleManufacturer;
                                    std::cout << "\tPlease enter model >> \t";
                                    std::cin >> temp_vehicleModel;
                                    std::cout << "\tPlease enter registration/license number >> \t";
                                    std::cin >> temp_vehicleRegNr;
                                    std::cout << "\tPlease enter colour >> \t";
                                    std::cin >> temp_vehicleColour;
                                    std::cout << "\tPlease enter number of seats >> \t";
                                    std::cin >> temp_vehicleSeats;
                                    std::cout << "\tFrame? (female/male)  >> \t";
                                    std::cin >> in_bikeFrame;
                                    std::cout << "\tPlease enter number of wheels >> \t";
                                    std::cin >> in_bikeWheels;
                                    
                                    Vehicle*bike = new Bicycle("", temp_vehicleManufacturer, temp_vehicleModel, temp_vehicleRegNr, temp_vehicleColour, temp_vehicleSeats, in_bikeFrame, in_bikeWheels);
                                    g.addVehicle(bike);
                                    break;
                                }
                                case 2: {
                                    //Park/Register Motorcycle
                                    int in_motorClass;
                                    int in_gears;
                                    
                                    std::cout << "\tPlease enter brand >> \t";
                                    std::cin >> temp_vehicleManufacturer;
                                    std::cout << "\tPlease enter model >> \t";
                                    std::cin >> temp_vehicleModel;
                                    std::cout << "\tPlease enter registration/license number >> \t";
                                    std::cin >> temp_vehicleRegNr;
                                    std::cout << "\tPlease enter colour >> \t";
                                    std::cin >> temp_vehicleColour;
                                    std::cout << "\tPlease enter number of seats >> \t";
                                    std::cin >> temp_vehicleSeats;
                                    std::cout << "\tPlease enter class (light/heavy) >> /t";
                                    std::cin >> in_motorClass;
                                    std::cout << "\tPlease enter nr of gears >> \t";
                                    std::cin >> in_gears;
                                    
                                    Vehicle* motorcycle = new MotorCycle("", temp_vehicleManufacturer, temp_vehicleModel, temp_vehicleRegNr, temp_vehicleColour, temp_vehicleSeats, in_gears, in_motorClass);
                                    g.addVehicle(motorcycle);
                                    break;
                                }
                                case 3: {
                                    //Park/Register Car
                                    int in_carDoors;
                                    std::string in_electric;
                                    
                                    std::cout << "\tPlease enter brand >> \t";
                                    std::cin >> temp_vehicleManufacturer;
                                    std::cout << "\tPlease enter model >> \t";
                                    std::cin >> temp_vehicleModel;
                                    std::cout << "\tPlease enter registration/license number >> \t";
                                    std::cin >> temp_vehicleRegNr;
                                    std::cout << "\tPlease enter colour >> \t";
                                    std::cin >> temp_vehicleColour;
                                    std::cout << "\tPlease enter number of seats >> \t";
                                    std::cin >> temp_vehicleSeats;
                                    std::cout << "\tPlease enter number of doors >> \t";
                                    std::cin >> in_carDoors;
                                    std::cout << "\tPlease enter type of engine >> \t";
                                    std::cin >> in_electric;
                                    
                                    Vehicle* car = new Car("", temp_vehicleManufacturer, temp_vehicleModel, temp_vehicleRegNr, temp_vehicleColour, temp_vehicleSeats, in_carDoors, in_electric);
                                    g.addVehicle(car);
                                    break;
                                }
                                case 4: {
                                    //Park/Register Bus
                                    float in_length;
                                    float in_height;
                                    
                                    std::cout << "\tPlease enter brand >> \t";
                                    std::cin >> temp_vehicleManufacturer;
                                    std::cout << "\tPlease enter model >> \t";
                                    std::cin >> temp_vehicleModel;
                                    std::cout << "\tPlease enter registration/license number >> \t";
                                    std::cin >> temp_vehicleRegNr;
                                    std::cout << "\tPlease enter colour >> \t";
                                    std::cin >> temp_vehicleColour;
                                    std::cout << "\tPlease enter number of seats >> \t";
                                    std::cin >> temp_vehicleSeats;
                                    std::cout << "\tPlease enter length in meters accordingly '\"'X.X'\"' >> \t";
                                    std::cin >> in_length;
                                    std::cout << "\tPlease enter height in meters accordingly '\"'Y.Y'\"' >> \t";
                                    std::cin >> in_height;
                                    
                                    Vehicle* bus = new Bus("", temp_vehicleManufacturer, temp_vehicleModel, temp_vehicleRegNr, temp_vehicleColour, temp_vehicleSeats, in_length, in_height);
                                    g.addVehicle(bus);
                                    break;
                                }
                                case 5: {
                                    //Park/Register Trucks
                                    int in_truckBed;
                                    float in_weight;
                                    
                                    std::cout << "\tPlease enter brand >> \t";
                                    std::cin >> temp_vehicleManufacturer;
                                    std::cout << "\tPlease enter model >> \t";
                                    std::cin >> temp_vehicleModel;
                                    std::cout << "\tPlease enter registration/license number >> \t";
                                    std::cin >> temp_vehicleRegNr;
                                    std::cout << "\tPlease enter colour >> \t";
                                    std::cin >> temp_vehicleColour;
                                    std::cout << "\tPlease enter number of seats >> \t";
                                    std::cin >> temp_vehicleSeats;
                                    std::cout << "\tPlease enter number of truck beds >> \t";
                                    std::cin >> in_truckBed;
                                    std::cout << "\tPlease enter weight >> \t";
                                    std::cin >> in_weight;
                                    Vehicle* truck = new Truck("", temp_vehicleManufacturer, temp_vehicleModel, temp_vehicleRegNr, temp_vehicleColour, temp_vehicleSeats, in_truckBed, in_weight);
                                    g.addVehicle(truck);
                                    break;
                                }
                                case 6: {
                                    choice = 0;
                                    break;
                                }
                                case 7: {
                                    choice = 0;
                                    b = false;
                                    c = false;
                                    break;
                                }
                                default: {
                                    std::cout << "\nInvalid input! \n" << std::endl;
                                    if (choice == 0)
                                        choice++;
                                    break;
                                }
                            }
                        } while (choice != 0);
                             break;
                         }
                    case 2: {
                        std::cout << "\n\t\t   Enter yours vehicle registration number:  "; std::cin >> temp_vehicleRegNr;
                        g.check_out(temp_vehicleRegNr);
                        break;
                    }
                    case 3: {
                        // Error message if no vehicle are retrieved
                        std::string searchInput;
                        
                        std::cout
                        << "\n--------------------------"
                        << "\n \tSEARCH VEHICLE"
                        << "\n--------------------------"
                        << "\nPlease Enter Your Vehicles Registration Plate Number Accordingly  > abc123 < "
                        << std::endl;
                        
                        std::cin >> searchInput;
                        
                        if (g.garageSize != 0) {
                            std::cout
                            << "--------------------------------------"
                            << "\nVehicle Found: ";
                            g.searchRegNr(searchInput);
                            std::cout
                            << "\n--------------------------------------"
                            << "\nYour Vehicle Is Parked At\n Parkinglot Number: "
                            << g.get_parkingLot();
                            std::cout
                            << "\n--------------------------------------"
                            << std::endl;
                        }else{
                            std::cout << "No vehicle found";
                        }
                        break;
                    }
                    case 4: {
                        do {
                            //   b = true;
                            g.display_CurrentData();
                            g.list_vehicle_Menu();
                            
                            std::cin >> choice;
                            
                            if (choice < 1 || choice > 8) {
                                std::cout << "\nInvalid input! \n" << std::endl;
                                break;
                            }
                            if (choice != 7) {
                                g.listVehicles(choice);
                                //                        g.display_Counter();
                            }
                            if (choice == 8) {
                                b = false;
                                c = false;
                            }
                            else {
                                b = false;
                            }
                        } while (b);
                        b = true;
                        break;
                    }
                    case 5: {
                        b = true;
                        
                        do {
                            g.garage_data_Menu();
                            std::cin >> choice;
                            
                            switch (choice) {
                                case 1: {
                                    std::cout
                                    << "\nThis Garage Has a Capacity of: "
                                    << g.newGarage << " vehicles" << std::endl;
                                    break;
                                }
                                case 2: {
                                    int vacancy = g.get_Vacancy();
                                    std::cout
                                    << "\nNumber of Vacant Parkinglots: "
                                    << vacancy << std::endl;
                                    vacancy = 0;
                                    break;
                                }
                                case 3: {
                                    std::cout << "Vacant lots: " << g.get_Vacancy() << std::endl;
                                    break;
                                }
                                case 4: {
                                    break;
                                }
                                case 5: {
                                    b = false;
                                    c = false;
                                    break;
                                }
                                default: {
                                    std::cout << "\nInvalid input! \n" << std::endl;
                                    b = true;
                                    break;
                                }
                            }
                        } while (b && choice != 4);
                        break;
                    }
                    case 6: {
                        b = false;
                        break;
                    }
                    case 7: {
                        b = false;
                        c = false;
                        break;
                    }
                    default: {
                        std::cout << "\nInvalid input! \n" << std::endl;
                        b = true;
                        break;
                    }
                }
            } while (b);
        }
    } while (c);
    
    std::cout << "\nExiting..." << std::endl;
    return 0;
}
