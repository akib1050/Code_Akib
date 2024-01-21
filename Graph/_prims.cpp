#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;

#define ft first
#define sd second
#define flag bool fl=true

#define mod 1000000000000000007
#define N 1000001
#define MX 1000000001
#define MXX 1000000000000000001
#define csl cout<<"Case "<<qq<<":"<<endl;
#define T int tt, qq=0; cin>>tt; while(qq++<tt)


int main()
{
    int n, m;
    cin>>n>>m;

    vector<pair<int, int>>v[n+1];
    for(int i=0;i<m;i++)
    {
        int x, y, z;
        cin>>x>>y>>z;

        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }

    priority_queue<pair<int, int>>pq;
    pq.push({0, 1});


    int ans=0;
    bool vis[n+1]={};
    for(int i=0;i<n;i++)
    {
        int x=pq.top().sd;
        ans-=pq.top().ft;
        vis[x]=true;
        pq.pop();

        for(auto it=v[x].begin();it!=v[x].end();it++)
        {

            if(!vis[it->ft])
                pq.push({-it->sd, it->ft});

        }
    }
    cout<<ans<<endl;
}

/*

<----SAMPLE---->

4 5
1 2 10
1 3 20
1 4 25
2 4 20
3 4 30

<----OUTPUT---->

50

*/

