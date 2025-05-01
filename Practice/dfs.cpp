#include <iostream>
#include <queue>

using namespace std;

class BSTree{

 private:
    struct bst_node{
        int data;
        bst_node *left;
        bst_node *right;
        bst_node(int x){
            data = x;
            this->left = nullptr;
            this -> right = nullptr;
        }
    };


 public:

    int height(bst_node *n){
        if(!n)
            return -1;
        else
            return 1 + max(height(n->left),height(n->right));
    }

    void print_DFS(bst_node * n){

        if(!n) return;

        cout << n->data << " ";
        print_DFS(n->left);
        print_DFS(n->right);
    }


    void BFS(bst_node* root){

        if(!root) return;
        queue <bst_node*> q;
        q.push(root);

        while(!q.empty()){

            bst_node* p = q.front();
            q.pop();
            cout << p << " ";
            if(!p->left) q.push(p->left);
            if(!p->right) q.push(p->right);
        }
    }


};


