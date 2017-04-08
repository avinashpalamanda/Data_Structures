#include<iostream>
using namespace std;
#define INDEX 1000

extern struct hash_table{
  int key=-1;
  int data=-1;
  struct hash_table* next=NULL;
}hash_table[INDEX];

extern int hash_key(int);
extern void insert_list(int,int);
extern void insert_data(int);
extern void find_list(struct hash_table* current,int);
extern void find(int data);
