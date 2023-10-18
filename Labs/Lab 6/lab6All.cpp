#include <iostream>
using namespace std;


//Question 1

struct BinaryNode {
    int data;
    struct node* left;
    struct node* right;
};

BinaryNode* BSTMinimum(BinaryNode* v) {

    if (BinaryNode->left == NULL){
        return BinaryNode->data;
    }

    return BSTMinimum(BinaryNode->left);

}




//Question 2

struct BinaryNode {
    int data;
    BinaryNode *left, *right
}

void BSTInsert(BinaryNode* u, BinaryNode* v) {

    if (v == nullptr){
        v = u;
        return;
    }

    if (u->data < v->data){
        if (v -> left = nullptr){
            v -> left = u;
        }else{
            BSTInsert(u,v->left)
        }
    }else{
        if (v->right == nullptr){
            v->right = u;
        }else{
            BSTInsert(u,v->right);
        }
    }


}