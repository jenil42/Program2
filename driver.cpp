/*
    Title: Program 2
    Author: Jenil Goyani, Vraj Patel and Fenil Patel
    Date: 10/15/2024
    Purpose: Create ParkingLotManager with using Template Classes,Linked List and List Node and Sorting Functions
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// create function for display menu
void showMenu()
{
    cout << "\n=== Parking Lot Management System ===\n";
    cout << "1. Add Vehicles\n";
    cout << "2. Add Parking Lots\n";
    cout << "3. Show All Entries\n";
    cout << "4. Clear File\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

// create function for adding vehicles in the file
void addVehicles(ofstream &file)
{
    for (int i = 0; i < 3; ++i)
    {
        string license, make, model;
        int year;

        cout << "Enter details for Vehicle " << (i + 1) << ":\n";
        cout << "License: ";
        cin >> license;
        cout << "Make: ";
        cin >> make;
        cout << "Model: ";
        cin >> model;
        cout << "Year: ";
        cin >> year;

        file << "Vehicle " << (i + 1) << " - License: " << license
             << ", Make: " << make << ", Model: " << model
             << ", Year: " << year << "\n";
    }
}

// Adds parking lot details to the file
void addParkingLots(ofstream &file)
{
    for (int i = 0; i < 2; ++i)
    {
        int lotID;
        cout << "\nEnter Parking Lot ID for Lot " << (i + 1) << ": ";
        cin >> lotID;
        file << "Parking Lot " << (i + 1) << " - ID: " << lotID << "\n";
    }
}

// Create function to clear data from the files
void clearFile()
{
    ofstream clearFile("TEST_CASE.txt", ofstream::trunc);
    clearFile.close();
    cout << "File cleared successfully.\n";
}

// Displays all entries in the file
void showEntries()
{
    int i = 1;
    ifstream readFile("TEST_CASE.txt");
    if (!readFile)
    {
        cout << "File could not be opened.\n";
        return;
    }

    string line;
    while (getline(readFile, line))
    {
        i = 0;
        cout << line << "\n";
    }
    if (i == 1)
    {
        cout << "Your File is Empty";
    }

    readFile.close();
}

// Create Main function to run the Parking Lot Management System
int main()
{
    int choice;
    ofstream testFile;

    // Create loop to display menu and handle user input
    do
    {
        showMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            testFile.open("TEST_CASE.txt", ios::app); // Append mode
            if (!testFile)
            {
                cout << "Unable to open the file." << endl;
                return 1;
            }
            addVehicles(testFile);
            testFile.close();
            break;
        case 2:
            testFile.open("TEST_CASE.txt", ios::app); // Append mode
            if (!testFile)
            {
                cout << "Unable to open the file." << endl;
                return 1;
            }
            addParkingLots(testFile);
            testFile.close();
            break;
        case 3:
            showEntries();
            break;
        case 4:
            clearFile();
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
