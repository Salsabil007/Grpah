#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
stack < int > stk;
bool visited[100];
int dist[100];
class graph
{
public:
    int v;
    vector < pii > *arr;
    graph(int a)
    {
        v=a;
        arr = new vector < pii > [a+1];
    }
    void addedge(int u,int v,int w)
    {
        arr[u].push_back(make_pair(v,w));
    }
    void topsort(int s)
    {
        visited[s]=true;

        vector < pii > :: iterator it;
        for(it=arr[s].begin();it!=arr[s].end();it++)
        {
            if(visited[(*it).first]==false)
            {
                topsort((*it).first);
            }

        }
         stk.push(s);

    }
    void longest_len(int v,int s)
    {
        for(int i=0;i<v;i++)
        {
            visited[i]=false;
            dist[i]=-INFINITY;
        }
        dist[s]=0;
        for(int i=0;i<v;i++)
        {
            if(visited[i]==false) topsort(i);
        }
        for(int i=0;i<v;i++)
        {
            int u=stk.top();
            stk.pop();
            vector < pii > :: iterator it;
            for(it=arr[u].begin();it!=arr[u].end();it++)
            {
                if(dist[(*it).first]<dist[u]+(*it).second  )
                {
                    dist[(*it).first]=dist[u]+(*it).second;
                }
            }
            cout<<dist[u]<<endl;

        }

    }

};

int main()
{
        int n,i,j,k,w,e,u,v;
        cin>>n>>e;
        graph q(n);
        for(i=1;i<=e;i++)
        {
            cin>>u>>v>>w;
            q.addedge(u,v,w);
        }
        q.longest_len(n,1);


}
