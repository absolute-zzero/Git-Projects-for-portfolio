//PROGRAM HEADER
/************************************************************************************************************************

Name:  Romari Bartley        Z#: Z23575490
Course: Data Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date:  04/2/2021           Due Time: 11:59 PM
Total Points: 25
Assignment #3(module6): bqueue_driver.cpp

Description: The purpose of this program is to implement a circular queue by using a circular doubly-linked list. The
             program allows us to add one number at a time to the queue. The first item goes to the front while the rest
             is added to the back. Each node or number has two pointers that points to the next and the previous node
             which allows us to cycle through the queue. The previous pointer for the front node points to the back end
             of the queue to complete the circle. Also, items can be removed from the front of the queue one at a time.
             Finally, the contents of the queue can be displayed to the screen at any time.

*************************************************************************************************************************/

#pragma once

#include <iostream>
using namespace std;

#ifndef BQUEUE_H
#define BQUEUE_H

class bqnode
{
public:
    int priority; //variable holding the data for each node
    bqnode* prev, * next; //previous and next pointers
};

class bqueue
{
public:
    bqueue(); //default constructor
    ~bqueue(); //destructor
    bqueue(const bqueue&); //copy constructor
    void enqueue(int); //add one to the back of the queue 
    void dequeue(); //removide one from the back of the queue
    bool isEmpty() { return front == 0; } //checks whether the queue is empty or not and returns the bool value
    void print(); //prints the contents of the queue
private:
    bqnode* front;//ONLY one pointer to the front
};

#endif // !BQUEUE_H
