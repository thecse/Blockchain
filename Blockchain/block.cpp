#include<bits/stdc++.h>
#include "include/sha256.h"
#include "include/data.h"
#include "include/rsa.h"
#include "include/block.h"
using namespace std;
block::block(long long index_in, std::string voter_id, std::string name, std::string party){
    index=index_in;
    data=get_data(voter_id, name, party);
    nonce=-1;
    ctime=time(nullptr);
}
string block::gethash(){
    return hash;
}
void block::mine_block(long long difficulty){
    string str="";
    for(int i=0;i<difficulty;i++)str=str+'0';
    while(hash.substr(0, difficulty)!=str){
        nonce++;
        hash=calculate_hash();
    }
    cout<<"Block Mined :"<<endl;
}
string block::calculate_hash(){
    string hashdata="";
    hashdata=hashdata+to_string(ctime)+to_string(nonce)+to_string(index)+prev_hash;
    for(long long i=0;i<data.size();i++)
        for(long long j=0;j<data[i].size();j++)
            hashdata=hashdata+to_string(int(data[i][j]));
    
    return sha256(hashdata);
}
void block::print_block(){
    cout<<"index: "<<index<<endl;
    cout<<"previous hash: "<<prev_hash<<endl;
    cout<<"hash: "<<hash<<endl;
    cout<<"time: "<<ctime<<endl;
    cout<<"encrypted data: ";
    for(int i=0;i<data.size();i++){
        for(int j=0;j<data[i].size();j++)
            cout<<data[i][j];
        cout<<" ";
    }

    for(int i=0;i<data.size();i++){
        for(int j=0;j<data[i].size();j++){
            data[i][j]=decrypt(data[i][j], 20779, 79523);
        }
    }
    for(int i=0;i<data.size();i++){
        for(int j=0;j<data[i].size();j++)
            data[i][j]=decrypt(int(data[i][j]), public_key[index].first, public_key[index].second);
    }
    cout<<endl<<"decrypted data: ";
    for(int i=0;i<data.size();i++){
        for(int j=0;j<data[i].size();j++)
            cout<<char(data[i][j]);
        cout<<" ";
    }
    cout<<endl;
    cout<<"====================================================================================================\n";
}

