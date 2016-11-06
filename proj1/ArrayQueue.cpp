#ifndef _ARRAYQUEUESOLN_CPP
#define _ARRAYQUEUESOLN_CPP

//ArrayQueueSoln.cpp

#include "ArrayQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>
using namespace std;

// 221 STUDENTS:
//
// This skeleton file (along with the .hpp) is
// here to help get you started, but you are
// free to change function signatures, etc.
// as long as ArrayQueue is some subtype
// of BagOfMazeStates
ArrayQueue::ArrayQueue()
{
  // Constructor: initialize member variables
  //              and do any other initialization
  //              needed (if any)
  // TODO: implement constructor

  size = 0;
  head = 0;
  tail = 0;
  array = new MazeState*[INIT_SIZE];
  for(int i = 0; i < INIT_SIZE; i++){
   array[i] = NULL;
  }

 capacity = INIT_SIZE; 
}

void ArrayQueue::add(MazeState *elem)
{
  // TODO: implement add method
  if(elem == NULL){
return;
}

  if ((tail) % (capacity) == head) {
    // queue is full
   // cout << size << endl;
    ensure_capacity(size+1); // ensure_capacity makes grows the array.
    
 }
  
 
  if((size == 0) ){
    array[0] = elem;
	head = 0;
	tail = 1;
	size = 1;
	return;
    }
 array[tail] = elem;
 tail = (tail + 1) % (capacity);
size++;
//cout << size << endl;
}

MazeState *ArrayQueue::remove()
{
  // TODO: implement remove method
  assert(!is_empty());
  MazeState *temp = array[head];
  head = (head+1) % (capacity);
  size--;
  return temp;
}

bool ArrayQueue::is_empty()
{
 // TODO: implement is_empty method
  return (size == 0);
}

// TODO: implement ensure_capacity (but leave this to last.. just start with lots of capacity!)
void ArrayQueue::ensure_capacity(int n)
{
  if (capacity < n) {
//    cout << "head tail array" << head<< "  "  << tail << "  " << array << endl;
    // Make plenty of room.
    
    int target_capacity = (n > 2*capacity+1) ? n : (2*capacity+1);

    // TODO: Set the current array aside and make room for the new one.

    // TODO: Copy each element of the old array over.
    // Update front carefully as you go!  Can you just use front++?

    // TODO: Fix front and back and capacity so they correspond to the new array.
    // TODO: Delete the old array.
       MazeState **oldarray = array;
       array = new MazeState*[target_capacity];

       for(int i = 0; i<size; i++){
       array[i] = oldarray[(head + i) % (capacity)];
       }
       head = 0;
       tail = size;
 
       capacity = target_capacity;
       delete [] oldarray;
   }
 //  cout<< "hello? capacity head tail size  " <<capacity << "  " << head << "   " << tail << "   " << size <<  endl;
}


ArrayQueue::~ArrayQueue()
{
  // TODO: implement the destructor
//cout << "seofinsefb"  << size << endl;
  delete [] array;
  
  head = 0;
  tail = 0;
  size = 0;
}

#endif
