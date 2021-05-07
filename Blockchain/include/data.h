#ifndef data_h
#define data_h
#include<vector>
#include<string>
#include<utility>
using namespace std;
    extern vector<pair<long double, long double>> public_key;
    vector<vector<long double>> get_data(string voter_id, string name, string party);

#endif