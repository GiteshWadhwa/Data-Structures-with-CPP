#include<stack>

void reverseStack(stack<int> &s1,stack<int> &s2){

  if(s1.size()<=1)
  {
  return ;
  }
  int lastElement=s1.top();
  s1.pop();
  reverseStack(s1,s2);
  while(!s1.empty()){
     int a=s1.top();
     s1.pop();
     s2.push(a);
  }
  s1.push(lastElement);
  while(!s2.empty()){
  int b=s2.top();
  s2.pop();
  s1.push(b);

  }
}
