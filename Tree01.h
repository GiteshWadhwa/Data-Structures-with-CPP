#include<vector>
using namespace std;
template <typename T>
class  TreeNode{

public:
    T data;//parent si of t type
    vector<TreeNode<T>*> children;//childs are also of t types
    TreeNode(T data){
    this->data=data;

    }



};
