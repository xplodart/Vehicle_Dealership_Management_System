#ifndef DATABASE_MANAGEMENT_H
#define DATABASE_MANAGEMENT_H

#include <iostream>
#include <string>
#include <cstring> //not necessary, but could benefit
#include <iomanip>
#include "sqlite3.h"



// Struct for vehicle details
struct GetDetails {
    std::string type, brand, fuelType, color, model, motoType;
    double engine, price, cargoCapacity, towingCapacity;
    int mileage, year, topSpeed;
};


    // Function declaration for creating tables
    void createTables();
    // SQLite database function
    int callback(void *NotUsed, int argc, char **argv, char **azColName);
    void executeSQL(const char* sql);
    // definition of retrieveVehicleDetails function
    GetDetails retrieveVehicleDetails(int vehicleID);
    // definition of retrieveCustomers list
    void retrieveCustomers();


#endif