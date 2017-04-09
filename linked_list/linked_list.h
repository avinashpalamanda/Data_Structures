#include<iostream>

using namespace std;

template<class U,class T>
struct linked_list{
  U key;
  T data;
  struct linked_list<U,T>* next;
};

template<class U,class T>
class list{
public:
struct linked_list<U,T>* head=NULL;
void insert_first(U,T);
void insert_last(U,T);
void insert_key(U,T,U);
void remove_first();
void remove_last();
void remove(U);
void find(U);
void print_list();
void reverse();
void sort();
void count();
};
