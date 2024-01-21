#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}

int lcm(int a,int b)
{
    if(b==0)return a;
    return (a/(gcd(a,b))*b);
}

int main()
{
    int x,y;
    cin>>x>>y;

    cout<<gcd(x,y)<<endl;
    cout<<lcm(x,y)<<endl;

}
