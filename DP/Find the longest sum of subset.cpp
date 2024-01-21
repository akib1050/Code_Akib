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


const int MAX = 1e5+10;

vector<int>v;
vector<int>ans;

int n,e=0,o=0,ar[100],xx=9;
void subSet(int x)
{
    if(x>=n)
    {

        int sum=0;
        for(auto i:v)
        {
            sum+=ar[i];

        }
        if(sum==xx)
        {
            // for(auto i:v)
            //  cout<<ar[i]<<" ";

            // cout<<endl;

            if(v.size()>ans.size())
                ans=v;
        }

        return;
    }

    v.push_back(x);
    subSet(x+1);

    v.pop_back();
    subSet(x+1);

}

int main()
{
    cin>>n;

    for(int i=0; i<n; i++)cin>>ar[i];

    subSet(0);

    for(int i=0; i<ans.size(); i++)cout<<ans[i]<<" ";



}
