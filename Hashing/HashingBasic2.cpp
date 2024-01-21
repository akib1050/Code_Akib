#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int sz = 1e6+9;
ll modInverse(ll a, ll m)
{
	ll m0 = m;
	ll y = 0, x = 1;

	if (m == 1)
	return 0;

	while (a > 1)
	{
		ll q = a / m;
		ll t = m;

		m = a % m, a = t;
		t = y;

		y = x - q * y;
		x = t;
	}

	if (x < 0)
	x += m0;

	return x;
}

ll p_pow[sz],modIn[sz];
ll hash_val[sz];
const ll p = 31;
const ll m = 1e9 + 7;
void compute_hash(string const& s)
{
    hash_val[0] = s[0] - 'a' + 1;
    for (ll i =1;i<s.size();i++)
    {
        hash_val[i] = (hash_val[i-1] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    }
}
ll get_hash(string const& s)
{
    ll x = s[0] - 'a' + 1;
    for (ll i =1;i<s.size();i++)
    {
        x = (x + (s[i] - 'a' + 1) * p_pow[i]) % m;

    }
    return x;
}
void powCalc(ll n)
{
    p_pow[0] = 1;
    for(ll i=1;i<=n;i++)
    {
        p_pow[i] = (p*p_pow[i-1])%m;
        modIn[i]  =  modInverse(p_pow[i],m);
    }
}
ll query_hash(ll l,ll r)
{
    if(r<l)
        return 0;
    if(l==0)
        return hash_val[r];
    else return ((((hash_val[r] - hash_val[l-1])+m)%m)*modIn[l])%m;
}
ll mergeHash(ll l1,ll r1,ll l2,ll r2)
{
    return (query_hash(l1,r1)   + query_hash(l2,r2)*p_pow[r1-l1+1])%m;
}
int main()
{
    ll i,n,t,k,j,x=0,y=0;
    string str;
    cin>>str;
    n = str.size();
    powCalc(n);
    compute_hash(str);
    for(i=0;i<=n;i++)
    {
        cout<<i<<" "<<hash_val[i]<<endl;
    }
    cout<<query_hash(2,3)<<endl;
    cout<<query_hash(0,1)<<endl;
    return 0;
}
