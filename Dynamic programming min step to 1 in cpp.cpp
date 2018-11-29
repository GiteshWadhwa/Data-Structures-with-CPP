#include<iostream>
using namespace std;
minStep(int n){
if(n<=1){
    return 0;
}
//recursion call
int x=minStep(n-1);
int y=INT_MAX,z=INT_MAX;
if(n%2==0)
{
    y=minStep(n/2);
}
if(n%3==0)
{
    z=minStep(n/3);
}
int ans=min(x,min(y,z))+1;

}
int main()
{

    int n;
    cin>>n;
    cout<<minStep(n)<<endl;
}
