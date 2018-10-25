#include<iostream>
using namespace std;
template<typename T>
class Tree{

public:
    T data;
    vector<Tree<T>*> children;
    Tree(T data)
    {
        this->data=data;
    }

};
