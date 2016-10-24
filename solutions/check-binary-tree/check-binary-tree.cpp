/*
#include <bits/stdc++.h>
// To be compiled with -std=c++11 flag set if not set by default
using namespace std;

typedef struct node{
    int data;
    struct node *left, *right;
}node;

node* newnode(int val){
    node* new_node = new node;
    new_node->data = val;
    new_node->left= NULL;
    new_node->right = NULL;
    return new_node;
}
*/
bool complete(node* tree)
{
    list<node*>  list;
    list.push_back(tree);

    // Normal BFS Procedure
    while(!list.empty())
    {
        node* next = list.front();
        list.pop_front();

        if (next == NULL)
        {   break;
        }

        list.push_back(next->left);
        list.push_back(next->right);
    }

    // Now if the list values should be NULL given the tree is to be complete.
    return !(find_if(list.begin(), list.end(), [](node* e){return e != NULL;}) != list.end());
}
/*
// Driver Function to test the complete module
int main(){
    node* root;
    root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    node* leftc = root->left;
    leftc->left = newnode(4);
    leftc->right = newnode(5);
    node* rightc = root->right;
    rightc->right = newnode(6);

    if (complete(root))
        cout << "The Binary Tree is complete" << endl;
    else
        cout << "The Binary Tree is not complete" << endl;
}
*/
