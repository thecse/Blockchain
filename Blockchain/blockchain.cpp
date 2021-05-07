#include "include/blockchain.h"
using namespace std;

blockchain::blockchain(){
    chain.emplace_back(block(0, "Genesis", "Block", "N/A"));
    difficulty=6;
}

void blockchain::add_block(block new_block){
    new_block.prev_hash=getlastblock().gethash();
    new_block.mine_block(difficulty);
    new_block.print_block();
    chain.push_back(new_block);
}
block blockchain::getlastblock(){
    return chain.back();
}
