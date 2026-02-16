

/*
 * LaQueue
 * 
 * 
 * This is part of a series of labs for the Liberal Arts and Science Academy.
 * The series of labs provides a mockup of an POSIX Operating System
 * referred to as LA(SA)nix or LAnix.
 *  
 * (c) copyright 2018, James Shockey - all rights reserved
 * 
 * */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "PQueue.h"



/*
 * Class Priority Queue
 */

		
/*
* Insert into Priority Queue
*/
void PQueue::push(void *item, int priority)
{
	node *tmp = new node;
	tmp->data = item;
	tmp->priority = priority;
	tmp->link = NULL;
	
	if (front == NULL){
	    front = tmp;
	}
	
	else if (priority > front-> priority){
	    tmp->link = front;
	    front = tmp;
	} else {
	    node *current = front;
	    while (current->link != NULL && current->link->priority >= priority) {
	        current = current->link;
	    }
	    tmp->link = current->link;
	    current->link = tmp;
	}
	
	
}

/*
 * Delete from Priority Queue
 */
void* PQueue::top()
{
	if (front == NULL){
	    return NULL;
	}
	
	return front->data;
}
/*
 * Delete from Priority Queue
 */
void PQueue::pop()
{
	if (front==NULL){
	    return;
	}
	node *temp = front;
	front = front->link;
	delete temp;
}

/*
 * Print Priority Queue
 */
void PQueue::display()
{

	/* Your code here */
	node* ptr = front;
	
	while(ptr!=NULL){
	
	/* Use the following out command for the data */
	    std::cout<<ptr->priority<<" "<<(char*)ptr->data<<std::endl;
	    ptr = ptr->link;
	}

}
	
