#include <iostream>
using namespace std;
/*

Check if the two input rectangles overlap

Input:
r1_x1
r1_y1
r1_x2
r1_y2
...
...similar for r2

*/
typedef struct {
    float x;
    float y;
} Point;

class Rectangle {
public:
Point p1, p2, p3, p4;
};

bool check_point_in_rectangle(Rectangle r, Point p) {
    float ab_x, ab_y;
    ab_x = r.p2.x - r.p1.x;
    ab_y = r.p2.y - r.p1.y;

    float bc_x, bc_y;
    bc_x = r.p3.x - r.p2.x;
    bc_y = r.p3.y - r.p2.y;

    float ap_x, ap_y;
    ap_x = p.x - r.p1.x;
    ap_y = p.y - r.p1.y;

    float bp_x, bp_y;
    bp_x = p.x - r.p2.x;
    bp_y = p.y - r.p2.y;

    float dot_ab_ap, dot_ab_ab, dot_bc_bp, dot_bc_bc;
    dot_ab_ap = ab_x * ap_x + ab_y * ap_y;
    dot_ab_ab = ab_x * ab_x + ab_y * ab_y;
    dot_bc_bp = bc_x * bp_x + bc_y * bp_y;
    dot_bc_bc = bc_x * bc_x + bc_y * bc_y;

    if(dot_ab_ap >= 0 && dot_ab_ab >= dot_ab_ap && dot_bc_bp >= 0 && dot_bc_bc >= dot_bc_bp) {
        return true;
    }
    return false;
}
bool check_intersection(Rectangle r1, Rectangle r2) {
    bool p1_in_r1, p2_in_r1, p3_in_r1, p4_in_r1;

    p1_in_r1 = check_point_in_rectangle(r1, r2.p1);
    p2_in_r1 = check_point_in_rectangle(r1, r2.p2);
    p3_in_r1 = check_point_in_rectangle(r1, r2.p3);
    p4_in_r1 = check_point_in_rectangle(r1, r2.p4);

    if(p1_in_r1 || p2_in_r1 || p3_in_r1 || p4_in_r1) {
        return true;
    }
    return false;
}
int main() {
    cout << "Taking input for rectangle ABCD" << endl;
    cout << "Please enter the co-ordinates of A: " << endl;
    Rectangle r1;
    cin >> r1.p1.x;
    cin >> r1.p1.y;

    cout << "Please enter the co-ordinates of B: " << endl;
    cin >> r1.p2.x;
    cin >> r1.p2.y;

    cout << "Please enter the co-ordinates of C: " << endl;
    cin >> r1.p3.x;
    cin >> r1.p3.y;

    cout << "Please enter the co-ordinates of D: " << endl;
    cin >> r1.p4.x;
    cin >> r1.p4.y;
 
    cout << "Taking input for rectangle PQRS" << endl; 
    cout << "Please enter the co-ordinates of P: " << endl;
    Rectangle r2;
    cin >> r2.p1.x;
    cin >> r2.p1.y;
        
    cout << "Please enter the co-ordinates of Q: " << endl;
    cin >> r2.p2.x;
    cin >> r2.p2.y;

    cout << "Please enter the co-ordinates of R: " << endl;
    cin >> r2.p3.x;
    cin >> r2.p3.y;

    cout << "Please enter the co-ordinates of S: " << endl;
    cin >> r2.p4.x;
    cin >> r2.p4.y;
    
    bool intersect = check_intersection(r1, r2);
    if(intersect) {
        cout << "The two rectangles intersect" << endl;
    }
    else {
        cout << "The two rectangles don't intersect" << endl;
    }
    return 0;
}

