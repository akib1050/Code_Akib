#include<bits/stdc++.h>

#include<assert.h>
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
ll x,y,z,r,b=0,a,c=0,d=0,sum,ans,total,n,m,k,p,kase,i,r2,r3,u,v;
#define PI acos(-1)
#define vs    vector<string>
#define pi 3.14159265358979323846
const ll MAX = 1e5+10;
const ll MAX1 = 1e9+7;

#define pii pair<int,int>

vector<pii>edge[MAX];
vector<ll>cost;

int dis[100];
queue<int>q;
int nd,ed;
void bfs(int src)
{
    q.push(src);
    dis[src]=0;


    while(!q.empty())
    {
        int x=q.front();
        q.pop();

        for(int i=0; i<edge[x].size(); i++)
        {
            int y=edge[x][i].first;
            if(dis[y]>(dis[x]+edge[x][i].second))
            {
                dis[y]=(dis[x]+edge[x][i].second);
                q.push(y);

            }
        }


    }


}

int main()
{
    cin>>nd>>ed;
    for(int i=0; i<ed; i++)
    {
        int a,b,cos;
        cin>>a>>b>>cos;

        edge[a].push_back({b,cos});
        edge[b].push_back({a,cos});

    }

    for(int i=0;i<100;i++)dis[i]=MAX1;

    int src=1;

    bfs(src);

    int qq;
    cin>>qq;
    while(qq--)
    {
        int xx,totTime;
        cin>>xx>>totTime;
        int playingTime=totTime-(dis[xx]*2);
        if(playingTime<0)playingTime=0;

        cout<<playingTime<<endl;
    }




}


/*
5 5
1 2 2
2 3 4
3 4 5
4 5 1
1 4 7
3
4 20
5 21
3 5
*/

