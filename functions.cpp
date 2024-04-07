#include "functions.h"
#include <iostream>

using namespace std;

void addVehicle(Vehicle* vehicle) {
    string type;
    string sql = "INSERT INTO Vehicles (Type, Brand, Engine, FuelType, Mileage, Year, Color, Price";

    // Check "Type" attribute
    if (Car* car = dynamic_cast<Car*>(vehicle)) {
        type = "Car";
        sql += ", Model, TopSpeed) VALUES (";
    } else if (Truck* truck = dynamic_cast<Truck*>(vehicle)) {
        type = "Truck";
        sql += ", CargoCapacity, TowingCapacity) VALUES (";
    } else if (Motorcycle* motorcycle = dynamic_cast<Motorcycle*>(vehicle)) {
        type = "Motorcycle";
        sql += ", MotoType) VALUES (";
    }

    // Add attributes to the SQL query
    sql += "'" + toUpper(type) + "', "; 
    sql += "'" + toUpper(vehicle->getBrand()) + "', ";
    sql += to_string(vehicle->getEngine()) + ", "; 
    sql += "'" + toUpper(vehicle->getFuelType()) + "', ";
    sql += to_string(vehicle->getMileage()) + ", "; 
    sql += to_string(vehicle->getYear()) + ", ";
    sql += "'" + toUpper(vehicle->getColor()) + "', ";
    sql += to_string(vehicle->getPrice());

    // Add additional attributes based on the type of vehicle
    if (type == "Car") {
        Car* car = dynamic_cast<Car*>(vehicle);
        sql += ", '" + toUpper(car->getModel()) + "', ";
        sql += to_string(car->getTopSpeed()) + ")";
    } else if (type == "Truck") {
        Truck* truck = dynamic_cast<Truck*>(vehicle);
        sql += ", " + to_string(truck->getCargoCapacity()) + ", ";
        sql += to_string(truck->getTowingCapacity()) + ")";
    } else if (type == "Motorcycle") {
        Motorcycle* motorcycle = dynamic_cast<Motorcycle*>(vehicle);
        sql += ", '" + toUpper(motorcycle->getMotoType()) + "')";
    }

    executeSQL(sql.c_str());

    displayUnderline();
    cout << "Vehicle added successfully!" << endl;
}

