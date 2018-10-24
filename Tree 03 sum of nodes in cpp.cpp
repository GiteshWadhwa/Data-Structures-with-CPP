#include<queue>
#include<iostream>
using namespace std;
#include "Tree 03 sim of nodes.h"
Tree<int>* input(){
int rootData;
cout<<"enter root node:";
cin>>rootData;
Tree<int>* root=new Tree<int>(rootData);
queue<Tree<int>*>pendingNode;
pendingNode.push(root);
while(pendingNode.size()!=0)
    {
      Tree<int>* front=pendingNode.front();
      pendingNode.pop();
      cout<<"enter the number of children of"<<front->data<<endl;
      int numChild;
      cin>>numChild;
        for(int i=0;i<numChild;i++)
            {
               int childData;
               cout<<"enter"<<i<<"th child of "<<front->data<<endl;
               cin>>childData;
               Tree<int>* child=new Tree<int>(childData);
               front->children.push_back(child);
               pendingNode.push(child);
             }
    }
    return root;

}
void print(Tree<int>* root){

    if(root==NULL)
    {
        return ;
    }

cout<<root->data<<":";
for(int i=0;i<root->children.size();i++)
{
    cout<<root->children[i]->data<<",";
}
cout<<endl;
for(int i=0;i<root->children.size();i++)
{
    print(root->children[i]);
}
}


int countNodes(Tree<int>* root)
{
    int ans=1;
    for(int i=0;i<root->children.size();i++)
    {
       ans+=countNodes(root->children[i]);
    }
  return ans;
}

int sum(Tree<int>* root)
{
    int s=0;
    if(root!=NULL)
    {
        s+=root->data;
     for(int i=0;i<root->children.size();i++)
      {
       s= s+sum(root->children[i]);
      }
      return s;
    }

    /*if(root==NULL)
    {
        return -1;
    }
    s+=root->data;
    for(int i=0;i<root->children.size();i++)
    {
        s+=root->children[i]->data;
    }
    for(int i=0;i<root->children.size();i++)
    {
        print(root->children[i]);
    }*/
}

int main()
{
    Tree<int>* root=input();
    print(root);
    int ans=countNodes(root);
    cout<<"Total Nodes are: " <<ans<<endl;
    int s=sum(root);
    cout<<"Sum of all nodes :"<<s;
}
