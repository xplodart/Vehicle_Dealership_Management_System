#include "vehicle.h"
#include <iostream>

// Implementation of Vehicle constructor and destructor
Vehicle::Vehicle(const std::string& brand, double engine, const std::string& fuelType, int mileage, int year, const std::string& color, double price)
    : brand(brand), engine(engine), fuelType(fuelType), mileage(mileage), year(year), color(color), price(price) {}

Vehicle::~Vehicle() {}

// Implementations of Vehicle member functions
std::string Vehicle::getBrand() const {
    return brand;
}
double Vehicle::getEngine() const {
    return engine;
}
std::string Vehicle::getFuelType() const {
    return fuelType;
}
int Vehicle::getMileage() const {
    return mileage;
}
int Vehicle::getYear() const {
    return year;
}
std::string Vehicle::getColor() const {
    return color;
}
double Vehicle::getPrice() const {
    return price;
}

// Implementation of Car constructor and displayDetails function
Car::Car(const std::string& brand, double engine, const std::string& fuelType, int mileage, int year, const std::string& color, double price, const std::string& model, int topSpeed)
    : Vehicle(brand, engine, fuelType, mileage, year, color, price), model(model), topSpeed(topSpeed) {}

std::string Car::getModel() const {
    return model;
}

int Car::getTopSpeed() const {
    return topSpeed;
}

void Car::displayDetails() const {
    std::cout << "Brand: " << brand << ", Model: " << model << ", Engine: " << engine << ", Fuel Type: " << fuelType
              << ", Mileage: " << mileage << ", Year: " << year << ", Color: " << color << ", Price: " << price << ", Top Speed: " << topSpeed << std::endl;
}

// Implementation of Truck constructor and displayDetails function
Truck::Truck(const std::string& brand, double engine, const std::string& fuelType, int mileage, int year, const std::string& color, double price, double cargoCapacity, double towingCapacity)
    : Vehicle(brand, engine, fuelType, mileage, year, color, price), cargoCapacity(cargoCapacity), towingCapacity(towingCapacity) {}

double Truck::getCargoCapacity() const {
    return cargoCapacity;
}

double Truck::getTowingCapacity() const {
    return towingCapacity;
}

void Truck::displayDetails() const {
    std::cout << "Brand: " << brand << ", Engine: " << engine << ", Fuel Type: " << fuelType << ", Mileage: " << mileage
              << ", Year: " << year << ", Color: " << color << ", Price: " << price << ", Cargo Capacity: " << cargoCapacity
              << ", Towing Capacity: " << towingCapacity << std::endl;
}

// Implementation of Motorcycle constructor and displayDetails function
Motorcycle::Motorcycle(const std::string& brand, double engine, const std::string& fuelType, int mileage, int year, const std::string& color, double price, const std::string& motoType)
    : Vehicle(brand, engine, fuelType, mileage, year, color, price), motoType(motoType) {}

std::string Motorcycle::getMotoType() const {
    return motoType;
}

void Motorcycle::displayDetails() const {
    std::cout << "Brand: " << brand << ", Engine: " << engine << ", Fuel Type: " << fuelType << ", Mileage: " << mileage
              << ", Year: " << year << ", Color: " << color << ", Price: " << price << ", Moto Type: " << motoType << std::endl;
}
