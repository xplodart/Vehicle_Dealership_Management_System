#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
protected:
    std::string brand;
    double engine;
    std::string fuelType;
    int mileage;
    int year;
    std::string color;
    double price;

public:
    Vehicle(const std::string& brand, double engine, const std::string& fuelType, int mileage, int year, const std::string& color, double price);
    virtual ~Vehicle();

    // Getters
    std::string getBrand() const;
    double getEngine() const;
    std::string getFuelType() const;
    int getMileage() const;
    int getYear() const;
    std::string getColor() const;
    double getPrice() const;

    // Virtual function for displaying details
    virtual void displayDetails() const = 0;
};

class Car : public Vehicle {
private:
    std::string model;
    int topSpeed;

public:
    Car(const std::string& brand, double engine, const std::string& fuelType, int mileage, int year, const std::string& color, double price, const std::string& model, int topSpeed);

    // Getter for model
    std::string getModel() const;

    // Getter for top speed
    int getTopSpeed() const;

    // Display details function
    void displayDetails() const override;
};

class Truck : public Vehicle {
private:
    double cargoCapacity;
    double towingCapacity;

public:
    Truck(const std::string& brand, double engine, const std::string& fuelType, int mileage, int year, const std::string& color, double price, double cargoCapacity, double towingCapacity);

    // Getters for cargo and towing capacity
    double getCargoCapacity() const;
    double getTowingCapacity() const;

    // Display details function
    void displayDetails() const override;
};

class Motorcycle : public Vehicle {
private:
    std::string motoType;

public:
    Motorcycle(const std::string& brand, double engine, const std::string& fuelType, int mileage, int year, const std::string& color, double price, const std::string& motoType);

    // Getter for motorcycle type
    std::string getMotoType() const;

    // Display details function
    void displayDetails() const override;
};

#endif
