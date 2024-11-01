/*
    Title: Program 2
    Author: Jenil Goyani, Vraj Patel and Fenil Patel
    Date: 10/15/2024
    Purpose: Create ParkingLotManager with using Template Classes,Linked List and List Node and Sorting Functions
*/
#ifndef PARKINGLOT_MANAGER_H
#define PARKINGLOT_MANAGER_H

#include "LinkedList.h"
#include "ParkingLot.h"

class ParkingLotManager
{
private:
    LinkedList<ParkingLot> lots;    // LinkedList of ParkingLots
    LinkedList<ParkingLot> garages; // LinkedList of Garages

public:
    // Constructor
    ParkingLotManager() {}

    // Add a parking lot
    void addLot(const ParkingLot &lot)
    {
        lots.append(lot);
    }

    // Remove a parking lot
    void removeLot(const ParkingLot &lot)
    {
        lots.remove(lot);
    }

    // Add a garage
    void addGarage(const ParkingLot &garage)
    {
        garages.append(garage);
    }

    // Remove a garage
    void removeGarage(const ParkingLot &garage)
    {
        garages.remove(garage);
    }

    // Show all parking lots
    void showLots()
    {
        cout << "Parking Lots:\n";
        cout << lots << "\n";
    }

    // Show all garages
    void showGarages()
    {
        cout << "Parking Garages:\n";
        cout << garages << "\n";
    }

    // Visit a specific parking lot
    void visitLot(const ParkingLot &lot)
    {
        cout << "Visiting parking lot:\n";
        cout<< lot;
    }
};

#endif
