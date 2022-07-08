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

using namespace std;

/************************************************************************************************************************************/
//Name: default constructor
//Precondition: The state of the class has not been initialized
//Postcondition: The state of the class has been initialized
//Decription: Assigns null to the front pointer
/************************************************************************************************************************************/
bqueue::bqueue()
{
    front = 0; 
}


/************************************************************************************************************************************/
//Name: copy constructor
//Precondition: A deep copy has not been made of the class
//Postcondition: A deep copy has been made of the class
//Decription: Makes a deep copy of the class for the new object
/************************************************************************************************************************************/
bqueue::bqueue(const bqueue& org)
{
    bqnode* p = org.front; //let p point to the front of the object accepted as an argument

    do //iterates through the nodes in the linked list
    {
        enqueue(p->priority); //adds the current number from the org object to newly created object
        p = p->next; //point to the next node

    } while (p != org.front); //continue loop until the circle is complete

}


/************************************************************************************************************************************/
//Name: enqueue
//Precondition: the number has not been added to the queue 
//Postcondition: the number has been added to the queue 
//Decription: adds a number to the back of the queue and updates the pointers to maintain the order and circular shape of queue 
/************************************************************************************************************************************/
void bqueue::enqueue(int num)
{
    if (isEmpty()) //adding a node if queue is empty
    {
        front = new bqnode;                 //creating new node
        front->priority = num;              //assigning number to back of queue
        front->prev = front->next = front;  //ensuring that the previous and next pointer all point to front to start the circle
    }
    else if (front == front->next) //adding a node if there is currently a single node in the queue
    {
        front->prev = new bqnode;           //adding node to back
        front->prev->next = front;          //let back of queue point to fron
        front->next = front->prev;          //let front next point to back of queue
        front->next->prev = front;          //let back of queue previous point to front
        front->prev->priority = num;        //assigning number to back of queue
    }
    else //adding a node if there are two are more nodes in the queue
    {
        bqnode* p = front->prev;            //let p point to current back of queue

        front->prev = new bqnode;           //let front previous point to new back of queue 
        front->prev->next = front;          //let back of queue point to the front of queue
        front->prev->prev = p;              //let the current back point to the previous back
        front->prev->prev->next=front->prev; //let the previous back point to the current back
        front->prev->priority = num;        //assigning number to back of queue
    }
}


/************************************************************************************************************************************/
//Name: dequeue
//Precondition: the number has not been removed from the front of the queue
//Postcondition: the number has been removed from the front of the queue
//Decription: removes the node and the number that is located at the front of the queue
/************************************************************************************************************************************/
void bqueue::dequeue()
{
    if (isEmpty()) //checking if queue is empty
    {
        cout << "unable to dequeue, queue is empty\n"; 
    }
    else if (front->prev == front) //checking if there is only one node in the queue
    {
        bqnode* p = front;  //let p poin to front
        front = 0;          //let front point to null
        delete p;           //delete p (former front)
    }
    else //if there is two or more nodes in the queue
    {
        bqnode* p = front;          //let p point to front for later use
        bqnode* q = front->prev;    //let q point to back for later use
        front = front->next;        //let front point to the next node in the queue
        front->prev = q;            //let front previous point to back of queue
        front->prev->next = front;  //let back next point to front of queue
        delete p;
    }
}


/************************************************************************************************************************************/
//Name: print
//Precondition: the contents of the queue has not been printed to the screen
//Postcondition: the contents of the queue has been printed to the screen
//Decription: displays the current contents of the queue to the screen from front to back
/************************************************************************************************************************************/
void bqueue::print()
{
    if (!(isEmpty())) //ensuring that queue is not empty
    {
        bqnode* p = front;
        do    //used to check condition last so the first front is ignored
        {
            cout << p->priority << " "; //print current number
            p = p->next;                //move to the next node

        } while (p != front);           //loop until a complete cycle is done

        cout << endl;
    }
    else
    {
        cout << "queue is empty\n";
    }

}


/****************************************************************************************************************************/
//Name: destructor
//Precondition: memory is still being allocated to the linked list
//Postcondition: memory that was allocated to the linked list has been deallocated and returned to freestore
//Decription: De-allocates all memory allocated to the linked list by deleting all nodes starting from the front of the queue.
//			  This will be the last function to be called (automatically by the compiler) before the program is exited.
/***************************************************************************************************************************/
bqueue::~bqueue()
{
    cout << "\n~QUEUE has been called";
    while (!(isEmpty())) //loop until queue is empty
    {
        dequeue();       //removing all nodes from queue
    }
}