void viewVehicles(){
    int viewChoice;
    cout << "1. View All Vehicles" << endl;
    cout << "2. View Cars" << endl;
    cout << "3. View Trucks" << endl;
    cout << "4. View Motorcycles" << endl;
    cout << "5. Back to Main Menu" << endl;
    displayUnderline();
    cout << "Choose an option: ";
    cin >> viewChoice;
        switch (viewChoice) {
            case 1: {
                // View all vehicles from Vehicles table
                const char* sql = "SELECT * FROM Vehicles;";
                executeSQL(sql);
                break;
            }
            case 2: {
                // View only cars from Vehicles table
                const char* sql = "SELECT * FROM Vehicles WHERE Type='CAR';";
                executeSQL(sql);
                break;
            }
            case 3: {
                // View only trucks from Vehicles table
                const char* sql = "SELECT * FROM Vehicles WHERE Type='TRUCK';";
                executeSQL(sql);
                break;
            }
            case 4: {
                // View only motorcycles from Vehicles table
                const char* sql = "SELECT * FROM Vehicles WHERE Type='MOTORCYCLE';";
                executeSQL(sql);
                break;
            }
            case 5:
                // Return to Main Menu
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
}


void searchVehicles() {
    displayHeader("Search Vehicles");

    int searchChoice;
    cout << "Search By:" << endl;
    cout << "1. Brand" << endl;
    cout << "2. Engine" << endl;
    cout << "3. Mileage" << endl;
    cout << "4. Year" << endl;
    cout << "5. Fuel Type" << endl;
    cout << "6. Color" << endl;
    cout << "7. Model" << endl;
    cout << "8. Price Range" << endl;
    cout << "9. Back to main menu" << endl;
    displayUnderline();
    cout << "Choose an option: ";
    cin >> searchChoice;

    switch (searchChoice) {
        case 1: {
            string brand;
            cout << "Enter Brand: ";
            cin >> brand;
            displaySeparator();
            string sql = "SELECT * FROM Vehicles WHERE Brand='" + toUpper(brand) + "';";
            executeSQL(sql.c_str());
            break;
        }
        case 2: {
            double minEngine, maxEngine;
            cout << "Enter Minimum Engine: ";
            cin >> minEngine;
            cout << "Enter Maximum Engine: ";
            cin >> maxEngine;
            displaySeparator();
            string sql = "SELECT * FROM Vehicles WHERE Engine BETWEEN " + to_string(minEngine) + " AND " + to_string(maxEngine) + ";";
            executeSQL(sql.c_str());
            break;
        }
        case 3: {
            int minMileage, maxMileage;
            cout << "Enter Minimum Mileage: ";
            cin >> minMileage;
            cout << "Enter Maximum Mileage: ";
            cin >> maxMileage;
            displaySeparator();
            string sql = "SELECT * FROM Vehicles WHERE Mileage BETWEEN " + to_string(minMileage) + " AND " + to_string(maxMileage) + ";";
            executeSQL(sql.c_str());
            break;
        }
        case 4: {
            int minYear, maxYear;
            cout << "Enter Minimum Year: ";
            cin >> minYear;
            cout << "Enter Maximum Year: ";
            cin >> maxYear;
            displaySeparator();
            string sql = "SELECT * FROM Vehicles WHERE Year BETWEEN " + to_string(minYear) + " AND " + to_string(maxYear) + ";";
            executeSQL(sql.c_str());
            break;
        }
        case 5: {
            string fuelType;
            cout << "Enter Fuel Type: ";
            cin >> fuelType;
            displaySeparator();
            string sql = "SELECT * FROM Vehicles WHERE FuelType='" + toUpper(fuelType) + "';";
            executeSQL(sql.c_str());
            break;
        }
        case 6: {
            string color;
            cout << "Enter Color: ";
            cin >> color;
            displaySeparator();
            string sql = "SELECT * FROM Vehicles WHERE Color='" + toUpper(color) + "';";
            executeSQL(sql.c_str());
            break;
        }
        case 7: {
            string model;
            cout << "Enter Model: ";
            cin >> model;
            displaySeparator();
            string sql = "SELECT * FROM Vehicles WHERE Model='" + toUpper(model) + "';";
            executeSQL(sql.c_str());
            break;
        }
        case 8: {
            double minPrice, maxPrice;
            cout << "Enter Minimum Price: ";
            cin >> minPrice;
            cout << "Enter Maximum Price: ";
            cin >> maxPrice;
            displaySeparator();
            string sql = "SELECT * FROM Vehicles WHERE Price BETWEEN " + to_string(minPrice) + " AND " + to_string(maxPrice) + ";";
            executeSQL(sql.c_str());
            break;
        }
        case 9: {
            break;
        }
        default:
            cout << "Invalid choice! Please try again." << endl;
    }
}



void editVehicle() {
    displayHeader("Edit a Vehicle");

    cout << "Enter the ID of the vehicle you want to edit: ";
    int vehicleID;
    cin >> vehicleID;
    cin.ignore();

    // Calls the Helper function to get vehicle details from database 
    GetDetails vehicleDetails = retrieveVehicleDetails(vehicleID);
    
    // Check if the vehicle exists
    if (vehicleDetails.type.empty()) {
        cout << "No vehicle found with ID " << vehicleID << "." << endl;
        displayMenu();
        return;
    }
    string sql = "SELECT * FROM Vehicles WHERE ID='" + to_string(vehicleID) + "';";
    executeSQL(sql.c_str());  


    string userInput;

    cout << "Do you want to amend the Brand? (Press Enter to keep the current value): ";
    getline(cin, userInput);
    if (!userInput.empty()) {
        transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
        vehicleDetails.brand = userInput;
    }

    cout << "Do you want to amend the Engine? (Press Enter to keep the current value): ";
    getline(cin, userInput);
    if (!userInput.empty()) {
        vehicleDetails.engine = stoi(userInput);
    }

    cout << "Do you want to amend the Fuel Type? (Press Enter to keep the current value): ";
    getline(cin, userInput);
    if (!userInput.empty()) {
        transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
        vehicleDetails.fuelType = userInput;
    }

    cout << "Do you want to amend the Mileage? (Press Enter to keep the current value): ";
    getline(cin, userInput);
    if (!userInput.empty()) {
        vehicleDetails.mileage = stoi(userInput);
    }

    cout << "Do you want to amend the Year? (Press Enter to keep the current value): ";
    getline(cin, userInput);
    if (!userInput.empty()) {
        vehicleDetails.year = stoi(userInput);
    } 
    
    cout << "Do you want to amend the Color? (Press Enter to keep the current value): ";
    getline(cin, userInput);
    if (!userInput.empty()) {
        transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
        vehicleDetails.color = userInput;
    }

    cout << "Do you want to amend the Price? (Press Enter to keep the current value): ";
    getline(cin, userInput);
    if (!userInput.empty()) {
        vehicleDetails.price = stod(userInput);
    }

    // Only attributes for cars
    if (vehicleDetails.type == "CAR") {
         cout << "Do you want to amend the Model? (Press Enter to keep the current value): ";
        getline(cin, userInput);
        if (!userInput.empty()) {
            transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
            vehicleDetails.model = userInput;
        }

        cout << "Do you want to amend the Top Speed? (Press Enter to keep the current value): ";
        getline(cin, userInput);
        if (!userInput.empty()) {
            vehicleDetails.topSpeed = stoi(userInput);
        }
    }

    // Only attributes for trucks
    if (vehicleDetails.type == "TRUCK") {
        cout << "Do you want to amend Cargo Capacity? (Press Enter to keep the current value): ";
        getline(cin, userInput);
        if (!userInput.empty()) {
            vehicleDetails.cargoCapacity = stoi(userInput);
        }

        cout << "Do you want to amend Towing Capacity? (Press Enter to keep the current value): ";
        getline(cin, userInput);
        if (!userInput.empty()) {
            vehicleDetails.towingCapacity = stoi(userInput);
        }
    }

    // Only attributes for motorcycles
    if (vehicleDetails.type == "MOTORCYCLE") {
        cout << "Do you want to amend Moto Type? (Press Enter to keep the current value): ";
        getline(cin, userInput);
        if (!userInput.empty()) {
            transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
            vehicleDetails.motoType = userInput;
        }
    }

    // Update database with the new values
    sql = "UPDATE Vehicles SET Brand = '" + vehicleDetails.brand + "', Engine = " + to_string(vehicleDetails.engine) + ", FuelType = '" + vehicleDetails.fuelType + "', Mileage = " + to_string(vehicleDetails.mileage) + ", Year = " + to_string(vehicleDetails.year) + ", Color = '" + vehicleDetails.color + "', Price = " + to_string(vehicleDetails.price);

    if (vehicleDetails.type == "CAR") {
        sql += ", Model = '" + vehicleDetails.model + "', TopSpeed = " + to_string(vehicleDetails.topSpeed);
    } else if (vehicleDetails.type == "TRUCK") {
        sql += ", CargoCapacity = " + to_string(vehicleDetails.cargoCapacity) + ", TowingCapacity = " + to_string(vehicleDetails.towingCapacity);
    } else if (vehicleDetails.type == "MOTORCYCLE") {
        sql += ", MotoType = '" + vehicleDetails.motoType + "'";
    }

    sql += " WHERE ID = " + to_string(vehicleID) + ";";
    executeSQL(sql.c_str());

    displayUnderline();
    cout << "Vehicle details updated successfully!" << endl;

    displayMenu();
}

void removeVehicle() {
    displayHeader("Remove a Vehicle");

    int vehicleID;
    cout << "Enter the ID of the vehicle you want to remove: ";
    cin >> vehicleID;
    cin.ignore();
    
    GetDetails vehicleDetails = retrieveVehicleDetails(vehicleID);

    // Check if the vehicle exists
    if (vehicleDetails.type.empty()) {
        cout << "No vehicle found with ID " << vehicleID << "." << endl;
        displayMenu();
        return;
    }
    string sql = "SELECT * FROM Vehicles WHERE ID='" + to_string(vehicleID) + "';";
    executeSQL(sql.c_str());  
    

    // Get confirmation from the user
    char confirm;
    cout << "Are you sure you want to remove vehicle with ID " << vehicleID << "? (y/n): ";
    cin >> confirm;
    cin.ignore();

    if (confirm == 'y' || confirm == 'Y') {
        // Delete the vehicle from the Vehicles table
        sql = "DELETE FROM Vehicles WHERE ID = " + to_string(vehicleID) + ";";
        executeSQL(sql.c_str());

        displayUnderline();
        cout << "Vehicle removed successfully!" << endl;
    } else {
        cout << "Operation cancelled." << endl;
    }

    // Display main menu
    displayMenu();
}


void sellVehicle() {
displayHeader("Sell a Vehicle");
 
    int vehicleID;
    cout << "Enter the ID of the vehicle you want to sell: ";
    cin >> vehicleID;
    cin.ignore();

    // Calls the Helper function to get vehicle details from database
    GetDetails vehicleDetails = retrieveVehicleDetails(vehicleID);
    
    // Check if the vehicle exists
    if (vehicleDetails.type.empty()) {
        cout << "No vehicle found with ID " << vehicleID << "." << endl;
        displayMenu();
        return;
    }
    string sql = "SELECT * FROM Vehicles WHERE ID='" + to_string(vehicleID) + "';";
    executeSQL(sql.c_str());  

    string date, name, surname, contact;

    // Get additional information for the sold vehicle
    cout << "Enter sale date (YYYY-MM-DD): ";
    getline(cin, date);
    cout << "Enter buyer's name: ";
    getline(cin, name);
    cout << "Enter buyer's surname: ";
    getline(cin, surname);
    cout << "Enter buyer's contact: ";
    getline(cin, contact);

    // Insert the sold vehicle into the SoldVehicles table
    sql = "INSERT INTO SoldVehicles (Type, Brand, Engine, FuelType, Mileage, Year, Color, Price, Model, TopSpeed, CargoCapacity, TowingCapacity, MotoType, Date, Name, Surname, Contact) VALUES ('" +
          vehicleDetails.type + "', '" +
          vehicleDetails.brand + "', " +
          to_string(vehicleDetails.engine) + ", '" +
          vehicleDetails.fuelType + "', " +
          to_string(vehicleDetails.mileage) + ", " +
          to_string(vehicleDetails.year) + ", '" +
          vehicleDetails.color + "', " +
          to_string(vehicleDetails.price) + ", '" +
          vehicleDetails.model + "', " +
          to_string(vehicleDetails.topSpeed) + ", " +
          to_string(vehicleDetails.cargoCapacity) + ", " +
          to_string(vehicleDetails.towingCapacity) + ", '" +
          vehicleDetails.motoType + "', '" +
          date + "', '" +
          name + "', '" +
          surname + "', '" +
          contact + "');";
    executeSQL(sql.c_str());

    // Insert the customer into the Customers table
    sql = "INSERT INTO Customers (Name, Surname, Contact) VALUES ('" +
          name + "', '" +
          surname + "', '" +
          contact + "');";
    executeSQL(sql.c_str());

    // Delete the sold vehicle from the Vehicles table
    sql = "DELETE FROM Vehicles WHERE ID = " + to_string(vehicleID) + ";";
    executeSQL(sql.c_str());

    displayUnderline();
    cout << "Vehicle sold successfully!" << endl;
}


void viewSoldVehicles(){
displayHeader("Sold Vehicles");

int viewChoice;
    cout << "1. View All Sold Vehicles" << endl;
    cout << "2. View Sold Cars" << endl;
    cout << "3. View Sold Trucks" << endl;
    cout << "4. View Sold Motorcycles" << endl;
    cout << "5. Back to Main Menu" << endl;
    displayUnderline();
    cout << "Choose an option: ";
    cin >> viewChoice;
    displaySeparator();
        switch (viewChoice) {
            case 1: {
                // View all vehicles from soldVehicles table
                const char* sql = "SELECT * FROM soldVehicles;";
                executeSQL(sql);
                break;
            }
            case 2: {
                // View only cars from soldVehicles table
                const char* sql = "SELECT * FROM soldVehicles WHERE Type = 'CAR';";
                executeSQL(sql);
                break;
            }
            case 3: {
                // View only trucks from soldVehicles table
                const char* sql = "SELECT * FROM soldVehicles WHERE Type = 'TRUCK';";
                executeSQL(sql);
                break;
            }
            case 4: {
                // View only motorcycles from soldVehicles table
                const char* sql = "SELECT * FROM soldVehicles WHERE Type='MOTORCYCLE';";
                executeSQL(sql);
                break;
            }
            case 5:
                // Return to Main Menu
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
                 
};

void viewCustomers(){
     retrieveCustomers();
};

void displayStatistics() {
    displayHeader("Statistics");

    int choice;
    do {
        // Display submenu
        cout << "1. Total Number of Vehicles by Category\n";
        cout << "2. Average Mileage by Vehicle Type\n";
        cout << "3. Average Price by Vehicle Type\n";
        cout << "4. Most Popular Brand\n";
        cout << "5. Age Distribution of Vehicles\n";
        cout << "6. Color Distribution\n";
        cout << "7. Fuel Type Distribution\n";
        cout << "8. Back to main menu\n";
        displayUnderline();
        cout << "Enter your choice: ";
        cin >> choice;
        displaySeparator();

        // Handles SQL query based on user choice
        switch (choice) {
            case 1: {
                const char* totalVehiclesByCategoryQuery = "SELECT Type, COUNT(*) AS Total FROM Vehicles GROUP BY Type;";
                cout << "\nTotal Number of Vehicles by Category:\n";
                executeSQL(totalVehiclesByCategoryQuery);
                break;
            }
            case 2: {
                const char* avgMileageByTypeQuery = "SELECT Type, AVG(Mileage) AS AvgMileage FROM Vehicles GROUP BY Type;";
                cout << "\nAverage Mileage by Vehicle Type:\n";
                executeSQL(avgMileageByTypeQuery);
                break;
            }
            case 3: {
                const char* avgPriceByTypeQuery = "SELECT Type, AVG(Price) AS AvgPrice FROM Vehicles GROUP BY Type;";
                cout << "\nAverage Price by Vehicle Type:\n";
                executeSQL(avgPriceByTypeQuery);
                break;
            }
            case 4: {
                const char* mostPopularBrandQuery = "SELECT Brand, COUNT(*) AS Total FROM Vehicles GROUP BY Brand ORDER BY Total DESC LIMIT 1;";
                cout << "\nMost Popular Brand:\n";
                executeSQL(mostPopularBrandQuery);
                break;
            }
            case 5: {
                const char* ageDistributionQuery = "SELECT strftime('%Y', 'now') - Year AS Age, COUNT(*) AS Total FROM Vehicles GROUP BY Age ORDER BY Age;";
                cout << "\nAge Distribution of Vehicles:\n";
                executeSQL(ageDistributionQuery);
                break;
            }
            case 6: {
                const char* colorDistributionQuery = "SELECT Color, COUNT(*) AS Total FROM Vehicles GROUP BY Color;";
                cout << "\nColor Distribution:\n";
                executeSQL(colorDistributionQuery);
                break;
            }
            case 7: {
                const char* fuelTypeDistributionQuery = "SELECT FuelType, COUNT(*) AS Total FROM Vehicles GROUP BY FuelType;";
                cout << "\nFuel Type Distribution:\n";
                executeSQL(fuelTypeDistributionQuery);
                break;
            }
            case 8: {
                break;
            }
            default:
                cout << "Invalid choice. Please enter a number between 1 and 8.\n";
        }
    } while (choice != 8);
}
