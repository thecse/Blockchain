#ifndef rsa_h
#define rsa_h
#include<utility>
class rsa{
    long long p, q;
    public:
    long double d, n, phi, e, k;

    rsa();

    rsa(int x); 
    
    long int gcd(long int a, long int b);
};

long double encrypt(long long data, long double e, long double n);
    
long double decrypt(long double enc, long double d, long double n);
#endif