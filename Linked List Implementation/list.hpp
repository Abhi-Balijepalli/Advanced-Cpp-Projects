/*****************************************************
** Name: list.hpp 
** Author: YouKnowIt
** Date: 05/29/2019
** Description: header for Linked_List
******************************************************/
#ifndef LIST_HPP
#define LIST_HPP
#include "./node.hpp"
#include <iostream>
using namespace std;

class Linked_List {
	private:
		unsigned int length;
		Linked_List_Node *first;
		
	public:
		Linked_List();
		~Linked_List();
		void Sort(Linked_List_Node **);
		void Sort2(Linked_List_Node **); // for descending
		Linked_List_Node* sortedFinal(Linked_List_Node *, Linked_List_Node *);
		Linked_List_Node* sortedFinal2(Linked_List_Node *, Linked_List_Node *); // for descending
		int get_length();
		void print();
		bool is_prime(int );
		void prime_count();
		void clear();
		unsigned int push_front(int);
		unsigned int push_back(int);
		unsigned int insert(int val, unsigned int index);
		void sort_ascending();
		void sort_descending();
		void controller();
};
#endif
