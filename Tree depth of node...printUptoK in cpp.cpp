#include<iostream>
#include<queue>
#include<stack>
using namespace std;
#include "Tree01.h"
TreeNode<int>*takeInputLevelWise()
{
    int rootData;
    cout<<"enter root data:";
    cin>>rootData;
    TreeNode<int>* root=new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0)
    {
      TreeNode<int>* front=pendingNodes.front();
      pendingNodes.pop();
      cout<<"enter the number of children of"<<front->data<<endl;
      int numChild;
      cin>>numChild;
        for(int i=0;i<numChild;i++)
            {
               int childData;
               cout<<"enter"<<i<<"th child of "<<front->data<<endl;
               cin>>childData;
               TreeNode<int>* child=new TreeNode<int>(childData);
               front->children.push_back(child);
               pendingNodes.push(child);
             }
    }
    return root;
}
TreeNode<int>* takeInput(){
int rootData;
cout<<"data:";
cin>>rootData;
TreeNode<int>* root=new TreeNode<int>(rootData);
int n;
cout<<"enter number of childrens:";
cin>>n;
for(int i=0;i<n;i++)
{

    TreeNode<int>* child=takeInput();
    root->children.push_back(child);
}
return root;
}


void printTreeLevelWise(TreeNode<int>* root){
    queue<TreeNode<int>*>q;
     q.push(root);
     while(q.empty()==false)
     {
         int size=q.size();
         while(size>0)
         {
             TreeNode<int>*current=q.front();
             q.pop();
             cout<<current->data<<":";
             for(int i=0;i<current->children.size();i++)
             {
                 q.push(current->children[i]);
               cout<<current->children[i]->data ;
               if(i!=current->children.size()-1)cout<<",";
             }

             size--;
         cout<<endl;
         }
     }
 return;
}
void printUptoK(TreeNode<int>* root,int k)
{
    if(root==NULL)
    {
        return;
    }
  if(k==0)
   {
    cout<<root->data<<endl;
    return;
   }
   for(int i=0;i<root->children.size();i++)
   {
       printUptoK(root->children[i],k-1);
   }
}
int main()
{
      TreeNode<int>* root=takeInputLevelWise();
printTreeLevelWise(root);
int x;
cin>>x;
printUptoK(root,x);
}
