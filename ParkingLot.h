/*
    Title: Program 2
    Author: Jenil Goyani, Vraj Patel and Fenil Patel
    Date: 10/15/2024
    Purpose: Create ParkingLotManager with using Template Classes,Linked List and List Node and Sorting Functions
*/
#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "Vehicle.h"
#include "Storage.h"
#include <string>

class ParkingLot
{
private:
    Storage<Vehicle> vehicles; // A storage for vehicles in this lot
    int lotID;                 // Unique ID for each lot

public:
    // Constructor
    ParkingLot(int id)
    {
        lotID = id;
    }

    // Add a vehicle to the parking lot
    void addVehicle(Vehicle vehicle)
    {
        vehicles.addItem(vehicle);
    }

    // Remove a vehicle from the parking lot
    void removeVehicle(Vehicle vehicle)
    {
        vehicles.removeItem(vehicle);
    }

    // Get the number of vehicles in the lot
    int getNumVehicles()
    {
        return vehicles.size();
    }

    // Overloading the output stream operator to print all vehicles in the lot
    friend ostream &operator<<(ostream &os, ParkingLot lot)
    {
        os << "Parking Lot ID: " << lot.lotID << "\nVehicles:\n"
           << lot.vehicles;
        return os;
    }

    // Overloading the equality operator to compare two parking lots
    bool operator==(ParkingLot other)
    {
        return this->lotID == other.lotID;
    }

    bool operator!=(ParkingLot other)
    {
        return !(*this == other);
    }
};

#endif
