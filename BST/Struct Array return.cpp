#include<bits/stdc++.h>

using namespace std;
struct arr
{
    int id;
    char section;
    string name;
};

void print(struct arr ptr[])
{
    for(int i=0;i<3;i++)
    {
        cout<<ptr[i].name<<" "<<ptr[i].id<<" "<<ptr[i].section<<endl;
    }

}


int main()
{
    struct arr ar[3];
    for(int i=0;i<3;i++)
    {
        cin>>ar[i].id>>ar[i].section>>ar[i].name;
    }

    print(ar);

}
