#include<bits/stdc++.h>

using namespace std;

const int mxi=1e5+7;
vector<int>adj[mxi];
int visit[mxi];

void dfs(int u)
{
    visit[u]=1;

    for(auto i:adj[u])
    {
        if(visit[i]==0)
        {
            dfs(i);
        }
    }

}


int main()
{
    int node,edge;
    cin>>node>>edge;

    for(int i=0;i<edge;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }

    dfs(0);

    // All nodes are visited because we run dfs from a node of this graph

    for(int i=1;i<=node;i++)
    {
        cout<<i<<"'s Neighbours are: :";
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;

    }






}
