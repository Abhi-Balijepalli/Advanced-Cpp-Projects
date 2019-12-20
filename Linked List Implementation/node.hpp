/*****************************************************
** Name: node.hpp 
** Author: YouKnowIt
** Date: 05/29/2019
** Description: header for Linked_List_Node 
******************************************************/
#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
class Linked_List_Node {
	public:
		int val;
		Linked_List_Node *next;
		~Linked_List_Node();
};
#endif

