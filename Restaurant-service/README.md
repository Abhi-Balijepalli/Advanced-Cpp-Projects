The Pizza Portal
Problem Statement

This program is going to simulate some of the common functionality of a pizza ordering site. The program will allow customers and employees to interact with the site and will begin by prompting the user to identify themselves (customer or employee).
If the user is an employee, they need to successfully log in to be able to change aspects of the site. Upon successful log in, employees should be provided the option to change the restaurant hours, add or remove items from the menu, or view or remove orders.
If the user is a customer, they should be provided with the option to search the menu by price or by ingredients (case insensitive) or place an order. When placing an order, a customer may select off the entire menu or from the last search result they examined.
Both kinds of users should have the option to view the menu, the restaurant hours, address or phone number. Users may also log out at anytime which will return them to the welcome prompt. From the welcome prompt they can end the program or log in as another user.
Additional Requirements

To save time on this assignment, the restaurant information, menu, and employees of the restaurant will be read in from files. Changes to the menu, hours, and the orders will be written back out to their respective files. The file formats can be found at the end of this document. You may assume that the filenames are hardcoded as follows:
menu.txt
employee.txt
restaurant_info.txt
orders.txt

You will implement this program with the following classes and structs: Restaurant, Menu, Pizza, employee, and hours. Partial outlines of the classes and structs are provided at the end of this document to help get you started. You will need to add more functions. You may add variables if they are useful and you can defend their addition.

Your code must be written in a modular format with separate .h and .cpp files for each class.
Example Operation

<
Note: The example output from this assignment is made-up. The expected output will depend on the particular input files.
Your implementation does not have to look exactly the same but it must support the required functionality as described in
the assignment.
>
$ ./pizza_portal
Welcome to Bytes Pizza!
Are you a customer (C) or employee (E) or would you like to quit (Q)? E
Please enter your ID number: 1111
Please enter your password: Flam
Incorrect ID or password. Please try again.
Please enter your ID number: 1111
Please enter your password: Flamingo
Welcome C.J. Cregg!
What would you like to do?
  1. Change hours
  2. View orders
  3. Remove order
  4. Add Item to Menu  
  5. Remove Item from Menu
  6. View Menu
  7. View Hours
  8. View Address
  9. View Phone
  10. Log out
Selection: 1

Which day would you like to change the hours for? Friday
What should the opening time be? 8am
What should the closing time be? 11pm
Here are the updated hours:
Sunday 12pm 8pm
Monday 10am 9pm
Tuesday 10am 9pm
Wednesday 10am 9pm
Thursday 10am 9pm
Friday 8am 11pm
Saturday 10am 11pm

What would you like to do?
1. Change hours
2. View orders
3. Remove order
4. Add Item to Menu 
5. Remove Item from Menu
6. View Menu
7. View Hours
8. View Address
9. View Phone
10. Log out
Selection: 10

Welcome to Bytes Pizza!
Are you a customer (C) or employee (E) or would you like to quit (Q)? C
What would you like to do?
  1. View Menu
  2. Search by Cost
  3. Search by Ingredients
  4. Place Order
  5. View Hours
  6. View Address
  7. View Phone
  8. Log out
Selection: 3

Would you like to search for ingredients you want include (I) or exclude (E)? I
What item would you like to include? pepperoni
Do you want to include another item (Yes/No)? Yes
What item would you like to include? mozzarella
Do you want to include another item? No
Here are the pizzas that match your criteria:
Corvegas 12 23 28 5 Pesto Pepperoni Mozzarella Roasted_Red_Peppers Artichoke
Meat_Lovers 10 18 25 6 Pepperoni Sausage Smoked_Pork_Belly Mozzarella Parm Marinara

Would you like to reduce your search by excluding some ingredients (Yes/No)? No
Would you like to place an order off this search result (Yes/No)? No

