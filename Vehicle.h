/*
    Title: Program 2
    Author: Jenil Goyani, Vraj Patel and Fenil Patel
    Date: 10/15/2024
    Purpose: Create ParkingLotManager with using Template Classes,Linked List and List Node and Sorting Functions
*/
#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
private:
    string licensePlate;
    string make;
    string model;
    int year;

public:
    Vehicle()
    {
        year = 0;
    }
    Vehicle(string licensePlate, string make, string model, int year)
    {
        this->licensePlate = licensePlate;
        this->make = make;
        this->model = model;
        this->year = year;
    }

    // Getters and Setters
    string getLicensePlate()
    {
        return licensePlate;
    }
    string getMake()
    {
        return make;
    }
    string getModel()
    {
        return model;
    }
    int getYear()
    {
        return year;
    }

    // Comparison operators
    bool operator<(Vehicle other)
    {
        return this->licensePlate < other.licensePlate;
    }

    bool operator>(Vehicle other)
    {
        return this->licensePlate > other.licensePlate;
    }

    bool operator==(Vehicle other)
    {
        return this->licensePlate == other.licensePlate;
    }

    friend ostream &operator<<(ostream &os, Vehicle v)
    {
        os << v.licensePlate << " (" << v.make << " " << v.model << " " << v.year << ")";
        return os;
    }
};

#endif
