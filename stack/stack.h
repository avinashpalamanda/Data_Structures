#include<iostream>
#include<string.h>
/*Creating struct to save stack data*/
template <class T>
struct stack{
  T data;
  struct stack<T>* next;
};

template <class T>
class Stack{
public:
struct stack<T>* head=NULL;//Head of stack
void push(T);
void pop();
void top();
void print_stack();
};
