#include <iostream>
using namespace std;


//Question 2

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to count the number of nodes in the binary tree
int countNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to count the number of leaves in the binary tree
int countLeaves(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    return countLeaves(root->left) + countLeaves(root->right);
}

// Function to count the number of full nodes in the binary tree
int countFullNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left != nullptr && root->right != nullptr) {
        return 1 + countFullNodes(root->left) + countFullNodes(root->right);
    }
    return countFullNodes(root->left) + countFullNodes(root->right);
}



//Question 5

int AVLnodes(int height)
{
    if (height == 0)
        return 1;
    else if (height == 1)
        return 2;
 
    return (1 + AVLnodes(height - 1) + AVLnodes(height - 2));
}
 
int main()
{
    cout << AVLnodes(13) << endl;
}

