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
	std::string productName;
	double cost;
	int quantity;
};

//function prototypes
//function to display the array with column headings
void displayInventory(Inventory[], int);
//function to sort the array by ID
void sortInventory(Inventory[], int);
//function to sort the array by price
void sortInventoryByPrice(Inventory[], int);
//function to display money in currency format with 2 decimal places
void displayMoney(double);



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
		for (int i = 0; i < 10; i++)
		{
			for (int j = i + 1; j < 10; j++)
			{
				if (inventory[i].inventoryID > inventory[j].inventoryID)
				{
					temp = inventory[i];
					inventory[i] = inventory[j];
					inventory[j] = temp;
				} //end if statement
			} //end for loop
		} //end for loop
	} //end if statement
	else if (choice == 'p')
	{
		//sort the inventory by price
		//create a temporary struct to hold the inventory
		Inventory temp;
		//sort the inventory by price
		for (int i = 0; i < 10; i++)
		{
			for (int j = i + 1; j < 10; j++)
			{
				if (inventory[i].cost > inventory[j].cost)
				{
					temp = inventory[i];
					inventory[i] = inventory[j];
					inventory[j] = temp;
				} //end if statement
			} //end for loop
		} //end for loop
	} //end else if statement
	else
	{
		cout << "";
	} //end else statement
	
	
	//display the inventory
	displayInventory(inventory, 10);
	//Ask the user which item they want to purchase and what quantity; validate that the item number is valid and that there is enough of it in inventory.
	cout << "Which item would you like to purchase? (-1 to stop)\n\n";
	int itemNumber;
	cin >> itemNumber;
	while (itemNumber != -1)
	{
		//validate the item number
		if (itemNumber < 1 || itemNumber > 10)
		{
			cout << "Invalid item number. Please try again.\n\n";
		} //end if statement
		else
		{
			//ask the user how many they want to purchase
			cout << "How many would you like to purchase?\n\n";
			int quantity;
			cin >> quantity;
			//validate the quantity
			if (quantity < 1 || quantity > inventory[itemNumber - 1].quantity)
			{
				cout << "Invalid quantity. Please try again.\n\n";
			} //end if statement
			else
			{
				//subtract the quantity from the inventory
				inventory[itemNumber - 1].quantity -= quantity;
				//display the cost
				cout << "Cost for this item is $" << fixed << setprecision(2) << inventory[itemNumber - 1].cost * quantity << endl;
			} //end else statement
		} //end else statement
		//ask the user which item they want to purchase and what quantity; validate that the item number is valid and that there is enough of it in inventory.
		cout << "Which item would you like to purchase? (-1 to stop) ";
		cin >> itemNumber;
	} //end while loop

	//Display the total cost of all the item purchased
	double totalCost = 0;
	for (int i = 0; i < 10; i++)
	{
		totalCost += inventory[i].cost * (10 - inventory[i].quantity);
	} //end for loop
	cout << "Total cost of all items purchased is $" << fixed << setprecision(2) << totalCost << endl;
	cout << "Thank you for shopping at the Office Supply Store!\n\n";
	system("pause");
	return 0;	
} // end main function

//function to display the array with column headings
void displayInventory(Inventory inventory[], int size)
{
	cout << "Inventory List\n\n";
	cout << "ID\tProduct Name\tCost\tQuantity\n";
	cout << "-------------------------------------------------\n";

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
		for (int i = 0; i < 1; i++)
		{
			cout << inventory[i].inventoryID << "\t" << inventory[i].productName << "\t\t$" << inventory[i].cost << fixed << setprecision(2) << "\t" << inventory[i].quantity << endl;
		} //end for loop
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
		cout << "";
	} //end else statement
	cout << endl;
} //end displayInventory function
