#include<iostream>
using namespace std;
template <typename T>
class QueueUsingArray{

T *data;
int nextIndex;
int firstIndex;
int Size;
int capacity;

public:
  QueueUsingArray(int s)
  {
      data=new T(s);
      nextIndex=0;
      firstIndex=-1;
      Size=0;
      capacity=s;
  }

  int getSize()
  {
      return Size;
  }

  bool isEmpty(){
   return Size==0;
  }
  //insert
  void enqueue(T element)
  {
      if(Size==capacity)
      {
          cout<<"Queue full !"<<endl;
          return;
      }
    data[nextIndex]=element;
    nextIndex=(nextIndex+1)%capacity;
    if(firstIndex==-1)
    {
        firstIndex=0;
    }
    Size++;
  }
  T front(){
 if(isEmpty())
      {
         cout<<"Queue is empty"<<endl;
          return 0;
      }
      return data[firstIndex];
  }

  T dequeue(){
  if(isEmpty()){
    cout<<"queue is empty !"<<endl;
    return 0;
  }
  T ans=data[firstIndex];
  firstIndex=(firstIndex+1)%capacity;
  Size--;
  if(Size==0){
    firstIndex=-1;
    nextIndex=0;
  }
  return ans;
  }
};
