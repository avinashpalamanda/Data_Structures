#include "queue.h"
#include<string.h>

using namespace std;

template class Queue<int>;
template class Queue<char>;
template class Queue<string>;


template <class T>
void Queue<T>::enqueue(T data){
  struct queue<T>* current=new struct queue<T>;

  current->data=data;
  current->next=NULL;

  if(head==NULL){
    tail=current;
    head=current;
    return;
  }

  tail->next=current;
  tail=current;
}

template <class T>
void Queue<T>::dequeue(){
  if(head==NULL){
    cout<<"Queue is Empty\n";
    return;
  }
  cout<<"Dequeued Element - "<<head->data<<"\n";
  head=head->next;
  return;
}

template <class T>
void Queue<T>::top(){
  if(head!=NULL)
    cout<<"Top Element - "<<head->data<<"\n";
  else
    cout<<"Queue is Empty\n";
  return;
}

template <class T>
void Queue<T>::print_queue(){
  if(head==NULL){
    cout<<"Queue is Empty\n";
    return;
  }

  struct queue<T>* current=new struct queue<T>;
  current=head;
  while(current!=NULL){
    cout<<current->data<<" ";
    current=current->next;
  }
  cout<<"\n";
  return;
}
