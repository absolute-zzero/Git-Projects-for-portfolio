//PROGRAM HEADER
/************************************************************************************************************************

Name:  Romari Bartley        Z#: Z23575490
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:  03/01/2021           Due Time: 11:59 PM
Total Points: 20
Assignment #: nursery_porder11.cpp

Description: This program consists of an order class (order_class) which handles the organization, calculations and operations
			 of another class known as order record (order_record). The order class converts STR (of type order_record) into a
dynamic array. This allows STR to read all the plant purchase data for each plant from an input file. After this, the data is
used to calculate the net cost, tax rate, discount_rate, discount, order tax and total cost for every order that was read into
STR from the file. Furthermore, the program also consists of features such as adding a record and removing records which share
the same plant name. The "-" operator is overloaded and is used to invoke the function that removes. Also, this program prints
the entire contents of the dynamic array (STR) to the screen after initialization. The program also prints the records to the
screen after each operation is carried out such as a removal or addition of a record or records. The function for printing is
created by overloading the "<<" operator. Finally, the program was seperated so that there are three different files to be
compiled. These files include the header file (order_class.h), the functions definition file (order_class.cpp) and the driver
file (nursery_porder11.cpp). The header file contained the the classes of order_record and order_class, the order_class.cpp
file contained all function definitions and the driver file was responsible for calling all the necessary functions.

*************************************************************************************************************************/

#pragma once

#include <iostream>
using namespace std;

#ifndef ORDER_RECORD_H
#define ORDER_RECORD_H
class order_record
{
public:
	string pname;
	string cname;
	double plant_cost;
	int quantity;
	double tax_rate;
	double net_cost;
	double discount_rate;
	double discount;
	double purchase_tax;
	double total_cost;

	void calc_discountRate() // member function to calculate discount rate
	{
		//conditions to decide discount rate
		if (quantity <= 0)
			discount_rate = 0;
		else if (quantity >= 1 && quantity <= 6)
			discount_rate = .02;
		else if (quantity >= 7 && quantity <= 13)
			discount_rate = .04;
		else if (quantity >= 14 && quantity <= 25)
			discount_rate = .07;
		else if (quantity >= 26 && quantity <= 60)
			discount_rate = .09;
		else
			discount_rate = .14;
	}

	void calc_taxRate() //member function to calculate tax rate
	{
		//conditions to decide tax rate
		if (cname == "dade" || cname == "Dade" || cname == "DADE")
			tax_rate = .055;
		else if (cname == "broward")
			tax_rate = .05;
		else if (cname == "palm")
			tax_rate = .06;
		else
		{
			cout << "Error - In proper County Name\n" << endl;
			exit(1);
		}
	}
};
#endif // !ORDER_RECORD_H



#ifndef ORDER_CLASS_H
#define ORDER_CLASS_H
class order_class
{
public:
	order_class(); //default constructor
	order_class(const order_class& org); //copy constructor
	~order_class(); //de-allocates all memory allocate to STR by operator new.
	bool is_Empty(); //inline implementation
	bool is_full();//inline implementation
	int search(const string key);//returns location of key if in STR; otherwise return -1
	void add(); //adds a order record to STR
	order_class& operator-(const string key); //removes all items in STR with a plant name that matches key.
	void double_size(); //double the size of the dynamic array
	void process(); //calculates all the costs for each of the plant's order record 
	friend ostream& operator<<(ostream& out, order_class& ORG); //prints all the elements in ORG's STR to the screen
private:
	int count; //
	int size;
	order_record* STR;
};
#endif // !ORDER_CLASS_H

