#include<iostream>
using namespace std;

//dynamic programmning (bottom approach)
int fibbo(int n){
int *ans=new int[n+1];
ans[0]=0;
ans[1]=1;
for(int i=2;i<=n;i++)
{
    ans[i]=ans[i-1]+ans[i-2];
}
return ans[n];
}

//Brust fruit approach
/*
int fibbo(int n){
  if(n<=1){
    return n;
  }
  int a=fibbo(n-1);
  int b=fibbo(n-2);
  return a+b;
}*/
//using memoization   top down approach........!!!! complexity(o(n))
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
