//PROGRAM HEADER
/*******************************************************************************************************************************************
Name:  Romari Bartley        Z#: Z23575490
Course: Data Structures and Algorithm Analysis (COP3530)
Professor: Dr. Lofton Bullard
Due Date:  04/27/2021           Due Time: 11:59 PM
Total Points: 25
Assignment #6(module9): bst_driver.cpp

Description: The program uses recursive methods to build a binary search tree using the data stored in a text file. Also, the program can
			 insert or delete from the tree as well as search for a node within the tree given the name of a county. The function county
			 ranges gives the program the ability to list all the names of the county that are within a specified range (For example, 
			 between two letters). This is possible since the tree is sorted in alphabetical order. Additionally, functions such as empty
			 and inorder successor are used as supplementary functions. The empty function checks whether or not the tree is empty while 
			 the inorder successor returns a pointer to the inorder successor of the current. There is an empty tree function which 
			 deallocates all the nodes used for the binary search tree. This funciton was especially helpful when defining the destructor.
			 Finally, there are two functions that handles printing the contents of the binary search tree in order, regardless of its state 
			 (empty, full or otherwise). One of which displays the contents of the tree to the screen while the other writes the contents
			 to a text file.

*******************************************************************************************************************************************/


#include <iostream>
#include <fstream>
#include <string>
#include "bst.h"
#include "bst.cpp"

using namespace std;

//driver 
int main()
{

	cout << "**************************************************************" << endl;
	cout << "Test1: default constuctor" << endl;
	bst  myTree;
	cout << "\nPrint contents of bst inorder to the screen" << endl << endl;
	myTree.print_tree();
	cout << "*************End Test1*****************************************" << endl;
	cout << endl << endl << endl;


	cout << "**************************************************************" << endl;
	cout << "Test2: insert" << endl;
	myTree.insert("New County", 234658);
	cout << endl << "Print contents of bst inorder to the screen" << endl << endl;;
	myTree.print_tree();
	cout << "*************End Test2*****************************************" << endl;
	cout << endl << endl << endl;


	cout << "**************************************************************" << endl;
	cout << "Test3: county_ranges" << endl;
	cout << "Print contents of bst range between B and K inorder to the screen" << endl << endl;;
	myTree.county_ranges("B", "K");
	cout << "*************End Test3*****************************************" << endl;
	cout << endl << endl << endl;


	cout << "**************************************************************" << endl;
	cout << "Test4: del_name" << endl;
	myTree.del_name("Miami Dade");
	cout << endl << "Print contents of bst inorder, with Miami Dade removed, to the screen" << endl << endl;;
	myTree.print_tree();
	cout << "*************End Test4*****************************************" << endl;
	cout << endl << endl << endl;


	cout << "**************************************************************" << endl;
	cout << "Test5: sorted_info" << endl << endl;
	cout << "Print contents of bst inorder to the output file, county_info.txt, with name and associated population size shown" << endl << endl;
	myTree.sorted_info();
	cout << "*************End Test5*****************************************" << endl;
	cout << endl << endl << endl;


	cout << "**************************************************************" << endl;
	cout << "Test6: empty_tree" << endl << endl;
	myTree.empty_tree();
	cout << endl << "Print contents of an empty bst to the screen" << endl << endl;;
	myTree.print_tree();
	cout << "*************End Test6*****************************************" << endl;
	cout << endl << endl <<endl;

	return 0;
}


