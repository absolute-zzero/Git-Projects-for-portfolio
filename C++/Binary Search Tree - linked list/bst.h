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

#pragma once

#include <string>
using namespace std;

#ifndef bst_H
#define bst_H

class treenode //node in a bst 
{
public:
	string county_name;
	double population_size;
	treenode* lchild, * rchild;		//left and right children pointers
};

class bst
{
public:
	bst();	//store the data file (“county_data.txt”) into initial bst. 
	~bst();		//de-allocates dynamic memory allocated for tree
	bool empty();	//return true if bst is null; otherwise false is retured.
	void insert(const string& item, const double& population);		//auxiliary function.
	void insert(treenode*&, const string& item, const double& population);		//inserts an item into 
              //the bst; this function is invoked, in main, by the auxiliary function described above.
	
	void del_name(string item);		//auxiliary function. 
	void del_name(treenode*& loc_ptr, string item);		//function deletes an item from the bst; this 
                           //function is invoked, in main, by the auxiliary function described above	
	
	treenode* search_tree(string item);		//auxiliary fucntion
	treenode* search_tree(treenode*, string item);		//returns a pointer to the node in bst with a  
                  //county name county name that matches item; this function is invoked, in main, by 
                  //the auxiliary function describes above.
	
	treenode* inorder_succ(treenode*);	//returns a pointer to the inorder successor, based on county name. 

	void county_ranges(const string& min_name, const string& max_name); //auxiliary function.
	void county_ranges(treenode*&, const string& min_name, const string& max_name); //prints all 
							//the county names to the screen that lie between min_name and max_name, 
							//inclusive. 
	
	void print_tree();		//auxiliary function. 
	void print_tree(treenode*&);	//prints each county record to the screen sorted by county name.
	void sorted_info();		//auxiliary function.
	void sorted_info(ostream&, treenode*&);		//prints each county record to a file called “county_info.txt” sorted by county name”.
	void empty_tree();		//de-allocate all nodes that were allocated to the bst


private:
	treenode* root;
	int count=0;
	bool first1 = true;

};


#endif // !bst_H
