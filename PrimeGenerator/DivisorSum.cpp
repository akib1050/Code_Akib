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


ll divisorSum(ll n)
{
    ll total = 1;
    for (int i = 0; i < primes.size(); i++)
    {
        if (n % primes[i] == 0)
        {
            int cnt = 1;
            while (n % primes[i] == 0)
            {
                n /= primes[i];
                cnt++;
            }
            //cout<<cnt<<endl;
            total *= (pow(primes[i],cnt)-1)/(primes[i]-1);
        }
    }
    return total;
}

int main()
{
    ll mx=500001;
    mx=sqrt(mx)+1;
    seive(mx);
    T
    {
        ll n;
        cin>>n;

        ll total=divisorSum(n);
        cout<<total<<endl;
    }
}
