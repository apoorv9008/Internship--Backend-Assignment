#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

void multiply(ll F[2][2], ll M[2][2]);

void power(ll F[2][2], ll n);

ll largefibo(ll n)              //function to calculate fibonacci series till n'th number
{
    ll F[2][2] = {{1,1},{1,0}};
    if (n == 0)
        return 0;
    if (n == 1)
        return 2;
    if (n == 2)
        return 3;
    power(F, n-2);
    return (F[0][0]*3+F[0][1]*2)%MOD;
}

void power(ll F[2][2], ll n)    //function to increase the power exponentially
{
    if( n == 0 || n == 1)
        return;
    ll M[2][2] = {{1,1},{1,0}};

    power(F, n/2);
    multiply(F, F);

    if (n%2 != 0)
        multiply(F, M);
}

void multiply(ll F[2][2], ll M[2][2])      //function to multiply (2X2) matrix to itself to get the resultant value
{
    ll x =  ((F[0][0]*M[0][0])%MOD + (F[0][1]*M[1][0])%MOD)%MOD;
    ll y =  ((F[0][0]*M[0][1])%MOD + (F[0][1]*M[1][1])%MOD)%MOD;
    ll z =  ((F[1][0]*M[0][0])%MOD + (F[1][1]*M[1][0])%MOD)%MOD;
    ll w =  ((F[1][0]*M[0][1])%MOD + (F[1][1]*M[1][1])%MOD)%MOD;

    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin >> n;
        cout << largefibo(n) << endl;
    }
    return 0;
}
