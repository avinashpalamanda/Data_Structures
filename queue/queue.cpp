#include<iostream>

using namespace std;

/*Structure to hold queue*/
struct queue{
  int data;
  struct queue* next;
};

struct queue* head=NULL;//Head of queue
struct queue* tail=NULL;//Tail of queue

void enqueue(int data){
  struct queue* current=new struct queue;

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

void dequeue(){
  if(head==NULL){
    cout<<"Queue is Empty\n";
    return;
  }
  cout<<"Dequeued Element - "<<head->data<<"\n";
  head=head->next;
  return;
}

void top(){
  if(head!=NULL)
    cout<<"Top Element - "<<head->data<<"\n";
  else
    cout<<"Queue is Empty\n";
  return;
}

void print_queue(){
  if(head==NULL){
    cout<<"Queue is Empty\n";
    return;
  }

  struct queue* current=new struct queue;
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
    enqueue(i);
  }
  top();
  print_queue();
  for(int i=0;i<8;i++){
    dequeue();
  }
  top();
  print_queue();
  for(int i=0;i<2;i++){
    dequeue();
  }
  top();
  print_queue();
}
