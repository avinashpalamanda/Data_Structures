#include"linked_list.h"
int main(){
  list<string> a;
  a.insert_first("1","avi");
  a.insert_first("2","ram");
  a.insert_last("3","raja");
  a.insert_last("4","rahul");
  a.insert_key("5","rama","2");
  //a.remove_first();
  //a.remove_last();
  //a.remove("5");
  a.print_list();
  a.reverse();
  a.sort();
  a.print_list();
  a.count();
}
