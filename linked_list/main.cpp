#include"linked_list.h"
int main(){
  list<int,char> a;
  a.insert_first(1,97);
  a.insert_first(2,98);
  a.insert_last(3,99);
  a.insert_last(4,100);
  a.insert_key(5,101,2);
  //a.remove_first();
  //a.remove_last();
  //a.remove("5");
  a.print_list();
  a.reverse();
  a.sort();
  a.print_list();
  a.count();
}
