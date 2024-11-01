/*
    Title: Program 2
    Author: Jenil Goyani, Vraj Patel and Fenil Patel
    Date: 10/15/2024
    Purpose: Create ParkingLotManager with using Template Classes,Linked List and List Node and Sorting Functions
*/
#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include <iostream>

template <typename T>
class SmartPointer
{
private:
    T *ptr;

public:
    // Constructor
    SmartPointer(T *p = nullptr)
    {
        ptr = p;
    }

    // Destructor
    ~SmartPointer()
    {
        delete ptr;
    }

    // Overloading dereference operator
    T &operator*()
    {
        return *ptr;
    }

    // Overloading arrow operator
    T *operator->()
    {
        return ptr;
    }

    // Overloading assignment operator
    SmartPointer &operator=(T *p)
    {
        if (this->ptr != p)
        {
            delete ptr;
            ptr = p;
        }
        return *this;
    }
};

#endif
