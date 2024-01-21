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
#define nf 100000
#define vs    vector<string>
#define pi 3.14159265358979323846


int level[100];
int path[100];
vector<int>adj[100];
vector<int>edge[100];
vector<int>cost[100];

void bfs(int src)
{
    queue<int>q;
    q.push(src);
    level[src]=0;

    while(!q.empty())
    {
        u=q.front();
        q.pop();

        for(int i=0; i<edge[u].size(); i++)
        {
            int v=edge[u][i];
            if(level[v]==-1)
            {
                level[v]=level[u]+1;
                q.push(v);
                path[v]=u;
            }

        }

    }

}


int main()
{
    int nodeNum,edgeNum;
    cin>>nodeNum>>edgeNum;
    memset(level,-1,sizeof(level));
    memset(path,-1,sizeof(path));

    for(int i=0; i<edgeNum; i++)
    {
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    cout<<endl;

    for(int i=1; i<=nodeNum; i++)
    {
        for(int j=0; j<edge[i].size(); j++)
            cout<<edge[i][j]<<" ";

        cout<<endl;
    }
    cout<<endl;

    int nd;
    cin>>nd;
    bfs(nd);

    //for(int i=1;i<=path;i++)cout<<level[i]<<endl;
    vector<int>ans;
    //nodeNum=6;
    for(int i=nodeNum; i>0;)
    {
        ans.push_back(i);
        i=path[i];
       // cout<<i<<" ";
    }

    reverse(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); i++)cout<<ans[i]<<" ";


}


/*

6 8
1 2
1 4
2 4
2 5
4 5
5 3
3 6
6 6
*/

