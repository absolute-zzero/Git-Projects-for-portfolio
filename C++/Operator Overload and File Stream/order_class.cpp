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


#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#include "order_class.h"
using namespace std;


/************************************************************************************************************************************/
//Name: default constructor
//Precondition: The state of the class has not been initialized
//Postcondition: The state of the class has been initialized
//Decription: Reads the data file of purchase order information (plant name, county name, plant cost and quantity) into the dynamic array of order records, 
//STR. If the count become equal to the size the function double_size is called and the memory allocated to STR is doubled.
/************************************************************************************************************************************/
order_class::order_class()
{
	//initialization
	size = 1;
	count = 0;
	STR = new order_record[size];

	ifstream in; //input file stream
	in.open("nursery_stock.txt"); //opening input file

	if (in.fail()) //checking whether input file was open properly
	{
		cout << "Input file did not open correctly";
	}
	else
	{
		while (!in.eof()) //loop until end of file is read
		{
			if (is_full()) //checking if array is full
			{
				double_size(); //doubling the size of the array
			}

			//sending plant data from file to the dynamic array STR
			in >> STR[count].pname;
			in >> STR[count].cname;
			in >> STR[count].plant_cost;
			in >> STR[count].quantity;

			count++; //increment count after each record is read 
		}
	}

	in.close(); //closing input file

	cout << "The default constructor has been called\n";

}


/************************************************************************************************************************************/
//Name: copy constructor
//Precondition: A deep copy has not been made of the order class
//Postcondition: A deep copy has been made of the order class 
//Description:  The function performs a deep copy of the formal parameter org. 
//
/************************************************************************************************************************************/
order_class::order_class(const order_class& org)
{
	(*this).size = org.size;
	this->count = org.count;

	STR = new order_record[size];

	for (int i = 0; i < count; i++)
	{
		STR[i] = org.STR[i];
	}

}


/***********************************************************************************************************************************/
//Name: is_Empty
//Precondition: count has not been compared with zero
//Postcondition: the result of the comparison has been returned as bool 
//Decription: returns true if STR is empty
/**********************************************************************************************************************************/
bool order_class::is_Empty()
{
	return count == 0;
}

/**********************************************************************************************************************************/
//Name: is_full 
//Precondition: count has not been compared with size
//Postcondition: the result of the comparizon has been returned as a bool value
//Decription: returns true if STR is full
/*********************************************************************************************************************************/
bool order_class::is_full()
{
	return count == size;
}

/**********************************************************************************************************************************/
//Name: search
//Precondition: key has not been initialized
//Postcondition: key has been initialized
//Decription: locates key in STR if it is there; otherwise -1 is returned
/*********************************************************************************************************************************/
int order_class::search(const string key)
{
	if (!is_Empty())//checking if array is empty
	{
		for (int i = 0; i < count; i++) //loop to go through each purchase record within the array
		{
			if (STR[i].pname == key) //checking to see if the current plant name is equal to the current key
			{
				return i; //returning the index of the first key found
			}
		}
	}

	return -1;
}

/*********************************************************************************************************************************/
//Name: add
//Precondition: new plant purchase record is yet to be added 
//Postcondition: new plant purchase record has been added
//Decription: adds a order_record to STR; if STR is full, double_size is called to increase the size of STR. The user 
//            is prompted to enter the plant name, county name, plant cost and quantity.
/********************************************************************************************************************************/
void order_class::add()
{
	if (is_full()) //checking if array is full
	{
		double_size();
	}

	//prompting user for information on the plant to be added
	cout << endl << "Enter plant name: ";
	cin >> STR[count].pname;

	cout << endl << "Enter county name: ";
	cin >> STR[count].cname;

	cout << endl << "Enter plant cost: ";
	cin >> STR[count].plant_cost;

	cout << endl << "Enter quantity: ";
	cin >> STR[count].quantity;

	//Calculating cost for new plant that was added  
	STR[count].net_cost = STR[count].quantity * STR[count].plant_cost; //net cost calculation

	//discount rate calculation
	if (STR[count].quantity <= 0)
		STR[count].discount_rate = 0;
	else if (STR[count].quantity >= 1 && STR[count].quantity <= 6)
		STR[count].discount_rate = .02;
	else if (STR[count].quantity >= 7 && STR[count].quantity <= 13)
		STR[count].discount_rate = .04;
	else if (STR[count].quantity >= 14 && STR[count].quantity <= 25)
		STR[count].discount_rate = .07;
	else if (STR[count].quantity >= 26 && STR[count].quantity <= 60)
		STR[count].discount_rate = .09;
	else
		STR[count].discount_rate = .14;

	//tax calculation
	if (STR[count].cname == "dade" || STR[count].cname == "Dade" || STR[count].cname == "DADE") //condition to decide tax rate
		STR[count].tax_rate = .055;
	else if (STR[count].cname == "broward")
		STR[count].tax_rate = .05;
	else if (STR[count].cname == "palm")
		STR[count].tax_rate = .06;
	else
	{
		cout << "Error - In proper County Name\n" << endl;
		exit(1);
	}

	STR[count].purchase_tax = STR[count].net_cost * STR[count].tax_rate; //Calculations for purchase tax
	STR[count].discount = STR[count].net_cost * STR[count].discount_rate; //Calculations for discount
	STR[count].total_cost = STR[count].net_cost + STR[count].purchase_tax - STR[count].discount; //Calculations for total cost

	count++;
}

