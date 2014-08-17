/*
You have a bunch of ants on a meter stick, each walking 1cm/s in some direction.
If an ant hits the end of the stick, it falls off. If two ants collide,
they both reverse direction.

Q1: Given the starting positions and directions of all the ants, how long until the last ant falls off?
Q2: Given the starting positions and directions of all the ants, which ant(s) are the last to fall off?

*/
#include <iostream>
#include <vector>

using namespace std;

#define RIGHT 'r'
#define LEFT  'l'

void walk(vector<int>& pos, vector<char>& dirn, int& time_elapsed) {
    vector<bool> fallen_ants;
    fallen_ants.resize(pos.size(), false);
    while(true) {
        bool no_ants_left = true;
        // Scan pos and check if all ants have gone off the stick
        for(vector<int>::iterator it = pos.begin(); it != pos.end(); it++) {
            if(*it >= 0 and *it <= 100) {
                no_ants_left = false;
                break;
            }
        }
        if(no_ants_left) {
            break;
        }
        time_elapsed++;
        // Reverse directions if two ants are occupying the same position
        for(vector<int>::iterator it1 = pos.begin(); it1 != pos.end(); it1++) {
            for(vector<int>::iterator it2 = pos.begin(); it2 != pos.end(); it2++) {
                
                if(*it1 == *it2 and it1 < it2) {
                    int ant_1_idx = it1 - pos.begin();
                    int ant_2_idx = it2 - pos.begin();
                    
                    cout << "Ants " << ant_1_idx + 1 << " and " << ant_2_idx + 1 << " collided at time: " << time_elapsed << " and position: " << *it1 << endl;
                    dirn[ant_1_idx] = dirn[ant_1_idx] == RIGHT ? LEFT : RIGHT;
                    dirn[ant_2_idx] = dirn[ant_2_idx] == RIGHT ? LEFT : RIGHT;
                }
            }
        }

        // Move all ants one step
        for(vector<int>::iterator it = pos.begin(); it != pos.end(); it++) {
            int ant_pos = it - pos.begin();
            pos[ant_pos] = dirn[ant_pos] == RIGHT ? pos[ant_pos] + 1 : pos[ant_pos] - 1;
            if(pos[ant_pos] < 0 or pos[ant_pos] > 100) {
                if(!fallen_ants[ant_pos]) {
                    cout << "Ant " << ant_pos + 1 << " has fallen off the stick at " << time_elapsed << endl;
                    fallen_ants[ant_pos] = true;
                }
            }
        }

    }
}

int main() {
    int n;
    cout << "Enter the number of ants: ";
    cin >> n;

    vector<int> ants_pos;
    vector<char> ants_dirn;

    int tmp_pos;
    char tmp_dirn;

    for(int i = 0;i < n;i ++) {
        cout << "Position of ant " << i + 1 << " (0 <= pos <= 100)" << ": ";
        cin >> tmp_pos;
        if(tmp_pos < 0 or tmp_pos > 100) {
            cerr << "Incorrect position, should be between 0 and 100 (both inclusive)" << endl;
            exit(1);
        }
        ants_pos.push_back(tmp_pos);
        cout << "Direction of ant " << i + 1 << " (l/r): ";
        cin >> tmp_dirn;
        if(tmp_dirn != 'l' and tmp_dirn != 'r') {
            cerr << "Incorrect direction, should be one of (l|r)" << endl;
            exit(1);
        }
        ants_dirn.push_back(tmp_dirn);
    }

    int time_until_empty = 0;
    walk(ants_pos, ants_dirn, time_until_empty);
    cout << "It will take " << time_until_empty << " seconds for the stick to be empty" << endl; 
}

