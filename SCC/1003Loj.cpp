#include<bits/stdc++.h>
using namespace std;
#define SIZE 10010
vector <  int  > arr[10010];
int visited[10010];
int x;
bool instack[10010];

bool isCyclicUtil(int v)
{
    if(visited[v] == 0)
    {

        visited[v] = 1;
        instack[v] = true;
       vector <  int  >::iterator i;
        for(i = arr[v].begin(); i != arr[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i) )
                return true;
            else if (instack[*i])
                return true;
        }

    }
    instack[v] = false;
    return false;
}

bool isCycle()
{
    memset(visited,0,sizeof(visited));
 //   memset(instack,false,sizeof(instack));
    for(int i=0;i<x;i++)
    {
        instack[i]=false;
    }
    for(int i = 0; i < x; i++)
        if (isCyclicUtil(i))
            return true;

    return false;
}
int main()
{
    int t,i,j,k,l,m,n;
    string s1,s2;
    cin>>t;
    map < string , int > mp;
    for(int qq=1;qq<=t;qq++)
    {

        cin>>m;
        mp.clear();
        x=1;
        cin>>s1>>s2;
        mp[s1]=x;
        x++;
        mp[s2]=x;
        x++;
        arr[mp[s1]].push_back(mp[s2]);
        for(i=1;i<m;i++)
        {
            cin>>s1>>s2;
            if(mp.find(s1)==mp.end()) {mp[s1]=x;x++;}
            if(mp.find(s2)==mp.end()) {mp[s2]=x;x++;}
            arr[mp[s1]].push_back(mp[s2]);

        }
        if(isCycle()==true) cout<<"Case "<<qq<<": "<<"No"<<endl;
        else cout<<"Case "<<qq<<": "<<"Yes"<<endl;


//        for(i=1;i<10;i++)
//        {
//            vector < int > :: iterator it;
//            for(it=arr[i].begin();it!=arr[i].end();it++)
//            {
//                cout<<i<<" "<<(*it)<<endl;
//            }
//        }



    }
}
