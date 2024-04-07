
#include "menu.h"
#include <iostream>


using namespace std;

void displayMenu() {
    int choice;
    do {
        cout << endl;
        cout << "======================================================================" << endl;
        cout << "------------------   Car Dealer Management System   ------------------" << endl;
        cout << "======================================================================" << endl;
        cout << "1. Add a Vehicle" << endl;
        cout << "2. View Vehicles" << endl;
        cout << "3. Search Vehicles" << endl;
        cout << "4. Edit a Vehicle" << endl;
        cout << "5. Remove a Vehicle" << endl;
        cout << "6. Sell a Vehicle" << endl;
        cout << "7. Sold Vehicles" << endl;
        cout << "8. Customers" << endl;
        cout << "9. Statistics" << endl;
        cout << "0. Exit" << endl;
        displayUnderline();
        cout << "Choose an option: ";
        cin >> choice;
        displaySeparator();



        switch (choice) {
            case 1: {
                // Submenu for add vehicles
                displayHeader("Add a Vehicle");

                int addChoice;
                cout << "1. Add Car" << endl;
                cout << "2. Add Truck" << endl;
                cout << "3. Add Motorcycle" << endl;
                cout << "4. Back to Main Menu" << endl;
                displayUnderline();
                cout << "Choose an option: ";
                cin >> addChoice;

                switch (addChoice) {
                    case 1: {
                        string brand, fuelType, color, model;
                        double engine, price;
                        int mileage, year, topSpeed;

                        cout << "Enter Brand: ";
                        cin >> brand;
                        cout << "Enter Engine: ";
                        while (!(cin >> engine)) {
                            cerr << "Invalid input. Please enter a valid Engine value." << endl;
                            cout << "Enter Engine: ";
                            cin.clear();
                            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                        }
                        cout << "Enter Fuel Type: ";
                        cin >> fuelType;
                        cout << "Enter Mileage: ";
                        while (!(cin >> mileage)) {
                            cerr << "Invalid input. Please enter a valid Mileage value." << endl;
                            cout << "Enter Mileage: ";
                            cin.clear();
                            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                        }
                        cout << "Enter Year: ";
                        while (!(cin >> year)) {
                            cerr << "Invalid input. Please enter a valid Year value." << endl;
                            cout << "Enter Year: ";
                            cin.clear();
                            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                        }
                        cout << "Enter Color: ";
                        cin >> color;
                        cout << "Enter Price: ";
                        while (!(cin >> price)) {
                            cerr << "Invalid input. Please enter a valid Price value." << endl;
                            cout << "Enter Price: ";
                            cin.clear();
                            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                        }
                        cout << "Enter Model: ";
                        cin >> model;
                        cout << "Enter Top Speed: ";
                        while (!(cin >> topSpeed)) {
                            cerr << "Invalid input. Please enter a valid Top Speed value." << endl;
                            cout << "Enter Topspeed: ";
                            cin.clear();
                            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                        }

                        Car* car = new Car(brand, engine, fuelType, mileage, year, color, price, model, topSpeed);
                        addVehicle(car);

                        delete car;
                        break;
                    }
                    case 2: {
                        string brand, fuelType, color;
                        double engine, price, cargoCapacity, towingCapacity;
                        int mileage, year;

                        cout << "Enter Brand: ";
                        cin >> brand;
                        cout << "Enter Engine: ";
                        while (!(cin >> engine)) {
                            cerr << "Invalid input. Please enter a valid Engine value." << endl;
                            cout << "Enter Engine: ";
                            cin.clear();
                            cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); 
                        }
                        cout << "Enter Fuel Type: ";
                        cin >> fuelType;
                        cout << "Enter Mileage: ";
                        while (!(cin >> mileage)) {
                            cerr << "Invalid input. Please enter a valid Mileage value." << endl;
                            cout << "Enter Mileage: ";
                            cin.clear();
                            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                        }
                        cout << "Enter Year: ";
                        while (!(cin >> year)) {
                            cerr << "Invalid input. Please enter a valid Year value." << endl;
                            cout << "Enter Year: ";
                            cin.clear();
                            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                        }
                        cout << "Enter Color: ";
                        cin >> color;
                        cout << "Enter Price: ";
                        while (!(cin >> price)) {
                            cerr << "Invalid input. Please enter a valid Price value." << endl;
                            cout << "Enter Price: ";
                            cin.clear();
                            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                        }
                        cout << "Enter Cargo Capacity: ";
                        while (!(cin >> cargoCapacity)) {
                            cerr << "Invalid input. Please enter a valid Cargo Capacity value." << endl;
                            cout << "Enter Cargo Capacity: ";
                            cin.clear();
                            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                        }
                        cout << "Enter Towing Capacity: ";
                        while (!(cin >> towingCapacity)) {
                            cerr << "Invalid input. Please enter a valid Towing Capacity value." << endl;
                            cout << "Enter Towing Capacity: ";
                            cin.clear();
                            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                        }

                        Truck* truck = new Truck(brand, engine, fuelType, mileage, year, color, price, cargoCapacity, towingCapacity);
                        addVehicle(truck);

                        delete truck;
                        break;
                    }
                    case 3: {
                        string brand, fuelType, color, motoType;
                        double engine, price;
                        int mileage, year;

                        cout << "Enter Brand: ";
                        cin >> brand;
                        cout << "Enter Engine: ";
                        while (!(cin >> engine)) {
                            cerr << "Invalid input. Please enter a valid Engine value." << endl;
                            cout << "Enter Engine: ";
                            cin.clear();
                            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                        }
                        cout << "Enter Fuel Type: ";
                        cin >> fuelType;
                        cout << "Enter Mileage: ";
                        while (!(cin >> mileage)) {
                            cerr << "Invalid input. Please enter a valid Mileage value." << endl;
                            cout << "Enter Mileage: ";
                            cin.clear();
                            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                        }
                        cout << "Enter Year: ";
                        while (!(cin >> year)) {
                            cerr << "Invalid input. Please enter a valid Year value." << endl;
                            cout << "Enter Year: ";
                            cin.clear();
                            cin.ignore(std::numeric_limits<streamsize>::max(), '\n'); 
                        }
                        cout << "Enter Color: ";
                        cin >> color;
                        cout << "Enter Price: ";
                        while (!(cin >> price)) {
                            cerr << "Invalid input. Please enter a valid Price value." << endl;
                            cout << "Enter Price: ";
                            cin.clear();
                            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
                        }
                        cout << "Enter Moto Type: ";
                        cin >> motoType;

                        Motorcycle* motorcycle = new Motorcycle(brand, engine, fuelType, mileage, year, color, price, motoType);
                        addVehicle(motorcycle);

                        delete motorcycle;
                        break;
                    }
                    case 4:
                        // Return to Main Menu
                        break;
                    default:
                        cout << "Invalid choice! Please try again." << endl;
                }
                break;
            }
            case 2:
                // Code for viewing vehicles
                viewVehicles();
                break;
             case 3:
                // Code for searching vehicles
                searchVehicles();
                break;
            case 4:
                // Code for editing a vehicle
                editVehicle();
                break;
            case 5:
                // Code for selling a vehicle
                removeVehicle();
                break;
            case 6:
                // Code for selling a vehicle
                sellVehicle();
                break;
            case 7:
                // Code for viewing sold vehicles
                viewSoldVehicles();
                break;
            case 8:
                // Code for viewing customers
                viewCustomers(); 
                break;
            case 9:
                // Code for viewing statistics
                displayStatistics();
                break;  
            case 0:
                // Code for viewing statistics
                cout << "Exiting..." << endl;
                break;             
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 0);
}