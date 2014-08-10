#include <iostream>
using namespace std;

struct Node { 
    char value; 
    Node* left;
    Node* right;
};

Node * find_node_in_binary_tree(Node* root, char c) {
    // Find the char c in the tree rooted at 'root'
    // If found, return the pointer to the node else return 
    // the root itself
    Node* node;
    if(root->value == c) {
        return root;
    }   
    if(root->left != NULL) {
        node = find_node_in_binary_tree(root->left, c); 
        if(node != NULL) {
            return node;
        }   
    }   
    if(root->right != NULL) {
        node = find_node_in_binary_tree(root->right, c); 
        if(node != NULL) {
            return node;
        }   
    }   

    return NULL;
}

void handle_input_for_binary_tree(Node* root) {
    char from, l, r;
    int n;
    Node* from_node;
    cout << "Please enter the total number of nodes in your tree: ";
    cin >> n;
    cout << "There are " << n << " nodes in the tree" << endl; 
    int i = 0;

    while(i < n) {
        i = i + 1;
        cin >> from >> l >> r;
        Node * from_node;
        if(i == 1) {
            root->value = from;
            root->left = NULL;
            root->right = NULL;
            from_node = root;
        }
        else {
            from_node = find_node_in_binary_tree(root, from);
        }
        // Attach the left node
        if(l != '-') {
            Node* l_node = find_node_in_binary_tree(root, l);
            if(l_node == NULL) {
                from_node->left = new Node;
                from_node->left->value = l;
                from_node->left->left = NULL;
                from_node->left->right = NULL;
            }
            else {
                from_node->left = l_node;
            }
        }
        if(r != '-') {
            Node* r_node = find_node_in_binary_tree(root, r);
            if(r_node == NULL) {
                from_node->right = new Node;
                from_node->right->value = r;
                from_node->right->left = NULL;
                from_node->right->right = NULL;
            }
            else {
                from_node->right = r_node;
            }
        }
    }
}
