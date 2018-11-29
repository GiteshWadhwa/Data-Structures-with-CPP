#include<iostream>
using namespace std;

//using memoization   top down approach........!!!! complexicity(o(n))
int fibbona_helper(int n,int *arr)
{
    if(n<=1)
    {
        return n;
    }
    if(arr[n]!=-1){
        return arr[n];
    }
    int a=fibbona_helper(n-1,arr);
    int b=fibbona_helper(n-2,arr);

    arr[n]=a+b;

    return arr[n];

}
int fibbo(int n)
{
    int *ans=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        ans[i]=-1;
    }
    fibbona_helper(n,ans);
}
int main()
{

    int n;
    cin>>n;
   cout<< fibbo(n);
}
