#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <map>

using namespace std;

bool mycompare (pair<int, int> i, pair<int, int> j) {

    if (i.second == j.second) return (i.first < j.first);

    return (i.second < j.second);
}

map< int, vector<int> > *get_wine_assignment(map< int, vector<int> > &wine_to_person) {

    vector< pair<int, int> > wine_to_num_persons;
    map< int, vector<int> > *person_to_assignment = new map< int, vector<int> >();
    map< int, int > person_to_num_wines;

    typedef map<int, vector<int> >::const_iterator map_iterator;
    typedef vector<int>::const_iterator vec_iterator;

    cout << "Total number of wines: " << wine_to_person.size() << endl;
    int count = 0;

    for (map_iterator iter = wine_to_person.begin(); iter != wine_to_person.end(); iter++ )
    {
        
        for (vec_iterator person_iter = iter->second.begin(); person_iter != iter->second.end(); person_iter++ )
        {
            if(person_to_num_wines.find(*person_iter) == person_to_num_wines.end()) {
                person_to_num_wines[*person_iter] = 1;
            }
            else {
                person_to_num_wines[*person_iter] += 1;
            }

        }
        count ++;
        if (count % 1000000 == 0) {
            cout << "Processed " << count << " wines" << endl;
        }
        pair <int,int> wine_and_num_persons = make_pair(iter->first, iter->second.size());
        wine_to_num_persons.push_back(wine_and_num_persons);

    }
    cout << "Created wine_to_num_persons" << endl;

    sort(wine_to_num_persons.begin(), wine_to_num_persons.end(), mycompare);

    cout << "Sorted wine_to_num_persons" << endl;

    typedef vector< pair<int, int> >::const_iterator vec_pair_iterator;
    for (vec_pair_iterator wine_iter = wine_to_num_persons.begin(); wine_iter != wine_to_num_persons.end(); wine_iter++ )
    {
        int wine_id     = wine_iter->first;
        vector<int> person_list = wine_to_person[wine_id];

        //cout << "Processing wine: " << wine_id << endl;

        typedef vector<int>::const_iterator vec_iterator;
        float metric_max = 0.0;
        int   person_max = -1;

        for(vec_iterator person_iter = person_list.begin(); person_iter != person_list.end(); person_iter++)
        {
            //cout << "Considering person: " << *person_iter << endl;
            /* For each person in person_list, calculate the ratio */
            if((*person_to_assignment).find(*person_iter) != (*person_to_assignment).end() &&
               (*person_to_assignment).find(*person_iter)->second.size() == 3) {
                continue;
            }
            int already_assigned = 0;

            if((*person_to_assignment).find(*person_iter) != (*person_to_assignment).end()) {
                already_assigned = (*person_to_assignment).find(*person_iter)->second.size();
            }
           
            int left_to_buy = 3 - already_assigned;
            float metric    = float(left_to_buy) / float(person_to_num_wines[*person_iter]);
            if (metric > metric_max) {
                person_max = *person_iter;
                metric_max = metric;
            }

        }
        if (person_max == -1) {
            //cout << "Not assigning this wine to anyone" << endl;
            continue;
        }
        else {
            //cout << "Assigning this wine to " << person_max << endl;
            if ((*person_to_assignment).find(person_max) == (*person_to_assignment).end()) {
                vector<int> wine_vec (1, wine_id);
                (*person_to_assignment)[person_max] = wine_vec;
            }
            else {
                (*person_to_assignment).find(person_max)->second.push_back(wine_id);
            }
            for(vec_iterator p_iter = wine_to_person[wine_id].begin(); p_iter != wine_to_person[wine_id].end(); p_iter++){
                person_to_num_wines[*p_iter] -= 1;
            }
        }

    }
    
    return person_to_assignment;
}

map< int, vector<int> > *get_file_data(char* filename) {
    
    map< int, vector<int> > *wine_to_person_list = new map< int, vector<int> >();
    ifstream input_file(filename);
    
    string delimiter = "\t";
    int person, wine;
    string line;
    int count = 0;

    while(getline(input_file, line))
    {

        person = atoi( line.substr(0, line.find(delimiter)).c_str() );
        wine   = atoi( line.substr(line.find(delimiter) + 1, line.length() - 1).c_str() );

        // Check if the person exists in the map
        if ((*wine_to_person_list).find(wine) == (*wine_to_person_list).end())
        {
            // Add the person to the map
            vector<int> person_list (1, person);
            (*wine_to_person_list)[wine] = person_list;
        }
        else
        {
            // Person already exists in the map, add it to the vector
            (*wine_to_person_list)[wine].push_back(person);
        } 
        count++;
        if (count % 1000000 == 0) {
            cout << "Processed " << count << " lines" << endl;
        }
        //cout << person << " " << wine << endl;
    }
    cout << "Broke out of loop" << endl;

    return wine_to_person_list;
}

int main(int argc, char *argv[]) {

    map< int, vector<int> > *wine_to_person;
    wine_to_person = get_file_data(argv[1]);

    cout << "Read all file data" << endl;

    map< int, vector<int> > *person_to_assignment;
    person_to_assignment = get_wine_assignment(*wine_to_person);

    cout << "Got person to assignment" << endl;

    typedef map<int, vector<int> >::const_iterator map_iterator;

    for (map_iterator iter = (*person_to_assignment).begin(); iter != (*person_to_assignment).end(); iter++ )
    {
        
        typedef vector<int>::const_iterator vec_iterator;
        for (vec_iterator wine_iter = iter->second.begin(); wine_iter != iter->second.end(); wine_iter++ )
        {
            cout << iter->first << "\t" << *wine_iter << endl;
        }
    }
    
}

