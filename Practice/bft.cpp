#include <iostream>
#include <queue>

using namespace std;

void BFS(Node * root){

    if(root==nullptr)
        return;
    queue<Node *>q;
    q.push(root);
    while(!q.empty()){
        cout << q.front();
        Node * node = q.front();
        q.pop();
        if(node->left!=nullptr)
            q.push(node->left);
        if(node->right!=nullptr)
            q.push(node->right);
    }




}
