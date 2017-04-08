#include"stack.h"

using namespace std;

int main(){
  Stack<int> a;
  Stack<char> b;
  Stack<string> c;
  for(int i=62;i<96;i++){
    a.push(i);
    b.push(i+30);
    c.push("avi");
  }
  //a.top();
  a.print_stack();
  b.print_stack();
  c.print_stack();
}
