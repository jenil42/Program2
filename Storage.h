/*
    Title: Program 2
    Author: Jenil Goyani, Vraj Patel and Fenil Patel
    Date: 10/15/2024
    Purpose: Create ParkingLotManager with using Template Classes,Linked List and List Node and Sorting Functions
*/
#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class Storage
{
private:
    vector<T> items;

public:
    // Add an item to the storage
    void addItem(T item)
    {
        items.push_back(item);
    }

    // Remove an item from the storage
    void removeItem(T item)
    {
        vector<T>::iterator it = remove(items.begin(), items.end(), item);
        items.erase(it, items.end());
    }

    // Get size of the storage
    int size()
    {
        return items.size();
    }

    // Overloading the output stream operator to print all items
    friend void operator<<(ostream &, const Storage<T> &storage)
    {
        for (int i = 0; i < storage.items.size(); ++i)
        {
            cout << "Item " << (i + 1) << ": " << storage.items[i] << "\n";
        }
    }
};

#endif
