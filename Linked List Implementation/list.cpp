/*****************************************************
** Name: list.cpp 
** Author: YouKnowIt
** Date: 05/29/2019
** Description: implementation file for the list.hpp  
******************************************************/
#include "./list.hpp"
#include <cstdlib>
#include <string>
/*****************************************************
** Name: constructor
** Date: 05/29/2019
** Description: constructs 
*****************************************************/
Linked_List::Linked_List() {
	length = 0;
	first = NULL;	
}
/*****************************************************
** Name: destructor
** Date: 05/29/2019
** Description:deletes allocated memory
*****************************************************/
Linked_List::~Linked_List() {
	delete first;
}
/*****************************************************
** Name: push_front(int )
** Date: 05/29/2019
** Description:adds a value/node to the front of the Linked_List 
*****************************************************/
unsigned int Linked_List::push_front(int point) {
	Linked_List_Node *node = new Linked_List_Node();
	node->val = point;
	node->next = this->first;
	this->first = node;
	this->length++;
	return length;
}
/*****************************************************
** Name: push_back(int )
** Date: 05/29/2019
** Description:adds value/node to the tail of the Linked_List
*****************************************************/
unsigned int Linked_List::push_back(int point) {
	Linked_List_Node *node2 = this->first;
    	if (node2 == NULL) {  
        	node2 = new Linked_List_Node;
       		this->first = node2;
    	} else {
        	while (node2->next != NULL) {
            		node2 = node2->next;
        	}
       		node2->next = new Linked_List_Node;
        	node2 = node2->next;
    }
    	node2->val = point;
    	node2->next = NULL;
    	this->length++;
	return length;
}
/*****************************************************
** Name: insert(int, unsigned) 
** Date: 05/29/2019
** Description: inserts a value at a given index in that set of nodes
*****************************************************/
unsigned int Linked_List::insert(int val, unsigned int index) {
	Linked_List_Node* old = new Linked_List_Node();
	Linked_List_Node* now = new Linked_List_Node();
	Linked_List_Node* future = new Linked_List_Node();
	future->val = val;
	int temp = 0;
	now = first;
	if(first != NULL) {
		while(now->next != NULL && temp != index) {
			old = now;
			now = now->next;
			temp++;
		} if (index == 0) {
			push_front(index);
		} else if (now->next == NULL && index == temp+1) {
			push_back(index);
		} else if (index > temp+1) {
			cout << "that is out of bounds" << endl;
			exit(0);
		} else {
			old->next = future;
			future->next = now;
		}
	} else {
		first = future;
		future->next = NULL;
	}
}
/*****************************************************
** Name: print()
** Date: 05/29/2019
** Description: prints everything 
*****************************************************/
void Linked_List::print() {
	Linked_List_Node *boi = this ->first;
	int i = 0;
	while(boi != NULL) {
		cout << boi->val << " ";
		boi = boi->next;
	}
	cout << endl;
	prime_count();
}
/*****************************************************
** Name: is_prime(int )
** Date: 05/29/2019
** Description: it checks if a value is prime using a bool and its result it goes into prime_count
*****************************************************/
bool Linked_List::is_prime(int x) {
	if (x <= 1) {
		return false;
	} if (x == 2 || x == 3 || x == 5 || x == 7 ) {
		return true;
	}
	if (x%2 == 0 || x%3 == 0) {
		return false;
	}
	for(int i = 5; i*i <= x; i += 6) {
		if( x%i == 0 || x% (i+2) == 0)
			return false;
	}
	return true;

}
/*****************************************************
** Name: prime count 
** Date: 05/29/2019
** Description: if its a prime it will count it in the list
*****************************************************/
void Linked_List::prime_count() {
	int i = 0;
	Linked_List_Node *lol = this->first;
	while(lol != NULL) {
		if(is_prime(lol->val) == true) {
			i++;
		}
		lol = lol->next;
	}
	cout << "there are " << i << " prime(s) in your list. " << endl;
}
/*****************************************************
** Name: sort_ascending
** Date: 05/29/2019
** Description: small to big sorting
*****************************************************/
void Linked_List::sort_ascending() {
	Sort(&first);
	cout << "Ascending order: ";
	print();
}
/*****************************************************
** Name: sort_descending
** Date: 05/29/2019
** Description:big to small sorting
*****************************************************/
void Linked_List::sort_descending() {
	Sort2(&first);
	cout << "Descending order: ";
	print();
}
//game controller
/*****************************************************
** Name: controller()
** Date: 05/29/2019
** Description: runs the sorting
*****************************************************/
void Linked_List::controller() {
	int option;
	cout << "Do you want that sorted Ascending (1) or Descending (2): ";
	cin >> option;
	if (option == 1) {
		sort_ascending();
	}
	else if(option == 2) {
		sort_descending();
	}
	else {
		cout << "invalid input" << endl;
		return;
	}
}
// for ascending
/*****************************************************
** Name: sort( **start)
** Date: 05/29/2019
** Description: part of the merge sort algorithm
*****************************************************/
void Linked_List::Sort(Linked_List_Node **start) {
	Linked_List_Node *item = *start;
	Linked_List_Node *temp = *start;
	Linked_List_Node *s;

	if((item == NULL) || (item->next == NULL)) {
		return;
	} else {
		while(item->next != NULL) {
			item = item->next;
			if(item->next != NULL) {
				temp = temp->next;
				item  = item->next;
			}
		}
		s = temp->next;
		temp->next = NULL;
		item = *start;
	}
	Sort(&item);
	Sort(&s);
	*start = sortedFinal(item,s);
}
/*****************************************************
** Name: sortedFinal( *a, *b)
** Date: 05/29/2019
** Description: part of the merge sort algorithm
*****************************************************/
Linked_List_Node *Linked_List::sortedFinal(Linked_List_Node *a, Linked_List_Node *b) {
	Linked_List_Node* result = NULL; 
	if (a == NULL) {return b; } 
	else if (b == NULL) {return a;}
	if (a->val <= b-> val) { 
		result = a; 
		result->next = sortedFinal(a->next, b); 
	} else { 
		result = b; 
		result->next = sortedFinal(a, b->next); 
	} 
	return (result); 
}

// for descending
/*****************************************************
** Name: sort2
** Date: 05/29/2019
** Description: same as above but for descending 
*****************************************************/
void Linked_List::Sort2(Linked_List_Node **start) {
	Linked_List_Node *item = *start;
	Linked_List_Node *temp = *start;
	Linked_List_Node *s = new Linked_List_Node;

	if((item == NULL) || (item->next == NULL)) {
		return;
	} else {
		while(item->next != NULL) {
			item = item->next;
			if(item->next != NULL) {
				temp = temp->next;
				item  = item->next;
			}
		}
		s = temp->next;
		temp->next = NULL;
		item = *start;
	}
	Sort2(&item);
	Sort2(&s);
	*start = sortedFinal2(item,s);
}
/*****************************************************
** Name: sortedFinal(*a, *b)
** Date: 05/29/2019
** Description: same as above but for descending
*****************************************************/
Linked_List_Node *Linked_List::sortedFinal2(Linked_List_Node *a, Linked_List_Node *b) {
	Linked_List_Node* result = NULL; 
	if (a == NULL) {return b; } 
	else if (b == NULL) {return a;}
	if (a->val >= b-> val) { 
		result = a; 
		result->next = sortedFinal2(a->next, b); 
	} else { 
		result = b; 
		result->next = sortedFinal2(a, b->next); 
	} 
	return (result); 
}
