#include <bits/stdc++.h>
using namespace std;
int n,m;
#define pii pair<int,int>
#define MAX 1e9+7
#define mx 2000006
#define fast ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)

vector<pii>edge[mx];

int dis[mx];
int path[mx];
queue<int>q;

void dijkstra(int src)
{
    dis[src]=0;
    q.push(src);

    while(!q.empty())
    {
        int x=q.front();
        q.pop();


        for(int i=0; i<edge[x].size(); i++)
        {
            int y=edge[x][i].first;
            int cost=edge[x][i].second;

            if(dis[y]>(dis[x]+cost))
            {
                dis[y]=dis[x]+cost;
                q.push(y);
                path[y]=x;
            }

        }
    }
}



int main()
{
    fast;
    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        edge[x].push_back({y,z});
        edge[y].push_back({x,z});

    }
    memset(path,-1,sizeof(path));
    memset(dis,MAX,sizeof(dis));
    int src;
    cin>>src;
    dijkstra(src);


    if(path[n]==-1)
    {
        cout<<-1<<endl;
    }
    else
    {
        vector<int>ans;
        for(int i=n; i>0;)
        {
            ans.push_back(i);
            i=path[i];
            //cout<<i<<" ";
        }

        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    }


}