What would you like to do?
1. View Menu
2. Search by Cost
3. Search by Ingredients
4. Place Order
5. View Hours
6. View Address
7. View Phone
8. Log out
Selection: 2

What is your maximum budget (in dollars)? 20
Here are the pizzas that match your criteria. Ineligible sizes are marked as N/A:
Corvegas 12 N/A N/A 5 Pesto Pepperoni Mozzarella Roasted_Red_Peppers Artichoke
Zorba 12 N/A N/A 5 Herb_Chicken Feta Artichoke Red_onion Mushroom
Meat_Lovers 10 18 N/A 6 Pepperoni Sausage Smoked_Pork_Belly Mozzarella Parm Marinara
Southtown_Blues 9 17 20 7 Pear Apple Bleu_Cheese Mozzarella Toasted_Almonds Sweet_Onion Garlic_Infused_Oil
Margherita 9 17 N/A 5 Tomato Mozzarella_Fresca Basil Marinara Balsamic_Reduction

Would you like to place an order off this search result (Yes/No)? Yes
(1) Small Corvegas - $12
(2) Small Zorba - $12
(3) Small Meat_Lovers - $10
(4) Medium Meat_Lovers - $18
(5) Small Southtown_Blues - $9
(6) Medium Southtown_Blues - $17
(7) Large Southtown_Blues - $20
(8) Small Margherita - $9
(9) Medium Margherita - $17
Please select an option from the list above. You may also enter 0 to cancel this order or press enter (blank line) to proceed to checkout.
Your selection: 5
How many Small Southtown_Blues? 2
Please select an option from the list above. You may also enter 0 to cancel this order or press enter (blank line) to proceed to checkout.
Your selection: 4
How many Medium Meat_Lovers? 1
Please select an option from the list above. You may also enter 0 to cancel this order or press enter (blank line) to proceed to checkout.
<enter>
Please provide the following information:
Customer name: Justin Goins
Credit card number: 4405465316452134
Phone number: 8009776368
Thank you! Your order number is 2.

<
Note that the orders.txt file would now contain an additional entry with the new order.
The format would follow the example shown in the "Required File Formats" section.
>

What would you like to do?
1. View Menu
2. Search by Cost
3. Search by Ingredients
4. Place Order
5. View Hours
6. View Address
7. View Phone
8. Log out
Selection: 8

Welcome to Bytes Pizza!
Are you a customer (C) or employee (E) or would you like to quit (Q)? Q

Implementation Details:

    Clarification: I do not expect students to validate company information that is provided. There are many valid forms of addresses, hours of operation, etc.
    This list is not exhaustive. Your program must satisfy all the requirements given in this document.
    You may not use the <algorithm> library in your program. Any searching or sorting functionality must be implemented "manually" in your implementation.
    Each class needs accessor functions, mutator functions, constructors, copy constructor, destructors, assignment operator overload, and use of const where appropriate.
    No memory leaks are permitted in your code.
    All functions are to be implemented in a modular fashion. You should expect to lose points if any function is greater than 20 lines (including main). Lines that contain only comments, variable declarations, or curly braces do not count toward this limit.
    The program needs to be compiled with a Makefile
    Files must be separated into a .h and a .cpp for each class. Both structs may occur in the same .h You should have one driver file.
    Text files will be provided for demos. You may use the examples ones provided in this document to test your program.
    If an employee provides incorrect login information, the system should reprompt until they get it right or elect to quit.
    Users should be provided their menu of choices after each completed task.
    When text files are edited, they should be saved on disk with their newest version. At the completion of your program there should only be four .txt files.
    Users should have the option of refining their search when they search by ingredients. This means if they first search for ingredients to include on the pizza, then they may further reduce these results by providing a list of ingredients to not include. Users should then be able to place an order after completing this search.
    Users should be able to place an order after completing the cost search. The program does not need to refine the search after finding pizzas by cost.
    If the user does not place an order off of a search result, then the default behavior should be to select an order off the entire menu.

