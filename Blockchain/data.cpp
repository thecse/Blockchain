#include<bits/stdc++.h>
#include "include/data.h"
#include "include/rsa.h"
using namespace std;

vector<pair<long double, long double>>public_key;
vector<vector<long double>>get_data(string voter_id, string name, string party){
    rsa r(rand()%40);
    vector<string> data={voter_id, name, "votes", "for", party};
    vector<vector<long double>> encdata(data.size());
    for(int i=0;i<data.size();i++){
        for(int j=0;j<data[i].size();j++){
            encdata[i].push_back(encrypt(int(data[i][j]), r.d, r.n));
        }
    }
    for(int i=0;i<data.size();i++){
        for(int j=0;j<data[i].size();j++)
            encdata[i][j]=encrypt(encdata[i][j], 19, 79523);
    }
    public_key.push_back(make_pair(r.e, r.n));
    return encdata;
}
