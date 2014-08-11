/*

Find the maximum size BST present in the binary tree.

*/

#include <iostream>
#include <algorithm>
#include "binary_tree.h"
using namespace std;

int get_max_bst_length(Node* root, int height = 1) {
    //In the degenerate case, a single node is a BST of 
    // height 1, hence keeping 1 as the default value of
    // the height.

    int ht_from_left, ht_from_right;
    ht_from_left = height;
    ht_from_right = height;
    // If there exists a left node, find the maximum tree height 
    // if that node can be appended to the root and still form a BST
    // else, the tree ends at 'height'.    
    if(root->left != NULL) {
        if(root->left->value < root->value) {
            ht_from_left = max(ht_from_left, get_max_bst_length(root->left, height + 1));
        }
        else {
            ht_from_left = height;
        }
    }
    else {
        ht_from_left = height;
    }
    // Similar logic as the left 
    if(root->right != NULL) {
        if(root->right->value > root->value) {
            ht_from_right = max(ht_from_right, get_max_bst_length(root->right, height + 1));
        }   
        else {
            ht_from_right = height;
        }   
    }   
    else {
        ht_from_right = height;
    }

    return max(ht_from_left, ht_from_right);
}
int main() {
    Node* root = new Node;
    handle_input_for_binary_tree(root);
    int max_len = get_max_bst_length(root);
    cout << "Maximum BST is of length: " << max_len << endl;
    return 0;
}
