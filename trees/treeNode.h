#include <vector>
using namespace std;

template <typename T>

class treeNode{
public:
    T data;
    vector <treeNode*> children;
    //vector <treeNode < T > *> children can define T as a type of treenode but it also takes it by default 

    treeNode( T data ){
        this->data = data;
    }
    void setChildren ( vector <treeNode*> v){
        this->children = v;
    }
};