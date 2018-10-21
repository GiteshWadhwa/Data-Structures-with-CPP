#include<iostream>
using namespace std;
#include "queue in linkedlist class.h"
int main()
{
    Queue<int> s;
     s.enqueue(10);
   s.enqueue(20);
   s.enqueue(30);
  s.enqueue(40);
   s.enqueue(50);
  s.enqueue(60);
  cout<<s.front()<<endl;
  cout<<s.dequeue()<<endl;
    cout<<s.dequeue()<<endl;
cout<<s.dequeue()<<endl;
 cout<<s.getSize()<<endl;
  cout<<s.isEmpty()<<endl;

}
