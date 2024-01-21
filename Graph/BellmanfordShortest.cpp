#include <bits/stdc++.h>
using namespace std;
vector<int>vc[100],v[100];
int cost[100];
int parent[100];
int n,m;
void bellman()
{
    cost[0]=0;
    for(int i=0; i<n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            for(int k=0; k<v[j].size(); k++)
            {
                int u=j,V=v[j][k];
                if(cost[V]>cost[u]+vc[j][k])
                {
                    cost[V]=cost[u]+vc[j][k];
                    parent[V]=u;
                }
            }
        }
    }

    bool f=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<v[i].size(); j++)
        {
            int u=i,V=v[i][j];
            if(cost[V]>cost[u]+vc[i][j])f=1;
        }
        if(f)break;
    }
    if(f)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main()
{
    int x,y,c;
    cin>>n>>m;
    for(int i=1; i<=n; i++)cost[i]=1e15;
    for(int i=0; i<m; i++)
    {
        cin>>x>>y>>c;
        v[x].push_back(y);
        vc[x].push_back(c);
        v[y].push_back(x);
        vc[y].push_back(c);
    }
    bellman();


}
