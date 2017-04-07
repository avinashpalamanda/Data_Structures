#include<iostream>
using namespace std;

/*Creating struct to save stack data*/
struct stack{
  int data;
  struct stack* next;
};

struct stack* head=NULL;//Head of stack

/*Function to push data*/
void push(int data){
  struct stack* current=new struct stack;
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
void pop(){
  if(head!=NULL){
    cout<<"Data Pop'd - "<<head->data<<"\n";
    head=head->next;
  }
  else
    cout<<"Stack is Empty\n";
  }

/*Function to print top of data*/
void top(){
  if(head!=NULL)
    cout<<"Top of Stack - "<<head->data<<"\n";
  else
    cout<<"Stack is Empty\n";
  return;
}

/*Function to print Data*/
void print_stack(){
  if(head==NULL){
    cout<<"Stack is Empty\n";
    return;
  }
  struct stack* current=new struct stack;
  current=head;
  while(current!=NULL){
    cout<<current->data<<" ";
    current=current->next;
  }
  cout<<"\n";
  return;
}

int main(){
  for(int i=0;i<10;i++){
    push(i);
  }
  print_stack();
  top();
  for(int i=0;i<8;i++){
    pop();
  }
  print_stack();
  top();
  for(int i=0;i<2;i++)
    pop();
  print_stack();
  top();
}
