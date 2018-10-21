#include<queue>
#include<stack>

void reverseQueue(queue<int> &q)
{
  stack<int> Stack;
  while(!q.empty())
  {
      Stack.push(q.front());
      q.pop();
  }
  while(!Stack.empty())
  {
      q.push(Stack.pop());
      Stack.pop();
  }
}
