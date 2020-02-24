#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    // x will be always less than y
    Node* solve(Node* root, int x, int y)
    {
        if(root -> data >= x && root -> data <= y)
            return root;
        if(y < root ->data)
            return solve(root -> left, x, y);
        return solve(root -> right, x, y);

    }
    Node *lca(Node *root, int v1,int v2) {
        if(v1 < v2)
            return solve(root, v1, v2);
        return solve(root, v2, v1);
        

    }
};
