#include<iostream>
#include"hashing.h"
using namespace std;
#define INDEX 1000

struct hash_table hash_table[INDEX];

int hash_key(int data){
  return (data%INDEX);
}

void insert_list(int data,int key){
  struct hash_table* current=hash_table[key].next;
  struct hash_table* temp=new struct hash_table;

  temp->key=key;
  temp->data=data;
  temp->next=NULL;

  if(current==NULL){
    hash_table[key].next=temp;
    return;
  }

  while(current->next!=NULL){
    if(current->data==data){
      cout<<"Data Already Exist : "<<current->data<<"\n";
      return;
      }
    current=current->next;
    }
  if(current->data==data){
    cout<<"Data Already Exist : "<<current->data<<"\n";
    return;
  }
  current->next=temp;
}

void insert_data(int data){
  struct hash_table temp;
  int key=hash_key(data);
  temp.data=data;
  temp.key=key;
  temp.next=NULL;

  if(hash_table[key].data==-1){
    hash_table[key]=temp;
    return;
  }
  else if(hash_table[key].data==data){
    cout<<"Data Already Inserted : "<<"hash_table[key].data"<<"\n";
    return;
  }
  else{
    insert_list(data,key);
    return;
  }
}

void find_list(struct hash_table* current,int data){
  if(current==NULL){
    cout<<"Not found\n";
    return;
  }
  int count=1;
  while(current!=NULL){
    if(current->data==data){
      cout<<"Found : "<<count<<"\n";
      return;
    }
    current=current->next;
    count++;
  }
  cout<<"Not found\n";
}

void find(int data){
  int key=hash_key(data);

  if(hash_table[key].key!=-1){
    if(hash_table[key].data==data){
      cout<<"Found "<<data<<"\n";
      return;
    }
    else{
      find_list(hash_table[key].next,data);
      return;
    }
  }
  cout<<"Not Found\n";
}
