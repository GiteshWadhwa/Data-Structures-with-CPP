#include<stack>
#include<cstring>
int countBracketReversals(char input[]){
	// Write your code here
int len=strlen(input);
  if(len%2!=0)
  {
    return -1;
  }
   stack<char> s;
    for (int i=0; i<len; i++)
    {
        if (input[i]=='}' && !s.empty())
        {
            if (s.top()=='{')
                s.pop();
            else
                s.push(input[i]);
        }
        else
            s.push(input[i]);
    }
    int Or_len = s.size();
    int n = 0;
    while (!s.empty() && s.top() == '{')
    {
        s.pop();
        n++;
    }

    return (Or_len/2 + n%2);
}
