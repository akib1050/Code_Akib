#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define good ios_base::sync_with_stdio(0);cin.tie(0)
#define pb(x) push_back(x);
#define N 100001
#define MX 1000000001
#define sc(n) int n; scanf("%d",&n);1
#define T int t, q=0; scanf("%d", &t); while(q++<t)



const int mod=1e9+7;
const int mx=1e6+7;


int recursion(int a, int b, int modd)
{
    if(b==1)return a%modd;
    else
    {
        if( (b&1)==1 )
        {

            int y=(recursion(a,b-1,modd)*a)%modd;
            return y;
        }
        else
        {
            ll x=recursion( a,b/2,modd );
            x=(x*x)%modd;
            return x;
        }
    }



}

int main()
{
   int  n, m,a, b, c;

   cin>>a>>b>>m;


   int ans=recursion(a,b,m);
   cout<<ans;



}
