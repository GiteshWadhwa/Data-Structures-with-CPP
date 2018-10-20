#include<iostream>
#include<climits>
using namespace std;
class StackUsingArray{
int *data;
int nextIndex;
int capacity;
public:

    StackUsingArray(int totalSize){
    data=new int[totalSize];
    nextIndex = 0;
    capacity=totalSize;
    }

    //return the number of elements present  in the stack
    int size(){
    return nextIndex;
    }
    bool isEmpty()
    {
        /*if(nextIndex==0)
        {
            return true;
        }else{
          return false;
        }*/
        return nextIndex ==0;
    }
    //insert element
    void push(int element){
        if(nextIndex==capacity){
            cout<<"Stack Full"<<endl;
            return;
        }
     data[nextIndex]=element;
     nextIndex++;
    }

    //delete ellement
    int pop(){
        if(isEmpty()){

            cout<<"Stack is empty"<<endl;
            return INT_MIN;
        }
    nextIndex--;
    return data[nextIndex];
    }

    //check topmost element...
    int top(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return INT_MIN;
        }
    return data[nextIndex-1];
    }
};
