#include"stack.h"
using namespace std;

//struct stack* head=NULL;

/*Function to push data*/
template class Stack<int>;
template class Stack<char>;
template class Stack<string>;

template <class T>
void Stack<T>::push(T data){
  struct stack<T>* current=new struct stack<T>;
  current->data=data;

  if(head!=NULL){
    current->next=head;
    head=current;
    return;
  }
  current->next=NULL;
  head=current;
  return;
}

/*Function to pop data*/
template <class T>
void Stack<T>::pop(){
  struct stack<T>* current=new struct stack<T>;
  current=head;
  if(current!=NULL){
    cout<<"Data Pop'd - "<<(current->data)<<"\n";
    head=current->next;
  }
  else
    cout<<"Stack is Empty\n";
  }

/*Function to print top of data*/
template <class T>
void Stack<T>::top(){
  if(head!=NULL)
    cout<<"Top of Stack - "<<head->data<<"\n";
  else
    cout<<"Stack is Empty\n";
  return;
}

/*Function to print Data*/
template <class T>
void Stack<T>::print_stack(){
  if(head==NULL){
    cout<<"Stack is Empty\n";
    return;
  }
  struct stack<T>* current=new struct stack<T>;
  current=head;
  while(current!=NULL){
    cout<<current->data<<" ";
    current=current->next;
  }
  cout<<"\n";
  return;
}
