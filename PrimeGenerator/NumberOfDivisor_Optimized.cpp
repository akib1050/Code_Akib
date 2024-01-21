#include<bits/stdc++.h>

using namespace std;

#define T int t, q=0; scanf("%d", &t); while(q++<t)
#define ll long long
//#define MAX 32000
//SET PRECIOSION   cout << fixed ;  cout << setprecision(n) << ans << endl;

vector<ll>primes;

void seive(ll MAX)
{
    bool prime[MAX+1];

    memset(prime,true,MAX);
    prime[0] = false;
    prime[1] =false;

    for(ll i=3; i<=(MAX); i+=2)
        if(prime[i])
        {
            for (ll j = i*i; j <= MAX; j += i)
                prime[j] = false;
        }

    primes.push_back(2);

    for(ll i=3; i<MAX; i+=2)if(prime[i])primes.push_back(i);
}

int main()
{
    seive(1000001);
    T
    {
        ll n;
        cin>>n;

        ll ans=1;

        ll countDivisor=1;
        for(ll i=0; primes[i]*primes[i]<=n; i++)
        {
            ll c=1;
            while(n%primes[i]==0)
            {
                n/=primes[i];
                c++;
            }
            countDivisor*=c;
        }

        if(n>1)ans=2;
        countDivisor*=ans;

        cout<<countDivisor<<endl;
    }
}
