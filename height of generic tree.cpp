#include<queue>
#include<iostream>
using namespace std;
#include "Tree 04 maximum data node.h"
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
}
int maximumDataNode(Tree<int>* root)
{
  int max=root->data;
 for(int i=0;i<root->children.size();i++)
 {
     int ans= maximumDataNode(root->children[i]);
     if(max < ans)
     {
         max=ans;
     }
 }
 return max;
}
int height(Tree<int>* root)
{
    int h=0;

    if(root!=NULL)
    {
        for(int i=0;i<root->children.size();i++)
        {
             h=max(h,height(root->children[i]));
        }
    }
    return h+1;
}
int main()
{
    Tree<int>* root=input();
    print(root);
    int ans=countNodes(root);
    cout<<"Total Nodes are: " <<ans<<endl;
    int s=sum(root);
    cout<<"Sum of all nodes :"<<s<<endl;
    int m= maximumDataNode(root);
   cout<<"maximum data node is"<<" "<<m<<endl;
   int h=height(root);
   cout<<"height of tree is:"<<h;
}
