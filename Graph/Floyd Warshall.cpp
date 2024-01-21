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
#define ll long long
#define N 200010
#define inf 20000000

const int MAX = 1e5+10;
ll h[MAX];
ll dp[MAX];
int dist[100][100];


int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i!=j)dist[i][j]=inf;
        }
    }


    for(int i=1; i<=m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=w;
    }


    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(dist[i][k]+dist[k][j]<dist[i][j])dist[i][j]=dist[i][k]+dist[k][j];

            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }

}

/*
------Input------
4 6
4 1 20
4 3 8
1 2 3
2 1 2
2 3 2
3 2 5


*/
