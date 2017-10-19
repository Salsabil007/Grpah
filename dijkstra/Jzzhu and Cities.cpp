#include<bits/stdc++.h>
using namespace std;
typedef pair< long long , long long >pii;
long long parent[300000+1];
//long long train[300000+1],cost[300000+1];
long long n;
 long long a[300000+1];
list < pii >  *arr;
long long *dist;

long long Dijkstra(long long src)
{
 //   long long k=0;
 //   for(src=1;src<=n;src++)
    {

  //      if(parent[src]==0)
        {
           //  if(k>0) {cout<<"-1";return 0;}
        //    k++;
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
    long long m,k,i,j,l;
    cin>>n>>m>>k;
   // long long train[m],cost[m];
    arr=new list< pii >[n+1];
    dist=new long long [n+1];
    for(i=1;i<=n;i++)
  {
      //dist[i]=999999999999;
      dist[i]=INFINITY;
  }
   memset(parent,0,sizeof(parent));
   int f=0;
     long long sum=0;
    for(i=1;i<=m;i++)
    {
        long long x,y,w;
        cin>>x>>y>>w;
  //      if(((x==1 || y==1) && w==1)==0) f=1;
        arr[x].push_back(make_pair(w,y));
        arr[y].push_back(make_pair(w,x));
    }
    map< long long, long long > mp;
    for(i=0;i<k;i++)
    {
        long long x,y;
        cin>>x>>y;
  //      train[i]=x;
   //     cost[i]=y;
   if(mp[x]!=0)
   {
       sum++;
       if(mp[x]>y) mp[x]=y;
   }
    else mp[x]=y;
    }
    map < long long , long long > :: iterator ii;
    for(ii=mp.begin();ii!=mp.end();ii++)
    {
        cout<<"*it "<<(*ii).first<<" "<<(*ii).second<<endl;
    }
 //   cout<<"sum "<<sum<<endl;
    Dijkstra(1);
    cout<<"** "<<dist[1]<<" "<<dist[2]<<" "<<dist[5]<<endl;
  //  if(f==1)

    //cout<<dist[1]<<" * "<<dist[2]<<endl;
  /*  for(i=0;i<k;i++)
    {
        long long pp=train[i];
        if(dist[pp]<=cost[i])  sum++;
    }*/
    map < long long , long long > :: iterator it;
    for(it=mp.begin();it!=mp.end();it++)
    {
        cout<<"In map "<<(*it).first<<" "<<(*it).second<<endl;
       cout<<dist[(*it).first]<<endl;
        if(dist[(*it).first]>(*it).second) {cout<<"in sum"<<endl;long long ll=dist[(*it).first];dist[(*it).first]=(*it).second;

        for(i=1;i<=n;i++)
        {
            if(i!=(*it).first && parent[i]==(*it).first) {dist[i]=dist[i]-ll+dist[(*it).first];}
        }
        }
        else if(dist[(*it).first]<=(*it).second) {cout<<"in sum"<<endl;sum++;}
    }
    cout<<sum;
}


