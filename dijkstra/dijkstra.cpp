#include<bits/stdc++.h>
using namespace std;
typedef pair< long long , long long >pii;
long long parent[1000000];
long long n;
 long long a[1000000];
list < pii >  *arr;
long long *dist;
long long Dijkstra(long long src)
{
    long long k=0;
 //   for(src=1;src<=n;src++)
    {

  //      if(parent[src]==0)
        {
           //  if(k>0) {cout<<"-1";return 0;}
            k++;
    priority_queue< pii , vector < pii > , greater < pii > > pq;
    pq.push(make_pair(0,src));
    dist[src]=0;
    parent[src]=src;
    while(pq.empty()==0)
    {

        long long u=pq.top().second;
    //     cout<<"* "<<u<<endl;
        pq.pop();
        list < pii  > :: iterator it;
        for(it=arr[u].begin();it!=arr[u].end();it++)
        {

            long long v=(*it).second;
             long long weight=(*it).first;
          //    cout<<"** "<<v<<" "<<weight<<endl;
             if(dist[v]>dist[u]+weight)
             {
               //  cout<<"u "<<u<<" v "<<v<<endl;
                 parent[v]=u;
                 dist[v]=dist[u]+weight;
          //       cout<<v<<" "<<dist[v]<<endl;
                 pq.push(make_pair(dist[v],v));
             }





        }
    }
        }
    }
    return 1;
}
int main()
{
    long long i,j,k,l,x,y,w,m;
    cin>>n>>m;
    arr=new list< pii >[n+1];
    dist=new long long [n+1];
  //  dist.assign(n+1,99999);
  for(i=1;i<=n;i++)
  {
      //dist[i]=999999999999;
      dist[i]=INFINITY;
  }
  memset(parent,0,sizeof(parent));
    for(i=1;i<=m;i++)
    {
        cin>>x>>y>>w;
        arr[x].push_back(make_pair(w,y));
        arr[y].push_back(make_pair(w,x));
    }

    long long a1=1;
    long long ppp=Dijkstra(1);
  //  if(ppp==0) return 0;

    for(i=1;i<=n;i++)
    {
      //  cout<<"* "<<i<<" "<<parent[i]<<endl;
    }

  //  cout<<parent[n];
   long long ff=n;
 //  cout<<ff<<" ";
   a[1]=ff;
   a1++;
    while(ff!=1)
    {
    //    cout<<parent[ff]<<" ";
    if(parent[ff]==0) {cout<<"-1";return 0;}
      else if(parent[ff]!=ff)
      {
      a[a1]=parent[ff];
      a1++;
        ff=parent[ff];
    }

    }
    for(i=a1-1;i>=1;i--)
    {
        cout<<a[i]<<" ";
    }
}
