#include "queue.h"
#include<string.h>
using namespace std;

int main(){
  Queue<int> a;
  Queue<char> b;
  Queue<string> c;
  for(int i=62;i<96;i++){
    a.enqueue(i);
    b.enqueue(i+30);
    c.enqueue("avi");
  }
  //a.top();
  a.print_queue();
  b.print_queue();
  c.print_queue();
}
