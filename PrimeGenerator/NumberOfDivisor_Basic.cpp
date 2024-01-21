#include<bits/stdc++.h>

using namespace std;


int NOD(int n)
{
    int c=0;
    for(int i=1;i*i<=n;i++)
    {
        if(n==i*i)c+=1;
        else if(n%i==0)c+=2;
    }
    return c;
}


int main()
{
    int n,m;
    cin>>n;
    cout<<NOD(n)<<endl;


}
