C++ Linked List Implementation

Problem Statement:
For this assignment, you will implement a linked list class using pointers and object-oriented programming. Although the C++ STL (Standard Template Library) offers a linked list implementation, you must implement this program "from scratch" and cannot simply utilize the existing STL offerings (<list> or <forward_list>).

Your linked list will be designed to contain signed integers of type int.
Required Classes

You must implement the classes shown below (as well as the exact member functions that are listed).
Note: It is okay to add additional functions or variables as desired. You cannot add extra parameters to the functions that are listed.

```
class Linked_List_Node {
public:
   int val; // the value that this node stores
   Linked_List_Node *next; // a pointer to the next node in the list
   // you can add constructors or other functionality if you find it useful or necessary
}
```
Note: Linked_List_Node is being used akin to a struct (with public member variables). This is intentional so that you can easily modify the member variables from within the Linked_List class.
```
class Linked_List {
private:
   unsigned int length; // the number of nodes contained in the list
   Linked_List_Node *first; // a pointer to the first node in the list
   // anything else you need...
public:
   int get_length();
   // note: there is no set_length(unsigned int) (the reasoning should be intuitive)
   void print(); // output a list of all integers contained within the list
   void clear(); // delete the entire list (remove all nodes and reset length to 0)
   unsigned int push_front(int); // insert a new value at the front of the list (returns the new length of the list)
   unsigned int push_back(int); // insert a new value at the back of the list (returns the new length of the list)
   unsigned int insert(int val, unsigned int index); // insert a new value in the list at the specified index (returns the new length of the list)
   void sort_ascending(); // sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm
   // Note: it's okay if sort_ascending() calls a recursive private function to perform the sorting.
   void sort_descending(); // sort the nodes in descending order
   // you can add extra member variables or functions as desired
}
```
Note that the sort_ascending() function must be implemented using the recursive Merge Sort algorithm (Links to an external site.). sort_descending() can utilize Merge Sort or a different algorithm (see extra credit).
You are also required to implement a function that counts the number of prime numbers within a Linked_List. This can be written as part of the Linked_List class or in some other class. For our purposes, a negative number is never considered to be prime.

Note: All of the program functionality must be implemented using your linked list. You should not be storing or copying the user input into an array, vector, or other types of data structures.
`
Please enter a number: 146
Do you want another num (y or n): y
Enter a number: 30
Do you want another num (y or n): y
Enter a number: 73
Do you want another num (y or n): y
Enter a number: 10
Do you want another num (y or n): y
Enter a number: -31
Do you want another num (y or n): n
Sort ascending or descending (a or d)? a
Your linked list is: -31 10 30 73 146
You have 1 prime number(s) in your list.
Do you want to do this again (y or n)? n
`
