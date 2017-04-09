#include "binary_tree.h"

int main(){
  binary_tree<char> a;
  a.insert(97);
  a.insert(102);
  a.insert(103);
  a.insert(98);
  a.insert(100);
  a.insert(101);
  a.insert(109);
  a.insert(104);
  a.insert(110);
  a.levelorder_traversal(a.head);
  cout<<"\n";
  a.remove(97);
  a.remove(111);
  a.find(109);
  a.levelorder_traversal(a.head);
  cout<<"\n";

}
