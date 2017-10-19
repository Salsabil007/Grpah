#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n,i,j,k,l,t,x,y;
    cin>>t;
    for(int qq=1;qq<=t;qq++)
    {
        cin>>n>>m;
        vector < int > arr[n];
        for(i=1;i<=m;i++)
        {
            cin>>x>>y;
            arr[x-1].push_back(y-1);
        }
        int visited[n];
        memset(visited,0,sizeof(visited));
        int sum=0;

      for(i=0;i<n;i++)
        {
             list < int > q;
            if(visited[i]==0)
            {
                sum++;
                visited[i]=1;

                q.push_back(i);
               while(!q.empty())
                {
                    int v=q.front();
                    q.pop_front();
                    vector < int > :: iterator it;
                    for(it=arr[v].begin();it!=arr[v].end();it++)
                    {
                        if(visited[*it]==0)
                        {
                            visited[*it]=1;
                            q.push_back(*it);
                        }
                    }
                }
            }
        }
        cout<<"Case "<<qq<<": "<<sum<<endl;
    }
    return 0;
}
