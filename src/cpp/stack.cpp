/*
Implement a stack in which push(),pop() and getMiddle()
has O(1) complexity at any point of time.
*/

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};
class Stack {
    private:
        Node* top;
        int size;
    public:
        Stack();
        void push(int i);
        int pop();
        int getMiddle();
        ~Stack();
};

Stack::Stack() {
    top = NULL;
    size = 0;
}
Stack::~Stack() {
    
}
void Stack::push(int i) {

    if(top == NULL) {
        top = new Node;
        top->value = i;
        top->next = NULL;
        size = size + 1;
        return;
    }

    Node* tmp = top;    
    top = new Node;
    top->value = i;
    top->next = tmp;
    size = size + 1;
}

int Stack::pop() {
    if(top == NULL) {
        return -1;
    }
    int ret_val = top->value;
    top = top->next;
    size = size - 1;
    return ret_val;
}
int Stack::getMiddle() {
    int middle_element = size / 2;
    Node* tmp = top;
    int counter = 0;
    while(counter < middle_element) {
        tmp = tmp->next;
        counter = counter + 1;
    }
    return tmp->value;
}
int main() {
    Stack s;
    s.push(1);
    s.push(2);
    cout << "Pushed: 1 and 2" << endl;
    cout << "Popped: " << s.pop() << endl;
    s.push(3);
    s.push(4);
    cout << "Pushed 3 and 4" << endl;
    cout << "Middle element: " << s.getMiddle() << endl;
    s.push(5);
    s.push(6);
    s.push(7);
    cout << "Pushed 5, 6 and 7" << endl;
    cout << "Middle element: " << s.getMiddle() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Middle element: " << s.getMiddle() << endl;
    return 0;
}
