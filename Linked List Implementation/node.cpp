/*****************************************************
** Name: node.cpp 
** Author: YouKnowIt
** Date: 05/29/2019
** Description: implementation file for the node.hpp  
******************************************************/
#include "./node.hpp"
// constructor
Linked_List_Node::~Linked_List_Node() {
	if(next != NULL) {
		delete next;
	}
}
