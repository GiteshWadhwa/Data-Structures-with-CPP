#include<iostream>
using namespace std;
template <typename T>
class Node {
    public :
    T data;
    Node<T> *next;

    Node(T data) {
        this -> data = data;
        next = NULL;
    }
};

template <typename T>
class Stack{
Node<T> *head;
int Size;  //number of elements present in stack....
public:
    Stack(){
    head=NULL;
    Size=0;
    }
    int getSize(){
      return Size;
    }
    bool isEmpty(){
     return Size==0;
    }

    void push(T element){
//newnode k next me head or head=new Node..
    Node<T> *newNode=new Node<T>(element);
    newNode->next=head;
    head=newNode;
    Size++;
    }
    T pop(){
        if(isEmpty()){
            return 0;
        }
       T ans=head->data;
       Node<T> *temp=head;
       head=head->next;
       delete temp;
       Size--;
       return ans;
    }
    T top()
    {
         if(isEmpty()){
            return 0;
        }
        return head->data;

    }
};
