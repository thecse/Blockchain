#include <bits/stdc++.h>
#include "include/blockchain.h"
#include "include/block.h"
#include "include/rsa.h"
#include "include/data.h"
using namespace std;
int main(){
    blockchain bchain=blockchain();
    cout<<"mining block 1\n";
    bchain.add_block(block(1, "123QWE", "Modi", "AAP"));

    cout<<"mining block 2\n";
    bchain.add_block(block(2, "234WER", "Kejriwal", "BSP"));
    
    return 0;
   
}