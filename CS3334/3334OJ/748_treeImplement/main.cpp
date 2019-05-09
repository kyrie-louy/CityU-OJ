#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

int table[1024][1024];
int countNumber;
class quadtree_node
{
public:
    // black: 1  white: 0  both = -1
    int color;
    quadtree_node *my_child[4] = { NULL,NULL,NULL,NULL };
    
    quadtree_node(int color) {
        this->color = color;
    }
    ~quadtree_node()
    {
        for (int i = 0; i < 4; i++)
            delete my_child[i];
    }
};

class quadtree_tree
{
public:
    quadtree_node * root;
    quadtree_tree(int start_row, int start_col, int end_row, int end_col)
    {
        root = buildTree(start_row, start_col, end_row, end_col);
    }
    int getColor(int, int, int, int);
    quadtree_node* buildTree(int, int, int, int);
    
    void reset(int, int, int, int, int, int, quadtree_node*);
    
    void getNodeNumber(quadtree_node* nd) {
        if (nd == NULL)
            return;
        else if (nd->color == 1 || nd->color == 0) {
            countNumber++;
        }
        else
        {
            countNumber++;
            getNodeNumber(nd->my_child[0]);
            getNodeNumber(nd->my_child[1]);
            getNodeNumber(nd->my_child[2]);
            getNodeNumber(nd->my_child[3]);
        }
    }
    ~quadtree_tree()
    {
        delete root;
    }
};

void quadtree_tree::reset(int tr, int tc, int start_row, int start_col, int end_row, int end_col, quadtree_node* nd) {
    if (end_row - start_row == 1)
    {
        nd->color ^= 1;
    }
    else
    {
        if (tr >= start_row && tr < (start_row + end_row) / 2 && tc >= start_col && tc < (start_col + end_col) / 2) {
            reset(tr, tc, start_row, start_col, (start_row + end_row) / 2, (start_col + end_col) / 2, nd->my_child[0]);
        }
        else if (tr >= start_row && tr < (start_row + end_row) / 2 && tc >= (start_col + end_col) / 2 && tc < end_col) {
            reset(tr, tc, start_row, (start_col + end_col) / 2, (start_row + end_row) / 2, end_col, nd->my_child[1]);
        }
        else if (tr >= (start_row + end_row)/2 && tr < end_row && tc >= start_col && tc < (start_col + end_col)/2) {
            reset(tr, tc, (start_row + end_row) / 2, start_col, end_row, (start_col + end_col) / 2, nd->my_child[2]);
        }
        else if (tr >= (start_row + end_row) / 2 && tr < end_row && tc >= (start_col + end_col) / 2 && tc < end_col) {
            reset(tr, tc, (start_row + end_row) / 2, (start_col + end_col) / 2, end_row, end_col, nd->my_child[3]);
        }
        
        int originColor = table[start_row][start_col];
        if (nd->my_child[0]->color == nd->my_child[1]->color &&
            nd->my_child[0]->color == nd->my_child[2]->color &&
            nd->my_child[0]->color == nd->my_child[3]->color) {
            nd->color = originColor;
        }
        else
        {
            nd->color = -1;
        }
        
        
    }
}

quadtree_node* quadtree_tree::buildTree(int start_row, int start_col, int end_row, int end_col) {
    quadtree_node* root = new quadtree_node(getColor(start_row, start_col, end_row, end_col));
    
    if ((end_row - start_row) == 1)
        return new quadtree_node(getColor(start_row, start_col, end_row, end_col));
    else {
        root->my_child[0] = buildTree(start_row, start_col, (start_row + end_row) / 2, (start_col + end_col) / 2);
        root->my_child[1] = buildTree(start_row, (start_col + end_col) / 2, (start_row + end_row) / 2, end_col);
        root->my_child[2] = buildTree((start_row + end_row) / 2, start_col, end_row, (start_col + end_col) / 2);
        root->my_child[3] = buildTree((start_row + end_row) / 2, (start_col + end_col) / 2, end_row, end_col);
        if (root->my_child[0]->color == root->my_child[1]->color&&
            root->my_child[0]->color == root->my_child[2]->color&&
            root->my_child[0]->color == root->my_child[3]->color)
            root->color = root->my_child[0]->color;
        else root->color = -1;
    }
    
    return root;
    
}

int quadtree_tree::getColor(int start_row, int start_col, int end_row, int end_col) {
    int color = table[start_row][start_col];
    for (int i = start_row; i < end_row; i++) {
        for (int j = start_col; j < end_col; j++) {
            if (table[i][j] != color) {
                return -1;
            }
        }
    }
    return color;
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        // initialization
        int k;
        scanf("%d", &k);
        int size = 1 << k;
        // input the table
        for (int i = 0; i < size; i++) {
            string str;
            cin >> str;
            for (int j = 0; j < size; j++) {
                table[i][j] = ((int)str[j] - 48);
            }
        }
        
        quadtree_tree *tree = new quadtree_tree(0, 0, size, size);
        
        // read the change
        int m;
        scanf("%d", &m);
        while (m--) {
            int r, c;
            scanf("%d%d", &r, &c);
            r--;
            c--;
            tree->reset(r, c, 0, 0, size, size, tree->root);
            countNumber = 0;
            tree->getNodeNumber(tree->root);
            cout << countNumber << endl;
        }
        
        delete tree;
    }
    
    return 0;
}
