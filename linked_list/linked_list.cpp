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
        temp->next=current;
        head=temp;
        return;
      }
      else if(current->next==NULL){
        temp->next=current;
        prev->next=temp;
        return;
      }
      temp->next=current;
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

  if(current->next==NULL){
    head=NULL;
    return;
  }

  while(current->next!=NULL){
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
  cout<<"]\n";
}

void reverse(){
  struct linked_list* current=new struct linked_list;
  struct linked_list* next=new struct linked_list;
  struct linked_list* prev=new struct linked_list;
  current=head;
  prev=NULL;
  while(current!=NULL){
    next=current->next;
    current->next=prev;
    prev=current;
    current=next;
  }
  head=prev;
  print_list();
  return;
}

void sort(){
  struct linked_list* current=new struct linked_list;
  struct linked_list* ref=new struct linked_list;
  struct linked_list* temp=new struct linked_list;

  current=head;
  while(current!=NULL){
    temp=current->next;
    int key_1=current->key;
      while(temp!=NULL){
        if(key_1 > temp->key){
          ref->key=temp->key;
          temp->key=current->key;
          current->key=ref->key;

          ref->data=temp->data;
          temp->data=current->data;
          current->data=ref->data;
          //swap;
        }
        temp=temp->next;
      }
      current=current->next;
  }
}

void count(){
  struct linked_list* current=head;
  int count=0;
  while(current!=NULL){
    count++;
    current=current->next;
  }
  cout<<count<<"\n";
}

int main(){
  insert_first(3,30);
  insert_first(2,20);
  insert_last(5,50);
  insert_last(7,70);
  insert_key(1,10,2);
  insert_key(6,60,7);
  insert_key(4,40,5);

  print_list();
  reverse();
  sort();
  print_list();
  count();
}
