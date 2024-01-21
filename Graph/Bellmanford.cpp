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
//ll x,y,z,r,b=0,a,c=0,d=0,v,u,f,sum,ans,total,n,m,k,p,kase,i,r2,r3;
#define PI acos(-1)
#define MX 1000000001
#define MAX 1000006
#define vs    vector<string>
#define pi 3.14159265358979323846
#define rep(i,n) for(int i=0; i<(n); i++)
#define ll long long
#define pii pair<int,int>
#define mx 10000
#define inf 1e9+10

int n,m;

bool bellman( pair<pii,int>ed[], int dis[] )
{
    bool f;

    for(int i=0; i<n; i++)
    {
        f=false;
        for(int j=0; j<m; j++)
        {
            int agerNode=ed[j].first.first;
            int newNode=ed[j].first.second;
            int cost=ed[j].second;

            if(dis[newNode]>(dis[agerNode]+cost))
            {
                f=true;
                dis[newNode]=dis[agerNode]+cost;

            }

        }

    }

    return f;
}


int main()
{
    T
    {
        cin>>n>>m;

        pair<pii,int>ed[m];
        int dis[n]={};
        for(int i=1;i<n;i++) dis[i]=inf;

        for(int i=0; i<m; i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            ed[i]= {{a, b}, c};
        }
       // memset(dis,inf,sizeof(dis));

        bool f=bellman(ed,dis);

        if(f)cout<<"possible"<<endl;
        else cout<<"not possible"<<endl;

    }


}

