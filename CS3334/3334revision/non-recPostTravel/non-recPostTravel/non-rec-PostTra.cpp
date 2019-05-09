#include <iostream>
#include <stack>
using namespace std;

// binary tree created to test
class TreeNode
{
public:
    char data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(char value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
    void setLeft(char value){
        left = new TreeNode(value);
    }
    void setRight(char value){
        right = new TreeNode(value);
    }
};

class Mytree
{
public:
    TreeNode* root;
    Mytree(){
        root = new TreeNode('A');
        
        root->left = new TreeNode('B');
        root->right =new TreeNode('C');
        root->left->left =new TreeNode('D');
        root->left->right =new TreeNode('E');
        root->right->left =new TreeNode('F');
        root->right->right =new TreeNode('G');
    }

    void noncursivePostOrderTraversal(Mytree*);
};

// non-recursive Postorder Traversal
void Mytree::noncursivePostOrderTraversal(Mytree* t){
    stack<TreeNode*> stk;
    TreeNode* tempRoot = t->root;
    do {
        // to reach the leftmost node in the tree, and record the tempRoot and its right child during the path through stack
        while (tempRoot != NULL) {
            if(tempRoot->right != NULL)
                stk.push(tempRoot->right);
            stk.push(tempRoot);
            
            tempRoot = tempRoot->left;
        }
        
        // after reach the leftmost node
        // first judge if it has right child
        // if it has, change tempRoot to it(so right child will be print first)
        // otherwise, just print the current node
        tempRoot = stk.top();
        stk.pop();
        if(tempRoot->right != NULL && !stk.empty() &&tempRoot->right == stk.top()){
            stk.pop();
            stk.push(tempRoot);
            tempRoot = tempRoot-> right;
        }
        else{
            printf("%c ",tempRoot->data);
            tempRoot = NULL;
        }
        
        
    } while (!stk.empty());
}

int main(int argc, const char * argv[]) {
    // the tree here is filled with A,B,C,D,E,F,G
    Mytree* tree = new Mytree();
    
    tree->noncursivePostOrderTraversal(tree);
    
    return 0;
}
