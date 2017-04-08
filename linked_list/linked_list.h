#include<iostream>

using namespace std;

template<class T>
struct linked_list{
  T key;
  T data;
  struct linked_list<T>* next;
};

template<class T>
class list{
public:
struct linked_list<T>* head=NULL;
void insert_first(T,T);
void insert_last(T,T);
void insert_key(T,T,T);
void remove_first();
void remove_last();
void remove(T);
void find(T);
void print_list();
void reverse();
void sort();
void count();
};
