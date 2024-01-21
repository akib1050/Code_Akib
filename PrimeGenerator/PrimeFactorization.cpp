#include<bits/stdc++.h>

using namespace std;

#define T int t, q=0; scanf("%d", &t); while(q++<t)
#define ll long long
//#define MAX 32000
//SET PRECIOSION   cout << fixed ;  cout << setprecision(n) << ans << endl;

vector<ll>primes;

void seive(int MAX)
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

    for(int i=3; i<MAX; i+=2)if(prime[i])primes.push_back(i);
}

int main()
{

    T
    {
        int n;
        cin>>n;
        int m=sqrt(n)+1;
        seive(m);
        vector<ll>fact;

        for(int i=0; primes[i]*primes[i]<=n; i++)
        {
            while(n%primes[i]==0)
            {
                n/=primes[i];
                fact.push_back(primes[i]);
            }
        }

        for(int i=0; i<fact.size(); i++)cout<<fact[i]<<" ";
        if(n>1)cout<<n;

        cout<<endl;
    }
}
