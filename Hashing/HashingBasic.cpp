#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
#include<string.h>

using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define T int t, q=0; scanf("%d", &t); while(q++<t)
#define N 200010
#define inf 2000000000
#define mod 1000000007

typedef long long ll;

int n;
map<char,int>mp;
double a[3000], dp[3000][3000];
const int mx=1e7;


int ar[mx];
ll tow(ll a, ll b)
{
    ll ans = 1;
    for (int i = 0; i < b; i++)
    {
        ans *= a;
    }
    return ans;
}


int hashVal(string s)
{
    int n=s.size();

    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum+=(mp[s[i]]*tow(27,i));
        //cout<<mp[s[i]]<<endl;
    }
    return sum;

}


ll bigMod(ll a, ll b, ll M)
{
    if(b == 0) return 1 % M;
    ll x = bigMod(a, b/2, M);
    x = (x*x)%M;
    if(b%2 == 1) x = (x*a)%M;
    return x;
}

int hashVal2(string s) // Getting Hash value
{
    int n=s.size();

    int sum=0,x=1;
    for(int i=0; i<n; i++)
    {

        sum+=( (s[i]-96)*x)%mod;
        ar[i]=sum;
        x*=31;
    }
    return sum;

}

ll bigMOD(ll a, ll b, ll c)
{
    if(b==0)return 1%c;
    ll x=bigMOD(a,b/2,c);

    x=(x*x)%c;
    if(b%2)x=(x*a)%c;
    return x;
}


ll cumSum(ll l,ll r)
{
    if(l==0)return ar[r];
    else return ( (ar[r]-ar[l-1])+mod)%mod;
}



int main()
{
    string c="abcdefghijklmnopqrstuvwxyz";
    for(int i=0; i<26; i++)
    {
        mp[c[i]]=i+1;
    }

    ll b[100005],y=1; // all power of 27 is in an array
    for(int i=0; i<100005; i++)
    {
        b[i]=y;
        y=(y*31)%mod;
    }


    ll m[100005]; //all mod in an array
    for(int i=0; i<100005; i++)
    {
        m[i]=bigMOD(b[i],mod-2,mod);
    }



    string ss;
    cin>>ss;
    int h=hashVal2(ss);
    cout<<h<<endl;
//        int l=1,r=4;
//        cout<<cumSum(l,r)/tow(27,l)<<endl;
//        cout<<hashVal("bcde")<<endl;


    for(ll i=0; i<ss.size(); i++)
    {
        for(ll j=i; j<ss.size(); j++)
        {
            ll x=cumSum(i,j);
            y=m[i];
            x=(x*y)%mod;
            cout<<i<<" "<<j<<" = "<<x<<endl;
        }
    }


    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {

        ll a,b,c,d;
        cin>>a>>b>>c>>d;

        ll xx=cumSum(a,b);
        ll x1=m[a];
        xx=(xx*x1)%mod;

        ll yy=cumSum(c,d);
        ll x2=m[c];
        yy=(yy*x2)%mod;




        cout<<a<<" "<<b<<" = "<<xx<<endl;
        cout<<c<<" "<<d<<" = "<<yy<<endl;


        if(xx==yy)
        {
            cout<<"YES"<<endl;

        }
        else cout<<"NO"<<endl;

    }


}
