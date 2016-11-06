//HeapPriorityQueue.cpp
#ifndef _HEAPPRIORITYQUEUE_CPP
#define _HEAPPRIORITYQUEUE_CPP

#include "HeapPriorityQueue.hpp"
#include <cassert>
#include <cstdlib>//for NULL
#include <iostream>

HeapPriorityQueue::HeapPriorityQueue() {
  // Empty... nothing needs to be done.
}

HeapPriorityQueue::~HeapPriorityQueue() {
  // no clean-up to do, since the heap is not dynamically allocated
}

void HeapPriorityQueue::add(MazeState *elem) {
    if(elem == NULL){
    return;
    }
  
    //assert(!isFull());
    //heap[(int)heap.size()]=elem;
    heap.push_back(elem);
    percolateUp((int)heap.size()-1);
    /*heap.push_back(elem);
    int newpos = percolateUp((int)heap.size(),elem);
    heap[newpos] = elem;
    */
}

void HeapPriorityQueue::percolateUp(int hole){
  if(hole == 0) return;
  int p = parent(hole);
  if(heap[hole]->getBadness() < heap[p]->getBadness()){
    MazeState* tmp = heap[hole];
    heap[hole] = heap[p];
    heap[p] = tmp;
    percolateUp(p);
/*
  while(hole>0 && elem->getBadness() < heap[parent(hole)]->getBadness()){
    heap[hole] = heap[parent(hole)];
    hole = parent(hole);
  }
  return hole;
  */
}
}


void HeapPriorityQueue::percolateDown(int hole){
  int i = hole;
  int left = first_child(hole);
  int right = second_child(hole);
  if (left < ((int)heap.size()-1) && heap[left]->getBadness() < heap[i]->getBadness()){
  i = left;
  }
  if(right < ((int)heap.size()-1) && heap[right]->getBadness() < heap[i]->getBadness()){
  i = right;
  }
  if(i != hole) {
    MazeState* tmp = heap[hole];
    heap[hole] = heap[i];
    heap[i] = tmp;
    percolateDown(i);
    }
  /*while(first_child(hole) < (int)heap.size()){
    int left = first_child(hole);
    int right = second_child(hole);
    int target;
    if(right<(int)heap.size() && heap[right]->getBadness() < heap[left]->getBadness()){
      target = right;
    }else{
      target = left;
    }
    if(heap[target]->getBadness() < elem->getBadness()){
      heap[hole] = heap[target];
      hole = target;
    }else break;
  }
  return hole;*/
}

MazeState * HeapPriorityQueue::remove() {
  assert(!is_empty());
  MazeState* ret = heap[0];
  heap[0]=heap[(int)heap.size()-1];
  heap.pop_back();
  percolateDown(0);
  return ret;
 /*MazeState*  ret =  heap[0];
 heap[0] = heap[(int)heap.size()-1]
 heap.pop_back();
 int newpos = percolateDown(0, heap[(int)heap.size()]);
 heap[newpos] = heap[(int)heap.size()];
 return ret;
 */
}


bool HeapPriorityQueue::is_empty() {
  return heap.size()==0;
}

bool HeapPriorityQueue::isFull(){
  return heap.size()== heap.capacity();
}

// You might find these helper functions helpful...
int HeapPriorityQueue::parent(int index) {
  return (index - 1) / 2;
}

int HeapPriorityQueue::first_child(int index) {
  return 2 * index + 1;
}

int HeapPriorityQueue::second_child(int index) {
  return 2 * index +1;
}
bool HeapPriorityQueue::is_root(int index) {
  return index == 0;
}

bool HeapPriorityQueue::is_leaf(int index) {
  return num_children(index) == 0;
}

int HeapPriorityQueue::num_children(int index) {
  int fchild = first_child(index);
  return max(0, min(2, (int)heap.size() - fchild));
}

#endif

