#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t , i,j,k,l,x,y;
    cin>>t;
    for(int q=1;q<=t;q++)
    {
        int n;
        cin>>n;
        map < int , char > mp;
        for(i=1;i<=n;i++)
        {
            cin>>x>>y;
            if(mp[x]=='v') mp[y]='l';
            else if(mp[x]=='l') mp[y]='v';
            else if(mp[y]=='l') mp[x]='v';
            else if(mp[y]=='v') mp[x]='l';
            else {mp[x]='l';mp[y]='v';}
        }
        map < int , char > :: iterator it;
        int sum1=0,sum2=0;
        for(it=mp.begin();it!=mp.end();it++)
        {
            if((*it).second=='l') sum1++;
            else if((*it).second=='v') sum2++;
        }
        cout<<"Case "<<q<<": "<<max(sum1,sum2)<<endl;
        mp.clear();
    }
}
