#ifndef block_h
#define block_h
#include<vector>
#include<utility>
#include<string>
using namespace std;
class block{
    public:
    block(long long index_in, string voter_id, string name, string party);
    long long index, nonce;
    vector<vector<long double>> data;
    string hash, prev_hash;
    time_t ctime;
    string gethash();
    string calculate_hash();
    void print_block();
    void mine_block(long long difficulty);
};
#endif
