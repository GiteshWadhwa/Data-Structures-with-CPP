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


void printTree(TreeNode<int>* root){

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
    printTree(root->children[i]);
}
}

int main()
{
 /* TreeNode<int>* root=new TreeNode<int>(1);
    TreeNode<int>* node1=new TreeNode<int>(2);
      TreeNode<int>* node2=new TreeNode<int>(3);
      root->children.push_back(node1);
      root->children.push_back(node2);*/
      TreeNode<int>* root=takeInputLevelWise();
printTree(root);
//TODO delete the tree

}
