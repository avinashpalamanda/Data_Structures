#include<iostream>
using namespace std;
#define INDEX 1000

struct hash_table{
  int key=-1;
  int data=-1;
  struct hash_table* next=NULL;
}hash_table[INDEX];

int hash_key(int data){
  return (data%INDEX);
}

void insert_data(int data){
  struct hash_table temp;
  int key=hash_key(data);
  temp.data=data;
  temp.key=key;
  temp.next=NULL;

  if(hash_table[key].data==-1){
    hash_table[key]=temp;
  }
  else{
    //List
  }
}

void find(int data){
  int key=hash_key(data);

  if(hash_table[key].key!=-1){
    if(hash_table[key].data==data){
      cout<<"Found "<<data<<"\n";
      return;
    }
    else{
      //List
    }
  }
  cout<<"Not Found\n";
}

int main(){
  insert_data(20);
  insert_data(30);
  insert_data(40);
  insert_data(50);
  insert_data(60);
  insert_data(70);
  find(20);

}
