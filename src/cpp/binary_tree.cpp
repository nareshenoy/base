/*
    Implement level order traversal of binary trees
    in normal and spiral format.
*/
#include <iostream>
using namespace std;

struct Node {
    char value;
    Node* left;
    Node* right;
};

void print_level_order(Node* root, int level, bool spiral=false) {
    if(root == NULL) {
        return;
    }
    if(level == 1) {
        cout << root->value << " ";
    }
    else if (level > 1) {
        if(spiral == true && level % 2 == 0) {
            print_level_order(root->right, level - 1);
            print_level_order(root->left, level - 1);
        }
        else {
            print_level_order(root->left, level - 1);
            print_level_order(root->right, level - 1);
        }
    }
}
void print_dfs(Node* root) {
    if(root == NULL) {
        return;
    }
    cout << root->value << endl;
    print_dfs(root->left);
    print_dfs(root->right);

    return;
}

Node * find_node(Node* root, char c) {
    // Find the char c in the tree rooted at 'root'
    // If found, return the pointer to the node else return 
    // the root itself
    Node* node;
    if(root->value == c) {
        return root;
    }
    if(root->left != NULL) {
        node = find_node(root->left, c);
        if(node != NULL) {
            return node;
        }
    }
    if(root->right != NULL) {
        node = find_node(root->right, c);
        if(node != NULL) {
            return node;
        }
    }

    return NULL;
}
void handle_input(Node* root) {
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
            from_node = find_node(root, from);
        }
        // Attach the left node
        if(l != '-') {
            Node* l_node = find_node(root, l);
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
            Node* r_node = find_node(root, r);
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
int get_num_of_levels(Node* node) {
    if(node == NULL) {
        return 0;
    }
    if(node->left == NULL and node->right == NULL) {
        return 1;
    }
    int left_tree_height = get_num_of_levels(node->left);
    int right_tree_height = get_num_of_levels(node->right);
    if(left_tree_height > right_tree_height) {
        return left_tree_height + 1;
    }
    else {
        return right_tree_height + 1;
    }
}
int main() {
    Node* root = new Node;
    handle_input(root);
    cout << "====== DFS =====" << endl;
    print_dfs(root);
    cout << "== END OF DFS ==" << endl;
    cout << "====== LEVEL ORDER ======" << endl;
    int num_of_levels = get_num_of_levels(root);
    cout << "Number of levels: " << num_of_levels << endl;
    for(int i = 0; i < num_of_levels; i++) {
        print_level_order(root, i + 1);
        cout << endl;
    }
    cout << "=== END OF LEVEL ORDER ==" << endl;

    cout << "====== SPIRAL ORDER ======" << endl;
    for(int i = 0; i < num_of_levels; i++) {
        print_level_order(root, i + 1, true); 
        cout << endl;
    }   
    cout << "=== END OF SPIRAL ORDER ==" << endl;
 
    return 0;
}
