#include<bits/stdc++.h>
using namespace std;
typedef pair<long long ,long long >pii;
map < pii , int > mp;
long long  ifk[100000+1];
 vector < pii > *arr;
class graph
{
public:
    long long  v;

    graph(long long  a)
    {
        v=a;
        arr = new vector < pii > [a+1];
    }
    void addedge(long long  u,long long  v,long long  w)
    {
       arr[u].push_back(make_pair(v,w));
        arr[v].push_back(make_pair(u,w));
    }

//    void BFS(long long  s,long long  v)
//    {
//        long long  i;
//
//        visited[s]=true;
//        dist[s]=0;
//        queue < long long  > q;
//        q.push(s);
//        while(q.empty()==0)
//        {
//            long long  u=q.front();
//            q.pop();
//            vector < pii > :: iterator  it;
//            for(it=arr[u].begin();it!=arr[u].end();it++)
//            {
//                if(visited[(*it).first]==false && ifk[(*it).first]==0)
//                {
//                visited[(*it).first]=true;
//                dist[(*it).first]=dist[u]+(*it).second;
//                q.push((*it).first);
//                }
//            }
//
//        }
//
//    }
};
int  main()
{
        long long  n,m,k,i,j,u,v,w,exmin=INFINITY;
        cin>>n>>m>>k;
        graph g(n);

        for(i=1;i<=m;i++)
        {
            long long  f=0;
            cin>>u>>v>>w;
           if( mp[make_pair(u,v)]==0) mp[make_pair(u,v)]=w;
           else if(mp[make_pair(u,v)]!=0 && mp[make_pair(u,v)]>w) mp[make_pair(u,v)]=w;
            if(w<exmin) exmin=w;
         //   if(arr[u].)
         vector < pii > :: iterator  it,it1;
         for(it=arr[u].begin();it!=arr[u].end();it++)
         {
             if((*it).first==v)
             {
                  f=1;
                 if((*it).second>w)
                 {

                     (*it).second=w;
                     for(it1=arr[v].begin();it1!=arr[v].end();it1++)
                     {
                         if((*it1).first==u)
                         {
                              (*it1).second=w;
                         }

                     }
                 }
             }
         }
            if(f==0)g.addedge(u,v,w);
        }

        if(k==0) {cout<<"-1";return 0;}
        else
        {
            long long  x,y;
            long long  l=0;
            long long  minn=INFINITY;
            long long  kk[k+1],kkk;
            for(i=1;i<=k;i++)
            {
                cin>>kkk;
                kk[i]=kkk;
                ifk[kkk]=1;
            }

               for(long long  ii=1;ii<=k;ii++)
               {
                   vector < pii >::
                        iterator it2;
                    for(it2=arr[kk[ii]].begin();it2!=arr[kk[ii]].end();it2++)
                    {
                        if((*it2).second < minn && ifk[(*it2).first]==0 )
                        {
                            minn=(*it2).second;
                            l=1;
                            if(minn==exmin) {cout<<minn;return 0;}
                        }
                    }

               }

            if(l==1) cout<<minn;
            else cout<<"-1";
        }
}
