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

#include <iostream>
#include "bqueue.h"
#include "bqueue.cpp"


using namespace std; 



int main()
{
    bqueue k;       //defaul constructor for object k called
    cout << "Object K:\n";
    //adding to the front of queue and printing 
    k.print();
    k.enqueue(60);
    k.print();
    k.enqueue(20);
    k.enqueue(30);
    k.print();
    k.enqueue(10);
    k.print();
    k.enqueue(50);
    k.enqueue(40);
    k.print();
    

    cout << "\n\nObject J:\n";
    bqueue j = k;   //copy constructor called for object j and does a deep copy of k

    //removing from the back of queue and printing
    j.print();
    j.dequeue();
    j.print();
    j.dequeue();
    j.dequeue();
    j.dequeue();
    j.print();
    j.dequeue();
    j.dequeue();
    j.print();
    j.dequeue();
    j.dequeue();


    return 0;

}

