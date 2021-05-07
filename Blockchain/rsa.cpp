#include<bits/stdc++.h>
#include "include/rsa.h"
using namespace std;

rsa::rsa(int x){
    int prime[]={67, 71,	73,	79,	83,	89,	97,	101,	103,	107,	109,
                  113,	127,	131,	137,	139,	149,	151,	157,	163,	167,
                  173,	179,	181,	191,	193,	197,	199,	211,	223,	227,
                  229,	233,	239,	241,	251,	257,	263,	269,	271,	277,
                  281,	283,	293,	307,	311,	313,	317,	331,	337,	347,
                  349,	353,	359,	367,	373,	379,	383,	389,	397,	401,
                  409,	419,	421,	431,	433,	439,    443,	449,	457,	461,
                  463,	467,	479,	487,	491,	499,	503,	509,	521,	523,
                  541,	547,	557,	563,	569,	571,	577,	587,	593,	599,
                  601,	607,	613,	617,	619,	631,	641,	643,	647,    653,
                  659,	661,	673,	677,	683,	691,	701,	709,	719,	727,
                  733,	739,	743,	751,	757,	761,    769,    773,	787,	797,
                  809,	811,	821,	823,	827,	829,	839,	853,	857,	859,
                  863,	877,	881,	883,	887,	907,	911,	919,	929,	937,
                  941,	947,	953,	967,	971,	977,	983,	991,	997};
    
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