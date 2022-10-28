// officeSupplyStoreInventory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
//Create a project that simulates an office supply store with inventory
//need an array of structs or class objects to store the inventory; read the inventory from inventory.txt to store in that array
//The file has the inventory ID, product name, cost, and quantity on a single line for each item; there are 10 items in this inventory file


//create a struct to store the inventory
struct Inventory
{
	int inventoryID;
	string productName;
	double cost;
	int quantity;
};

//function prototypes
//function to display the array with column headings
void displayInventory(Inventory[], int);
//function to sort the array by ID
void sortID(Inventory[], int);
//function to sort the array by cost
void sortCost(Inventory[], int);




char choice;

int main()
{
    cout << "SDEV 2310 Final Project by Kevin Bell\n\n";
	cout << "Do you want to view the inventory sorted by ID (d) or price (p)? ";
	cin >> choice;
	cout << endl;
	//create an array of structs to store the inventory
	Inventory inventory[10];
	//create a file object to read the inventory from the file
	ifstream inventoryFile;
	//open the file
	inventoryFile.open("inventory.txt");
	//read the inventory from the file
	for (int i = 0; i < 10; i++)
	{
		inventoryFile >> inventory[i].inventoryID >> inventory[i].productName >> inventory[i].cost >> inventory[i].quantity;
	} //end for loop
	//close the file
	inventoryFile.close();

	//determine how to sort the inventory using if else statement
	if (choice == 'd')
	{
		//sort the inventory by ID
		//create a temporary struct to hold the inventory
		Inventory temp;
		//sort the inventory by ID
		sortID(inventory, 10);
	} //end if statement
	else if (choice == 'p')
	{
		//sort the inventory by price
		//create a temporary struct to hold the inventory
		Inventory temp;
		//sort the inventory by price
		sortCost(inventory, 10);
	} //end else if statement
	else
	{
		// do not sort the inventory
	} //end else statement
	
	
	//display the inventory
	displayInventory(inventory, 10);
	cout << "Which item would you like to purchase? (-1 to stop) ";
	// search for the item the user wants to purchase
	int item;
	cin >> item;
	double runningTotal = 0;
	while (item != -1)
	{
		//search for the item
		for (int i = 0; i < 10; i++)
		{
			if (inventory[i].inventoryID == item)
			{
				//display the item
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
					cout << "Cost for all those items: $" << total << endl;
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
		cout << "Total cost of all items purchased: $" << runningTotal << endl;
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

	if (choice == 'd')
	{
		for (int i = 0; i < 6; i++)
		{
			cout << inventory[i].inventoryID << "\t" << inventory[i].productName << "\t\t$" << inventory[i].cost << fixed << setprecision(2) << "\t" << inventory[i].quantity << endl;
		} //end for loop
		for (int i = 6; i < 9; i++)
		{
			cout << inventory[i].inventoryID << "\t" << inventory[i].productName << "\t$" << inventory[i].cost << fixed << setprecision(2) << "\t" << inventory[i].quantity << endl;
		} //end for loop
		cout << inventory[9].inventoryID << "\t" << inventory[9].productName << "\t\t$" << inventory[9].cost << fixed << setprecision(2) << "\t" << inventory[9].quantity << endl;
	} //end if statement
	else if (choice == 'p')
	{
		// for the first item in the array add a zero to the cost
		cout << inventory[0].inventoryID << "\t" << inventory[0].productName << "\t\t$" << inventory[0].cost << fixed << setprecision(2) << "0" << "\t" << inventory[0].quantity << endl;
		for (int i = 1; i < 5; i++)
		{
			cout << inventory[i].inventoryID << "\t" << inventory[i].productName << "\t\t$" << inventory[i].cost << fixed << setprecision(2) << "\t" << inventory[i].quantity << endl;
		} //end for loop
		for (int i = 5; i < 6; i++)
		{
			cout << inventory[i].inventoryID << "\t" << inventory[i].productName << "\t$" << inventory[i].cost << fixed << setprecision(2) << "\t" << inventory[i].quantity << endl;
		} //end for loop
		for (int i = 6; i < 7; i++)
		{
			cout << inventory[i].inventoryID << "\t" << inventory[i].productName << "\t\t$" << inventory[i].cost << fixed << setprecision(2) << "\t" << inventory[i].quantity << endl;
		} //end for loop
		for (int i = 7; i < 8; i++)
		{
			cout << inventory[i].inventoryID << "\t" << inventory[i].productName << "\t$" << inventory[i].cost << fixed << setprecision(2) << "\t" << inventory[i].quantity << endl;
		} //end for loop
		for (int i = 8; i < 9; i++)
		{
			cout << inventory[i].inventoryID << "\t" << inventory[i].productName << "\t\t$" << inventory[i].cost << fixed << setprecision(2) << "\t" << inventory[i].quantity << endl;
		} //end for loop
		cout << inventory[9].inventoryID << "\t" << inventory[9].productName << "\t$" << inventory[9].cost << fixed << setprecision(2) << "\t" << inventory[9].quantity << endl;
	} //end else if statement
	else
	{
		// do not sort the inventory, just display it
		for (int i = 0; i < 6; i++)
		{
			cout << inventory[i].inventoryID << "\t" << inventory[i].productName << "\t\t$" << inventory[i].cost << fixed << setprecision(2) << "\t" << inventory[i].quantity << endl;
		} //end for loop
		for (int i = 6; i < 9; i++)
		{
			cout << inventory[i].inventoryID << "\t" << inventory[i].productName << "\t$" << inventory[i].cost << fixed << setprecision(2) << "\t" << inventory[i].quantity << endl;
		} //end for loop
		cout << inventory[9].inventoryID << "\t" << inventory[9].productName << "\t\t$" << inventory[9].cost << fixed << setprecision(2) << "\t" << inventory[9].quantity << endl;
	} //end else statement
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
