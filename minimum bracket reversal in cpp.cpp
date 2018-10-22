#include<stack>
#include<cstring>
#include<iostream>
using namespace std;
int reversals(char st[])
{
    int len=strlen(st);
    if(len%2!=0)
    {

        return -1;
    }
    stack<int> s;
    for(int i=0;i<len;i++)
    {
        if(st[i]=='}'&& !s.empty())
        {
            if(s.top()=='{')
                {
                    s.pop();
                }else{
                s.push(st[i]);
                }
        }
        else{
           s.push(st[i]);
        }
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
int main()
{

    char str[100];
    cin.getline(str,100);
    int x=reversals(str);
   cout<<x;
}
