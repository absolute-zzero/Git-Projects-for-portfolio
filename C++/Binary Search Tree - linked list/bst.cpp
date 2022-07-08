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
#include <iomanip>
#include "bst.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: default constructor
//Precondition: Constructor has not been invoked.
//Postcondition: The binary search tree has been initialized with data that lies within the file
//				 county_data.txt
//Description: This function builds a binary search tree with the data that is within an input 
//			   file by sorting the data as it is being inserted within the tree
///////////////////////////////////////////////////////////////////////////////////////////////
bst::bst() 
{
	ifstream in;
	string line;
	string county;
	double popu=0;
	bool first=true;

	in.open("county_data.txt");		//opening file

	if (in.fail())	//testing to see if file opened correctly 
	{
		cout << "file did not open correctly";
	}
	else
	{
		while (!in.eof())	//loop until the end of file is read 
		{
			first = true;

			getline(in, line);		//reading line by line    

			for (unsigned int i = 0; i < line.length(); i++)	//checking all characters within the string read
			{
				//checking if a space is read and the next character is a digit and checking if it's the first time
				if  (line[i] == ' ' && isdigit(line[i+1]) && first==true)	
				{
					county = line.substr(0, i);		//storing the county by using substring 
					popu = stod(line.substr(i + 1, line.length()));		//storing the population by using substring

					first = false;	//changing first to false to keep check of whether it's the first time a space was found
				}

			}

			//printing unordered list of counties with their respective population 
			cout << right << setw(13) << county << "\t\t";	
			cout << right << setw(10) <<  int(popu) <<endl; 

			insert(county, popu);	//inserting current county and population
			
		}
	}
	in.close();	//closing file
}


///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: empty
//Precondition: bool has not been returned
//Postcondition: the result has been returned as a bool
//Description: checks whether or not the root is pointing to null.
///////////////////////////////////////////////////////////////////////////////////////////////
bool bst::empty()
{
	return (root == 0);	//returning bool result of empty
}