Required File Formats

Your program must accommodate the file formats as specified in this section.

An example menu.txt file is available here (Links to an external site.).
The menu.txt file will have the following pattern:

Pizza_name Small_Cost Medium_Cost Large_Cost Num_Ingredients Ingredients …
...<Repeats n times>...

An example employee.txt file is available here (Links to an external site.).
The employee.txt file will have the following pattern:

ID Password First_Name Last_Name
...<Repeats n times>...

An example restaurant_info.txt file is available here (Links to an external site.).
The restaurant_info.txt file will have the following pattern:

Name
Phone Number in format: (555) 543-8765
Address
Sunday Open_time Close_time
Monday Open_time Close_time
Tuesday Open_time Close_time
Wednesday Open_time Close_time
Thursday Open_time Close_time
Friday Open_time Close_time
Saturday Open_time Close_time

An example orders.txt file is available here (Links to an external site.).
The orders.txt file must follow the pattern shown below. The "size" must be stored as S, M, or L, representing small, medium, or large, respectively. The customer phone number must be stored without spaces or hyphenation (e.g. 8009776368).

Order_Num Customer_Name Customer_CC Customer_Phone Pizza_name size quantity <repeat for each distinct pizza on order>
Order_Num Customer_Name Customer_CC Customer_Phone Pizza_name size quantity <repeat for each distinct pizza on order>
...<Repeats for each individual order>...

Required Structs & Classes

The following structs and classes are required to be used in your implementation. Note that you are allowed to add additional member functions as needed. You may add member variables if you can justify their existence.

struct employee {
  int id;
  string password;
  string first_name;
  string last_name;
};

struct hours {
  string day;
  string open_hour;
  string close_hour;
};

class Pizza {
  private:
    string name;
    int small_cost;
    int medium_cost;
    int large_cost;
    int num_ingredients;
    string* ingredients;
  public:
    //need to include accessor functions and mutator functions for each private member
    //need to include constructors, copy constructors, assignment operator overload,
    //and destructors where appropriate
};

class Menu {
  private:
    int num_pizzas;
    Pizza* pizzas;
  public:
    //need to include accessor functions and mutator functions for each private member
    //need to include constructors, copy constructors, assignment operator overload,
    //and destructors where appropriate
    // Only one of the following two prototypes should be used:
    Menu search_pizza_by_cost(int upper_bound);
    Menu search_pizza_by_cost(int upper_bound, string size);
    Menu search_pizza_by_ingredients_to_include(string* ingredients, int num_ingredients);
    Menu search_pizza_by_ingredients_to_exclude(string* ingredients, int num_ingredients);
    void add_to_menu(Pizza pizza_to_add);
    void remove_from_menu(int index_of_pizza_on_menu);
}

class Restaurant {
  private:
    Menu menu;
    employee* employees;
    hours* week;
    string name;
    string phone;
    string address;
  public:
    //need to include accessor functions and mutator functions for each private member
    //need to include constructors, copy constructors, assignment operator overload,
    //and destructors where appropriate
    void load_data(); //reads from files to correctly populate menu, employees, hours, etc.
    bool login(string id, string password);
    void view_menu();
    void view_hours();
    void view_address();
    void view_phone();
    void search_menu_by_price();
    void search_by_ingredients();
    // note that the following prototype was modified to include additional parameters
    // selection is a dynamically allocated array of Pizza objects that are being ordered
    // selection_size indicates the number of Pizza objects in the array
    // num_ordered is a dynamically allocated array that indicates how many pizzas of each type were ordered
    void place_order(Pizza* selection, int selection_size, int* num_ordered);
    // you may also choose to use this prototype that was originally included:
    void place_order(Pizza* selection);
    void change_hours();
    void add_to_menu();
    void remove_from_menu();
    void view_orders();
    void remove_orders();
};

Programming Style/Comments

***************************
