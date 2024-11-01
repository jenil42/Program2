/*
    Title: Program 2
    Author: Jenil Goyani, Vraj Patel and Fenil Patel
    Date: 10/15/2024
    Purpose: Create ParkingLotManager with using Template Classes,Linked List and List Node and Sorting Functions
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <functional>

// Node class
template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T value) : data(value)
    {
        next = nullptr;
    }
};

// LinkedList class
template <typename T>
class LinkedList
{
private:
    Node<T> *head;
    int size;

public:
    // Constructor
    LinkedList()
    {
        head = nullptr;
        size = 0;
    }

    // Destructor
    ~LinkedList()
    {
        Node<T> *current = head;
        while (current)
        {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
    }

    // Add a node at the end
    void append(const T &data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node<T> *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    // Remove a node with specific data
    void remove(const T &data)
    {
        Node<T> *temp = head;
        Node<T> *prev = nullptr;
        while (temp && !(temp->data == data))
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp)
        {
            if (prev)
            {
                prev->next = temp->next;
            }
            else
            {
                head = temp->next;
            }
            delete temp;
            size--;
        }
    }

    // Sorting function
    void sort(bool ascending = true, function<bool(const T &, const T &)> comparator = nullptr)
    {
        if (!comparator)
        {
            comparator = [](const T &a, const T &b)
            { return a < b; };
        }

        if (!ascending)
        {
            comparator = [=](const T &a, const T &b)
            { return comparator(b, a); };
        }

        quickSort(head, comparator);
    }

    // QuickSort function
    void quickSort(Node<T> *&head, function<bool(const T &, const T &)> comparator)
    {
        if (!head || !head->next)
            return;

        Node<T> *pivot = head;
        Node<T> *less = nullptr, *greater = nullptr;

        Node<T> *current = head->next;
        while (current)
        {
            Node<T> *next = current->next;
            if (comparator(current->data, pivot->data))
            {
                current->next = less;
                less = current;
            }
            else
            {
                current->next = greater;
                greater = current;
            }
            current = next;
        }

        quickSort(less, comparator);
        quickSort(greater, comparator);

        if (less)
        {
            head = less;
            while (less->next)
                less = less->next;
            less->next = pivot;
        }
        else
        {
            head = pivot;
        }
        pivot->next = greater;
    }

    // Print list
    friend ostream &operator<<(ostream &os, const LinkedList<T> &list)
    {
        Node<T> *temp = list.head;
        while (temp)
        {
            os << temp->data << " ";
            temp = temp->next;
        }
        return os;
    }
};

#endif
