#include<bits/stdc++.h>
using namespace std;
vector < int > arr[20005];
int  main()
{
    int t,i,j,k,l,n,m;
    cin>>t;
    for(int qq=1;qq<=t;qq++)
    {
        cin>>n;
      //  arr = new vector < int > [(2*n)+1];
        int color[20005+1];
        memset(color,0,sizeof(color));
        int ara[20005+1];
        memset(ara,0,sizeof(ara));
         int x,y;
         int black=0,red=0;
         for(i = 0; i < 20005; i++)
			arr[i].clear();
        for(i=1;i<=n;i++)
        {

            cin>>x>>y;
            ara[x]=-1;
            ara[y]=-1;
            arr[x].push_back(y);
            arr[y].push_back(x);
        }
        for(i=0;i<20005;i++)
        {
        if(arr[i].empty()==0 && color[i]==0)
        {
        queue < int > q;
        color[i]=1;
        black++;

        q.push(i);
        while(q.empty()==0)
        {
            int s=q.front();
            ara[s]=1;
            q.pop();
            vector < int > :: iterator it;
            for(it=arr[s].begin();it!=arr[s].end();it++)
            {
                if(color[(*it)]==0)
                {
                    if(color[s]==1) {color[(*it)]=-1;red++;}
                    else {color[(*it)]=1;black++;}
                    q.push(*it);
                }
            }

        }
        }
        }
//        int sum1=0,sum2=0;
//        for(i=0;i<=20005;i++)
//        {
//            if(color[i]==1) sum1++;
//            else if(color[i]==-1) sum2++;
//        }
        cout<<"Case "<<qq<<": "<<max(black,red)<<endl;


    }
}
