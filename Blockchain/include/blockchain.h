#ifndef blockchain_h
#define blockchain_h
#include "block.h"
#include <vector>
using namespace std;
class blockchain{
    
    public:
    
    blockchain();
    
    void add_block(block new_block);
    
    long long difficulty;
    
    vector<block> chain;
    
    block getlastblock();
};
#endif