///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: insert
//Precondition: item and population has not been initialized
//Postcondition: item and population has been initialized
//Description: calls the overloaded insert function so that the main driver is not restricted
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::insert(const string& item, const double& population)
{
	insert(root, item, population);	//auxillary calling primary function
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: insert
//Precondition: root, item and population has not been initialized
//Postcondition: root, item and population has been initialized
//Description: inserts treenode within the tree to keep the order while assigning county name
//			   and population
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::insert(treenode*& root, const string& item, const double& population)
{
	if (root == 0)	//checking if tree is empty
	{
		root = new treenode;	//creating new node
		root->lchild = root->rchild = 0;	//setting left and right child to null
		root->county_name = item;	//assigning county name
		root->population_size = population;		//assigning population
	}
	else if (root->county_name > item)		//checking if item is less than the current root
		insert(root->lchild, item, population);		//inserting item to the left recursively
	else if (root->county_name < item)		//checking if item is greater than the current root
		insert(root->rchild, item, population);		//inserting item to the right recursively
	else
		cout << "the item is already in the tree\n";	//informing user that item is already within the tree
}


///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: search_tree
//Precondition: item has not been initialized
//Postcondition: item has been initialized
//Description: calls the overloaded search tree function so that the main driver is not restricted
///////////////////////////////////////////////////////////////////////////////////////////////
treenode* bst::search_tree(string item)
{
	return search_tree(root, item);		//auxillary function calling primary function
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: search_tree
//Precondition: location pointer and item has not been initialized
//Postcondition: location pointer and item has been initialized
//Description: searches the tree and returns a pointer to the location of a node that contains
//			   a given county name
///////////////////////////////////////////////////////////////////////////////////////////////
treenode* bst::search_tree(treenode* loc_ptr, string item)
{
	if (root != 0)	//checking if the pointer is currently pointing to null
	{
		if (root->county_name == item)		//checking if the pointer is currently pointing to the item
			return root;
		else if (root->county_name > item)	//checking if the current county name is greater than the item
			return search_tree(root->lchild, item);		//calling the function recursively with the left child
		else
			return search_tree(root->rchild, item);		//calling the function recursively with the right child
	}
	else
		return root;
}


///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: del_name
//Precondition: item has not been initialized
//Postcondition: item has been initialized
//Description: calls the overloaded del_name function so that the main driver is not restricted
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::del_name(string item)
{
	del_name(root, item);	//auxillary function calling primary function
}


///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: del_name
//Precondition: root and item has not been initialized
//Postcondition: root and item has been initialized
//Description: deletes the node that contains a given county name. Also rearranges the binary
//			   to keep the order if necessary
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::del_name(treenode*& root, string item)
{	
	if (root == 0)	//checking if tree is empty
		cout << "item not in tree\n";

	else if (root->county_name > item)	//checking if the county name is greater than item 
		del_name(root->lchild, item);	//calling the function recursively with the left child    

	else if (root->county_name < item)	//checking if the county name is less then item
		del_name(root->rchild, item);	//calling the function recursively with the right child

	else
	{
		treenode* ptr;

		if (root->lchild == 0)	//checking if the left child of the current node is pointing to null
		{
			ptr = root->rchild;	//set the new pointer to point to the right child of the current node
			delete root;	//deleting the current node
			root = ptr;	//set pointer of the current location to point to the right child as a replacement for the current node
		}
		else if (root->rchild == 0)	//checking if the right child of the current node is pointing to null
		{
			ptr = root->lchild;	//set the new pointer to point to the left child of the current node
			delete root;	//deleting the current node
			root = ptr;	//set pointer of the current location to point to the left child as a replacement for the current node
		}
		else//if there is a left and a right child for the current node
		{
			ptr = inorder_succ(root);	//let the pointer point to the inorder successor of the current node
			root->county_name = ptr->county_name;	//assigning the county name of the inorder successor to the current node
			root->population_size = ptr->population_size;	//assigning the population size of the inorder successor to the current node
			del_name(root->rchild, ptr->county_name);	//recursive call of the right child of current node
		}
	}

}


///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: inorder_succ
//Precondition: location pointer has not been initialized
//Postcondition: location pointer has been initialized
//Description: searches for the left most child of the right child of the current node and 
//			   returns a pointer to the node that was founded
///////////////////////////////////////////////////////////////////////////////////////////////
treenode* bst::inorder_succ(treenode* loc_ptr)
{
	treenode* ptr = root->rchild;	//pointing to the right child of root

	while (ptr->lchild != 0)	//loop until the left most node on the right side is identified
	{
		ptr = ptr->lchild;	//continuosly pointing to the left child
	}
	return ptr;	
}


///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: print_tree
//Precondition: the primary function has not been called 
//Postcondition: the primary function has been called 
//Description: calls the overloaded print_tree function so that the main driver is not restricted
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::print_tree()
{
	print_tree(root);	//auxillary function calling primary function
}


///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: print_tree
//Precondition: the root has not been initialized
//Postcondition: the root has been initialized
//Description: displays the county name and population size of each node that is within the tree
//			   in alphabetical order 
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::print_tree(treenode*& root)
{
	if (root != 0)	//checking if current node is pointing to null
	{
		print_tree(root->lchild);	//printing all left nodes starting from the left most
		cout << right << setw(13) <<root->county_name << "\t\t";	//printing county name of current root
		cout << int(root->population_size) << endl;		//printing population size of current root
		print_tree(root->rchild);	//printing all the right nodes starting from the left most
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: county_ranges
//Precondition: min_name and max_name has not been initialized 
//Postcondition: min_name and max_name has been initialized 
//Description: calls the overloaded county_ranges function so that the main driver is not restricted
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::county_ranges(const string& min_name, const string& max_name)
{
	county_ranges(root, min_name, max_name);	//auxillary function calling primary function
}


///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: county_ranges
//Precondition: root, min_name and max_name has not been initialized 
//Postcondition: root, min_name and max_name has been initialized 
//Description: prints the contents of the nodes that has their county's name within the given range
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::county_ranges(treenode*& root, const string& min_name, const string& max_name)
{
	if (root!=0)
	{
		if (root->county_name >= min_name)
		{
			county_ranges(root->lchild, min_name, max_name); //moving to the left until the min is realized
		}

		if (root->county_name <= max_name)
		{
			if (root->county_name > min_name && root->county_name <= max_name)	//defining range
			{
				cout << right << setw(14) << root->county_name << "\t\t";	
				cout << int(root->population_size) << endl;
			}
			
			county_ranges(root->rchild, min_name, max_name);	
		}
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: sorted_info
//Precondition: the primary function has not been called
//Postcondition: the primary function has been called
//Description: Opens an output file stream and then calls the overloaded sorted_info function 
//			   so that the main driver is not restricted. And then closes the output file
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::sorted_info()
{
	ofstream out;	//output file stream
	out.open("county_info.txt");	//opening file

	if (out.fail())	//checking if file opened correctly
	{
		cout << "File did not open properly";
	}
	else
	{
		sorted_info(out, root);	//auxillary function calling primary function
	}

	out.close();	//closing file
	

}//auxiliary function.


 ///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: sorted_info
//Precondition: the ostream (out) and the treenode pointer (root) has not been initialized
//Postcondition: the ostream (out) and the treenode pointer (root) has been initialized
//Description: writes all the contents of the binary search tree inorder to an output file. 
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::sorted_info(ostream& out, treenode*& root)
{
	if (root != 0)
	{
		sorted_info(out,root->lchild);	//printing contents of nodes on the left starting from the left most 
		out << right << setw(13) << root->county_name << "\t\t\t";	//printing county name for current root
		out << int(root->population_size) << endl;	//printing population size for current root
		sorted_info(out,root->rchild);	//printing contents of nodes on the right starting from the left most
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: empty_tree
//Precondition: the nodes within the binary search tree has not been deleted
//Postcondition: the nodes within the binary search tree has been deleted
//Description: deletes all the nodes that were being used for the binary search tree
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::empty_tree()
{
	while (root != 0) //loop until tree is empty
	{
		del_name(root->county_name);	//deleting all nodes
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: destructor
//Precondition: the dynamic memory that has been allocated to the binary search tree has not 
//				been deallocated
//Postcondition: the dynamic memory that has been allocated to the binary search tree has 
//				 been deallocated
//Description: deallocates all the memory that has been allocated to the binary search tree 
//			   throughout the program
///////////////////////////////////////////////////////////////////////////////////////////////
bst::~bst()
{
	empty_tree();	//calling empty tree to deallocate
}





