// officeSupplyStoreInventory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

struct Inventory
{
	int inventoryID;
	string productName;
	double cost;
	int quantity;
};

//function prototypes
void displayInventory(Inventory[], int);
void sortID(Inventory[], int);
void sortCost(Inventory[], int);
string dollarFormat(string);
string dollarFormat(double);

char choice;

int main()
{
    cout << "SDEV 2310 Final Project by Kevin Bell\n\n";
	cout << "Do you want to view the inventory sorted by ID (d) or price (p)? ";
	cin >> choice;
	cout << endl;
	//array of structs
	Inventory inventory[10];
	//file object
	ifstream inventoryFile;
	inventoryFile.open("inventory.txt");
	//read the inventory from the file
	for (int i = 0; i < 10; i++)
	{
		inventoryFile >> inventory[i].inventoryID >> inventory[i].productName >> inventory[i].cost >> inventory[i].quantity;
	} //end for loop
	//close the file
	inventoryFile.close();

	//sort the inventory 
	if (choice == 'd')
	{
		//sort the inventory by ID
		Inventory temp;
		sortID(inventory, 10);
	} //end if statement
	else if (choice == 'p')
	{
		//sort the inventory by price
		Inventory temp;
		sortCost(inventory, 10);
	} //end else if statement
	else
	{
		// do not sort the inventory
	} //end else statement
	
	
	//display the inventory
	displayInventory(inventory, 10);

	
	cout << "Which item would you like to purchase? (-1 to stop) ";
	// search for item user wants
	int item;
	cin >> item;
	double runningTotal = 0;
	while (item != -1)
	{
		//search for item
		for (int i = 0; i < 10; i++)
		{
			if (inventory[i].inventoryID == item)
			{
				//display item
				cout << "Item " << inventory[i].productName << ": " << "How many would you like to purchase? ";
				int quantity;
				cin >> quantity;
				//make sure user input is not less than -1
				while (quantity < -1)
				{
					cout << "Invalid quantity. Please enter a quantity greater than or equal to 1: ";
					cin >> quantity;
				} //end while loop
				//check to see if there is enough in stock
				if (quantity > inventory[i].quantity)
				{
					cout << "Sorry, we do not have that many in stock.\n\n";
				} //end if statement
				else
				{
					//update the quantity
					inventory[i].quantity -= quantity;
					//display the total
					double total = inventory[i].cost * quantity;
					cout << "Cost for all those items: $" << fixed << setprecision(2) << total << endl;
					// add total to the running total
					
					runningTotal += total;
					
					cout << endl;
				} //end else statement
			} //end if statement
		} //end for loop
		cout << "Which item would you like to purchase? (-1 to stop) ";
		cin >> item;
	} //end while loop


	if (runningTotal > 0)
	{
		//Display the running total
		cout << "Total cost of all items purchased: " << dollarFormat(runningTotal) << endl;
	} //end if statement
	else
	{
		//do nothing
	} //end else statement
	


	cout << "Thank you for shopping at the Office Supply Store!\n\n";
	system("pause");
	return 0;

		
} // end main function

//function to display the array with column headings
void displayInventory(Inventory inventory[], int size)
{
	cout << "Inventory List\n\n";
	cout << "ID\tProduct Name\tCost\tQuantity\n";
	cout << "-----------------------------------------\n";
	int k = 0;
	//use setw to format the output
		for (k = 0; k < size; k++)
		{
			cout << setw(6) << inventory[k].inventoryID;
			cout << setw(12) << inventory[k].productName << "     ";
			cout << setw(6) << dollarFormat(inventory[k].cost);
			cout << setw(6) << inventory[k].quantity << endl;
		} //end for loop
	cout << endl;
} //end displayInventory function

//function to sort the array by ID
void sortID(Inventory inventory[], int size)
{
	Inventory temp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (inventory[i].inventoryID > inventory
				[j].inventoryID)
			{
				temp = inventory[i];
				inventory[i] = inventory[j];
				inventory[j] = temp;
			} //end if statement
		} //end for loop
	} //end for loop
} //end sortID function

//function to sort the array by cost
void sortCost(Inventory inventory[], int size)
{
	Inventory temp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (inventory[i].cost > inventory[j].cost)
			{
				temp = inventory[i];
				inventory[i] = inventory[j];
				inventory[j] = temp;
			} //end if statement
		} //end for loop
	} //end for loop
} //end sortCost function

//**************************************************************
// Returns a $-formatted version of the input string.          *
//**************************************************************
string dollarFormat(string original)
{
	string formatted = original; // formatted string to return
	int decimalPos = formatted.find('.'); // position of decimal
	int pos = decimalPos; // position to insert commas

	while (pos > 3) // insert commas until pos is less than 3
	{
		pos -= 3; // move pos back 3 spaces
		formatted.insert(pos, ","); // insert comma
	} // end while loop
	formatted.insert(0, "$"); // insert dollar sign
	return formatted; // return formatted string
} // end dollarFormat


//**************************************************************
// Returns a $-formatted version of the input double.          *
//**************************************************************
string dollarFormat(double value) {

	//creat ostringstream oject
	ostringstream ostr;

	//set format flags
	ostr << fixed << setprecision(2);

	//insert value into stream
	ostr << value;

	//return formatted string
	return dollarFormat(ostr.str());
} // end dollarFormat
