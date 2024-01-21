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
#define mx (int)1e6+10


int main()
{

    ll n;
    cin>>n;

    ll ar[n];
    for(int i=0;i<n;i++)cin>>ar[i];

    int val;
    cin>>val;

    int l=0,r=n-1;
    int mid,ans=n;

    while(l<=r)
    {
        mid=(l+r)/2;

        if(ar[mid]<=val)
        {
           l=mid+1;
        }
        else
        {
            ans=min(mid,ans);
            r=mid-1;
        }
    }

    cout<<ans<<endl;


    return 0;
}
/*
7
1 2 2 3 3 3 4
3

 */
