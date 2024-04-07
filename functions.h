#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "vehicle.h"
#include "utilities.h"
#include "database_management.h"

void addVehicle(Vehicle* vehicle);
void viewVehicles();
void searchVehicles();
void editVehicle();
void removeVehicle();
void sellVehicle();
void viewSoldVehicles();
void viewCustomers();
void displayStatistics();
void displayMenu();

#endif

