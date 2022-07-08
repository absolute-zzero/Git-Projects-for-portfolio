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
#include <fstream>
#include <iomanip>
#include "order_class.h"
#include "order_class.cpp"

using namespace std;


//Here is your driver to test the program
int main()
{
	order_class myOrders;//declaring order_class object myOrders; the default constructor is called automically.
	cout << "********************************************************************************************\n\n";

	//Test 1:
	cout << "Test 1: Testing default construcor, double_size, process, is_full and operator<< " << endl;
	myOrders.process();
	cout << myOrders;
	cout << "End of Test 1" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n\n\n\n";


	//Test 2:
	//void add();
	cout << "Test 2: Testing add, double_size, process, is_full, and operator<< " << endl;
	myOrders.add();//test case: pname = rose, cname = dade, plant cost = 1, quantity = 1 
	cout << myOrders;
	cout << "End of Test 2" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n\n\n\n";


	//Test 3:
	//operator-(string key);
	cout << "Test 3: Testing operator-, is_Empty, search and opertor<< " << endl;
	cout << "\nRemoving rose\n";
	myOrders - "rose";
	cout << myOrders;
	cout << "\nRemoving bergenia and yarrow\n";
	myOrders - "bergenia" - "yarrow";
	cout << myOrders;
	cout << "\nRemoving rose ---AGAIN--- SHOULD GET MESSAGE\n";
	myOrders - "rose";
	cout << myOrders;
	cout << "End of Test 3" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n\n\n\n";


	//Test 4:
	//copy constructor
	cout << "Test4: Testing copy constructor\n";
	order_class yourOrders = myOrders;
	cout << yourOrders << endl;
	cout << "End of Test 4" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n\n\n";


	//Test 5:
	//destructor will be invoked when object myOrders goes out of scope
	cout << "Test 4: Destructor called" << endl;
	cout << "End of Test 5" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n\n";
	return 0;
}