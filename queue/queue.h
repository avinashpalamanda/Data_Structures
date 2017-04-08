#include<iostream>
#include<string.h>

/*Creating struct to save stack data*/
template <class T>
struct queue{
  T data;
  struct queue* next;
};

template <class T>
class Queue{
public:
struct queue<T>* head=NULL;//Head of stack
struct queue<T>* tail=NULL;//Head of stack
void enqueue(T);
void dequeue();
void top();
void print_queue();
};