/********************************************************************************************************************************/
//Name: operator-
//Precondition: key has not been initialized
//Postcondition: key has been initialized
//Decription: removes all order records in STR with a plant name field that matches key, if it is there.
/*******************************************************************************************************************************/
order_class& order_class::operator-(const string key)
{
	int rem = search(key); //assigning the index of the key plant name to the variable rem 
	int freq = 0;
	int cnt = 0;

	if (rem != -1) //checking if key was found 
	{
		for (int i = 0; i < count; i++) //loop to check how many plants in the array matches the key
		{
			if (STR[i].pname == key)
			{
				cnt++;
			}
		}

		while (freq < cnt) //loop to decide how many times will the array be arranged 
		{
			//loop to rearrange array so that the correct plant record is deleted
			for (int j = rem; j < count - 1; j++)
			{
				STR[j] = STR[j + 1];
			}
			count--;

			//calling the funstion again to search for the next key 
			rem = search(key);
			freq++;
		}
	}
	else
	{
		cout << "There is no record with the name of this plant\n";
	}

	return *this; //returning the current object
}

/******************************************************************************************************************************/
//Name: double_size
//Precondition: current size of the dynamic array has not been doubled
//Postcondition: size of the dynamic array has been doubled 
//Decription: doubles the size (capacity) of STR
/******************************************************************************************************************************/
void order_class::double_size()
{
	size *= 2; //doubling the size
	order_record* temp = new order_record[size]; //creating a dynamic array

	for (int i = 0; i < count; i++)
	{
		temp[i] = STR[i]; //storing the records in a temporary array that has twice the capacity
	}

	delete[] STR; 
	STR = temp; 
}


/******************************************************************************************************************************/
//Name: process
//Precondition: the costs for the initial plant purchases have not been calculated 
//Postcondition: the costs for the initial plant purchases have been calculated
//Decription: calculate the net cost, tax rate, order tax, discount and total cost for every order record in STR. for every call record in STR.
/*****************************************************************************************************************************/
void order_class::process()
{
	for (int i = 0; i < count; i++) //loop to iterate through the order record array
	{
		//calculations for plants purchased
		STR[i].net_cost = STR[i].quantity * STR[i].plant_cost; //Calculation for net cost

		STR[i].calc_discountRate(); //funnction to calculate discount rate (discount_rate)

		STR[i].calc_taxRate(); //function to calculate tax rate (tax_rate)

		STR[i].purchase_tax = STR[i].net_cost * STR[i].tax_rate; //Calculations for purchase tax

		STR[i].discount = STR[i].net_cost * STR[i].discount_rate; //Calculations for discount

		STR[i].total_cost = STR[i].net_cost + STR[i].purchase_tax - STR[i].discount; //Calculations for total cost
	}
}


/****************************************************************************************************************************/
//Name: operator<<
//Precondition: out (ostream) and org (order class) has not been initialized 
//Postcondition: out (ostream) and org (order class) has been initialized 
//Decription: prints every field of every call_record in STR formatted to a file and return the stream.
/***************************************************************************************************************************/
ostream& operator<<(ostream& out, order_class& org)
{

	static int run = 1;

	//formatting file output
	out.setf(ios::showpoint);
	out.setf(ios::fixed);
	out.precision(2);


	out << endl;
	for (int i = 0; i < org.count; i++)
	{
		//printing data from order record to file
		out << left << setw(15) << org.STR[i].pname
			<< left << setw(9) << org.STR[i].cname
			<< right << setw(7) << org.STR[i].plant_cost
			<< right << setw(6) << org.STR[i].quantity;

		out.precision(1);
		if (org.STR[i].cname == "dade") //condition to check whether or not the decimal point need to be shown for tax rate
			out << right << setw(6) << org.STR[i].tax_rate * 100 << "%";
		else
			out << right << setw(6) << int(org.STR[i].tax_rate * 100) << "%";

		out.precision(2);
		out << right << setw(10) << org.STR[i].net_cost
			<< right << setw(5) << int(org.STR[i].discount_rate * 100) << "%"
			<< right << setw(9) << org.STR[i].discount
			<< right << setw(8) << org.STR[i].purchase_tax
			<< right << setw(9) << org.STR[i].total_cost << endl;
	}


	out << "\t\t\t******************************\n";
	out << "\t\t\t*********end of run " << run << "*********" << endl;
	out << "\t\t\t******************************\n";
	run++;
	return out;//returning object that invoked the function
}

/****************************************************************************************************************************/
//Name: destructor
//Precondition: memory is still being allocated to STR
//Postcondition: memory that was allocated to STR has been deallocated and returned to freestore
//Decription: de-allocates all memory allocated to STR.  This will be the last function to be called (automatically by the compiler)
//before the program is exited.
/***************************************************************************************************************************/
order_class::~order_class()
{
	delete[] STR; //deleting memory allocated to STR
	cout << "The destructor has been called\n";
}