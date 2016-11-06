//LinkedListQueue.cpp
#ifndef _LINKEDLISTQUEUE_CPP
#define _LINKEDLISTQUEUE_CPP

#include "LinkedListQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>


LinkedListQueue::LinkedListQueue()
{
  // TODO:  Initialize any member variables as needed in the constructor.

	head = NULL;
	tail = NULL;
	size = 0;
}

void LinkedListQueue::add(MazeState *elem)
{
  // TODO:  Implement this.
if( elem == NULL){
return;
}	
	  node* temp = new node;
         temp->data = elem;
	if(size == 0){
        	temp->next = NULL;
		head = temp;
		tail = temp;
        }else{
	tail->next = temp;
	tail = temp;
}
	size++;
}

MazeState *LinkedListQueue::remove()
{
if(size == 0){
return NULL;
}

 MazeState* data = head->data;
node* temp = head;
head = head->next;
delete temp;
size--;
return data;
}


bool LinkedListQueue::is_empty()
{
  return size == 0;
}

LinkedListQueue::~LinkedListQueue()
{
  // TODO:  Implement the destructor.  Be sure to delete.
node* temp = head;
while(size != 0){
    node* next = temp->next;
    delete temp;
    temp = next;
    size--;
}
head = NULL;
tail = NULL;
size = 0;
}

#endif

