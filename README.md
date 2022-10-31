# officeSupplyStoreInventoryFinalProjectCplusPlus1

C++ Final Project

This final project demonstrates your competency in skills learned in this course. You must complete this exercise on your own, without any help from an instructor or another student. If you get stuck, go back through the relevant sections in the book and previous assignments -- everything you need to do in this exercise has been covered in this course.

This project will demonstrate your competency in several areas: 

-reading from a file

-using a struct or class

-working with an array

-sorting an array

-searching an array

-formatting output
 

# Final Project: Office Supply Store Inventory

Create a project that simulates an office supply store with inventory. You need an array of structs or class objects to store the inventory; read the inventory from this fileDownload this file to store in that array. The file has the inventory ID, product name, cost, and quantity on a single line for each item; there are 10 items in this inventory file. The project needs to display the list of inventory sorted either by product ID or by price, as specified by the user. Ask the user which item they want to purchase and what quantity; validate that the item number is valid and that there is enough of it in inventory. Display the cost of the item. Allow the user to purchase as many items as they want. When they signal they are done, display a total cost. All money amounts must display with proper currency formatting (hint: see the formatting functions in the previous chapter). 

Here are images that demonstrate the functionality of this project:

Inventory sorted by ID ascending (smallest to largest):

![Final - sort by ID](https://github.com/bell-kevin/officeSupplyStoreInventoryFinalProjectCplusPlus1/blob/main/final.PNG)   

Inventory sorted by price ascending (smallest to largest):

![Final - sort by price](https://github.com/bell-kevin/officeSupplyStoreInventoryFinalProjectCplusPlus1/blob/main/final0.PNG)

If the user does not select an appropriate sorting option, don't sort the file, just display it as it was loaded from the file:

![Final - sort bad](https://github.com/bell-kevin/officeSupplyStoreInventoryFinalProjectCplusPlus1/blob/main/final00.PNG)

This shows 2 good purchases after sorting by ID:

Final - ID all good    

This shows 2 good purchases after sorting by price:

Final - price all good

This shows bad sorting option, bad item ID, bad quantity:

Final - all bad 

This shows no purchase at all:

![Final - no purchase](https://github.com/bell-kevin/officeSupplyStoreInventoryFinalProjectCplusPlus1/blob/main/final000.PNG)

Validate the item ID the user provides and keep prompting the user until it is valid. Check if there is available inventory for the purchase, and if not, do not complete the transaction but present an error message. If there were no purchases before the user decided to quit, do not display a total cost of $0 -- don't display anything at all about a purchase. All money values must be displayed in currency format -- with a dollar sign, a comma separator if the value is in the thousands, a decimal point and 2 decimal places. The inventory list must display with column headings, as seen in the images.

![p](https://github.com/bell-kevin/officeSupplyStoreInventoryFinalProjectCplusPlus1/blob/main/final0000.PNG)

Use functions to display the array with column headings; to sort the array by ID; to sort the array by price; to format numbers and strings to display correctly as money.

Create a table of test cases BEFORE you write the code. Include test cases for all of the bad input options as well as at least 2 cases for good input. Run the project and test all the bad cases, taking screenshots of each one. Run the project 2 times with good input and take screenshots.

 

Submission: the table of test cases, the screenshots, and the root folder of the project.

== We're Using GitHub Under Protest ==

This project is currently hosted on GitHub.  This is not ideal; GitHub is a
proprietary, trade-secret system that is not Free and Open Souce Software
(FOSS).  We are deeply concerned about using a proprietary system like GitHub
to develop our FOSS project. I have a [website](https://bellKevin.me) where the
project contributors are actively discussing how we can move away from GitHub
in the long term.  We urge you to read about the [Give up GitHub](https://GiveUpGitHub.org) campaign 
from [the Software Freedom Conservancy](https://sfconservancy.org) to understand some of the reasons why GitHub is not 
a good place to host FOSS projects.

If you are a contributor who personally has already quit using GitHub, please
email me at **bellKevin@pm.me** for how to send us contributions without
using GitHub directly.

Any use of this project's code by GitHub Copilot, past or present, is done
without our permission.  We do not consent to GitHub's use of this project's
code in Copilot.

![Logo of the GiveUpGitHub campaign](https://sfconservancy.org/img/GiveUpGitHub.png)
