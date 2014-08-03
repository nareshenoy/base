/*

 Code to decide whether a linked list is a palindrome.
 Time complexity  : O(n)
 Extra Space complexity : O(1)
 
*/
#include <iostream>
using namespace std;

struct Node{
    char value;
    Node* next;
};

int take_input(Node* head) {
    int n;
    cout << "Please enter the number of nodes in the list:";
    cin >> n;

    if(n <= 0) {
        return -1;
    }

    char tmp;
    Node* head_ptr = head;
    cin >> tmp;
    head_ptr->value = tmp;
    for(int i = 0; i < n - 1; i++) {
        head_ptr->next = new Node;
        head_ptr = head_ptr->next;
        cin >> tmp;
        head_ptr->value = tmp;
    }
    return n;
}

void print_linked_list(Node* head) {
    Node* head_ptr = head;
    while(head_ptr != NULL) {
        cout << head_ptr->value << " ";
        head_ptr = head_ptr->next;
    }   
    cout << endl;    
}

bool compare_linked_lists(Node* first, Node* second) {
    Node* lhs = first;
    Node* rhs = second;
    /*
       We make an assumption here that the two linked
       lists have the same length
    */
    while(lhs->next != NULL and rhs->next != NULL) {
        if (lhs->value == rhs->value) {
            lhs = lhs->next;
            rhs = rhs->next;
        }
        else {
            return false;
        }
    }
    if(lhs->value == rhs->value) {
        return true;
    }
    return false;
}

bool check_palindrome(Node* head, int n) {

    Node* last;
    Node* head_ptr = head;
    // Get a pointer to the last element 
    while(head_ptr->next != NULL) {
        head_ptr = head_ptr->next;
    }
    last = head_ptr;

    /* Now, starting in the middle, reverse the linked list.
       Assuming the first element is number 0, the middle
       element would be n / 2 if n is even and n / 2 + 1
       otherwise.
    */
    int middle;
    if (n % 2 == 0) {
        middle = n / 2;
    }
    else {
        middle = n / 2 + 1;
    }
    
    /* Make head_ptr point to the the element just before
       the middle element. If we have a linked list:
       1->2->3->4->NULL, we are trying to edit it so that
       it looks like 1->2->NULL & 4->3->NULL. In case of an
       odd number of elements, say 1->2->3->4->5->NULL,
       we want 1->2->3->NULL and 5->4->3->NULL. 
    */
    int counter = 0;
    head_ptr = head;
    while(counter != middle - 1) {
        head_ptr = head_ptr->next;
        counter = counter + 1;
    }
    if(n % 2 == 0) {
        Node* tmp = head_ptr;
        head_ptr = head_ptr->next;
        tmp->next = NULL;
    }
    
    // Acutal reversal happens here.
    Node* tmp1 = head_ptr->next;
    Node* tmp2 = head_ptr;
    Node* tmp3;
    head_ptr->next = NULL;
    while(tmp1 != NULL) {
        tmp3 = tmp1->next;
        tmp1->next = tmp2;
        tmp2 = tmp1;
        tmp1 = tmp3;
    }
    /* Uncomment these lines if you want to
       see what the individual linked lists
       look like now
    */
    //print_linked_list(head);
    //print_linked_list(last); 
    
    return compare_linked_lists(head, last);
}

int main() {

    Node* head;
    head = new Node;

    int len = take_input(head);
    if(len <= 0) {
        return 0;
    }

    cout << "Input sequence: ";
    print_linked_list(head);
    cout << "Length of input sequence: " << len << endl;
    check_palindrome(head, len) ? cout << "Input sequence is a palindrome" << endl : cout << "Input sequence is not a palindrome" << endl;

    return 0;
}

