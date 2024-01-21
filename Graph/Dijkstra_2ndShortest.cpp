#include<bits/stdc++.h>
#include <iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
#include<bitset>
#include <cmath>
#include<string>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define T int t, q=0; scanf("%d", &t); while(q++<t)
#define ll long long
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define PI acos(-1)
#define vs    vector<string>
#define mx  5009
#define pi 3.14159265358979323846
#define fi(n, m) for(int i=n; i<=m; i++)
#define inf 999999999
#define mx 5e3
#define pii pair<int,int>
const int MAX = 1e5+10;

vector < pii > adj[MAX];
bool vis[2][MAX];
int dist[2][MAX];

vector<pii>v[MAX];

bool Dijkstra(int src,int n)
{
    for(int i=1; i<=n; i++)
    {
        dist[0][i]=dist[1][i]=MAX;
        vis[0][i]=vis[1][i]=0;
    }

    dist[0][src]=0;

    priority_queue<pair<int,pair<bool,int> > >pq;

    pq.push({0,{0,src}});
    dist[0][src] = 0;

    while(!pq.empty())
    {

        pair<int,pair<bool,int> >p=pq.top();

        pq.pop();
        int cur=p.second.second;
        int stt=p.second.first;

        if(vis[stt][cur]==1)continue;
        vis[stt][cur]=1;

        for(auto a:v[cur])
        {
            int b=a.first;
            int val=dist[stt][cur]+a.second;

            if(dist[1][b]>val && val>dist[0][b])
            {
                dist[1][b]=val;
                pq.push({-val,{1,b}});
            }
            else if(dist[0][b]>val)
            {
                dist[1][b]=dist[0][b];
                dist[0][b]=val;
                pq.push({-val,{0,b}});
                pq.push({-dist[1][b],{1,b}});


            }

        }
    }

}

int main()
{

    int n,m,a,c,b,k=0;

    T
    {
        k++;

        cin >> n >> m;

        for(int i=0; i<=n; i++)
        {
            v[i].clear();
        }


        while(m--)
        {
            cin>>a>>b>>c;
            v[a].push_back({b,c});
            v[b].push_back({a,c});
        }

        Dijkstra(1,n);

        cout<<"Case "<<k<<": ";
        cout<<dist[1][n]<<endl;
    }
}
