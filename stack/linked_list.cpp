#include<iostream>

using namespace std;

struct linked_list{
  int key;
  int data;
  struct linked_list* next;
};

struct linked_list* head=NULL;

void insert_first(int key,int data){
  struct linked_list* temp=new struct linked_list;

  temp->key=key;
  temp->data=data;
  temp->next=head;

  head=temp;
  return;
}

void insert_last(int key,int data){
  struct linked_list* current=new struct linked_list;
  struct linked_list* temp=new struct linked_list;

  temp->data=data;
  temp->key=key;
  temp->next=NULL;
  current=head;

  if(current==NULL){
    cout<<"Inserted Data - "<<temp->data;
    head=temp;
    return;
  }

  while(current->next!=NULL){
    current=current->next;
  }
  current->next=temp;
  return;
}

void insert_key(int key,int data,int key_refer){
  struct linked_list* current=new struct linked_list;
  struct linked_list* temp=new struct linked_list;
  struct linked_list* prev=new struct linked_list;

  current=head;
  temp->key=key;
  temp->data=data;

  while(current!=NULL){
    if(current->key==key_refer){
      if(current==head){
        temp->next=current->next;
        head=temp;
        return;
      }
      else if(current->next==NULL){
        current->next=temp;
        return;
      }
      temp->next=current->next;
      prev->next=temp;
      return;
    }
    prev=current;
    current=current->next;
  }

  cout<<"Key_Refer Not found\n";
}

void remove_first(){
  if(head==NULL){
    cout<<"List is Empty\n";
    return;
  }
  head=head->next;
}

void remove_last(){
  struct linked_list* current=new struct linked_list;
  struct linked_list* prev=new struct linked_list;
  current=head;

  if(head==NULL){
    cout<<"List is Empty\n";
    return;
  }

  while(current->next==NULL){
    prev=current;
    current=current->next;
  }
  prev->next=NULL;
  return;
}

void remove(int key){
  struct linked_list* current=new struct linked_list;
  struct linked_list* prev=new struct linked_list;
  current=head;

  if(current==NULL){
    cout<<"List is Empty\n";
    return;
  }
  while(current!=NULL){
    if(current->key==key){
      cout<<"Data Removed - "<<current->data<<"\n";
      if(current==head)
        head=head->next;
      else if(current->next!=NULL)
        prev->next=current->next;
      else
        prev->next=NULL;
      return;
    }
    prev=current;
    current=current->next;
  }
  cout<<"Data Not Found\n";
  return;
}

void find(int key){
  struct linked_list* current=new struct linked_list;
  current=head;

  if(head==NULL){
    cout<<"List is Empty\n";
    return;
  }

  while(current!=NULL){
    if(current->key==key){
      cout<<"Key Found,Data - "<<current->data<<"\n";
      return;
    }
    current=current->next;
  }
  cout<<"Key Not Found\n";
}

void print_list(){
  struct linked_list* current=new struct linked_list;
  current=head;

  if(current==NULL){
    cout<<"List is Empty";
    return;
  }

  cout<<"[";
  while(current!=NULL){
    cout<<"("<<current->key<<","<<current->data<<");";
    current=current->next;
  }
  cout<<"]";
}

int main(){
  insert_first(1,20);
  insert_first(2,10);
  insert_last(5,50);
  insert_last(6,60);
  insert_key(3,30,2);
  insert_key(4,40,3);
  print_list();
}
