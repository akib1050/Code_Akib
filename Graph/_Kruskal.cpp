#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;

#define ft first
#define sd second
#define mod 1000000000000000007
#define N 1000001
#define MX 1000000001
#define MXX 1000000000000000001
#define csl cout<<"Case "<<qq<<":"<<endl;
#define T int tt, qq=0; cin>>tt; while(qq++<tt)


int p[N];
int get(int x)
{
    if(x==p[x]) return x;
    else return p[x]=get(p[x]);
}

int main()
{

    int n,m;
    cin>>n>>m;

    vector<pair<int, pair<int, int>>>v;
    for(int i=0; i<=n; i++) p[i]=i;
    for(int i=0; i<m; i++)
    {
        int x, y, z;
        cin>>x>>y>>z;
        v.push_back({z, {x, y}});
    }
    sort(v.begin(), v.end());

    int cnt=0, ans=0;
    for(int i=0; i<v.size() && cnt<n-1; i++)
    {

        int x=get(v[i].sd.ft);
        int y=get(v[i].sd.sd);

        if(x!=y)
        {
            p[x]=y;
            ans+=v[i].ft;
            cnt++;
        }
    }
    cout<<ans<<endl;

}

