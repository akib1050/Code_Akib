#include<bits/stdc++.h>

using namespace std;

#define T int t, q=0; scanf("%d", &t); while(q++<t)
#define ll long long
#define MAX 32000


bool prime[MAX+1];
ll prime1[MAX+1];
vector<ll>vect;


void seive()
{
    memset(prime,true,MAX);
    prime[0] = false;
    prime[1] =false;

    for(ll i=3; i<=(MAX); i+=2)
        if(prime[i])
        {
            for (ll j = i*i; j <= MAX; j += i)
                prime[j] = false;
        }

    vect.push_back(2);

    for(int i=3; i<MAX; i+=2)if(prime[i])vect.push_back(i);
}

void segSeive(ll l,ll r)
{
    ll x=r-l+1;

    bool segPrime[x];
    memset(segPrime,true,x);

    for(int i=0; vect[i]*vect[i]<=r; i++)
    {
        ll current_prime=vect[i];

        ll base = (l/current_prime)*current_prime;

        if(base<l)base+=current_prime;

        for(ll j=base; j<=r; j+=current_prime)
        {
            segPrime[j-l]=false;
        }
        if(base==current_prime)segPrime[base-l]=true;
    }
    for(int i=0; i<x; i++)if(segPrime[i])cout<<i+l<<endl;
}


//SET PRECIOSION   cout << fixed ;  cout << setprecision(n) << ans << endl;


int main()
{


    seive();
    T
    {
        ll r,l;
        cin>>l>>r;
        if(l==1)l++;

        segSeive(l,r);
        cout<<endl;
    }

}
