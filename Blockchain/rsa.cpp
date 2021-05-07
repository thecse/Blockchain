#include<bits/stdc++.h>
#include "include/rsa.h"
using namespace std;

rsa::rsa(int x){
    int prime[]={67, 71,	73,	79,	83,	89,	97,	101,	103,	107,	109,
                  113,	127,	131,	137,	139,	149,	151,	157,	163,	167,
                  173,	179,	181,	191,	193,	197,	199,	211,	223,	227,
                  229,	233,	239,	241,	251,	257,	263,	269,	271};
    
    p=prime[x];
    q=prime[x+1];
    n=p*q;
    phi=(p-1)*(q-1);
    e=7;
    while(e<phi){
      if(gcd(e, phi)==1)
        break;
      else
        e++;
    }
    k=1;
    while(1){
      d=((k*phi)+1)/e;
      if(abs(d-int(d))==0)
        break;
      else k++;
    }
}


long double encrypt(long long data, long double e, long double n){
    long double enc=1;
    for(long long i=0;i<e;i++){
        enc=enc*data;
        enc=fmod(enc, n);
    }
    return enc;
}

long double decrypt(long double enc, long double d, long double n){
    long double dec=1;
    for(long long i=0;i<d;i++){
        dec=dec*enc;
        dec=fmod(dec, n);
    }
    return dec;
}

long int rsa::gcd(long int a, long int b){
    long long int temp;
    if(b==0)
        return a;
    return gcd(b, a%b);
}
