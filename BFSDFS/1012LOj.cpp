#include<bits/stdc++.h>
using namespace std;
int sum=1;
char arr[105][105];

void DFS(int n,int m,int i,int j)
{
   // int sum=1;
    int a,b,c;
    arr[i][j]='*';
    for(a=1;a<=4;a++)
    {
        if(i-1>=0 && arr[i-1][j]=='.')
        {
            sum++;
            DFS(n,m,i-1,j);
        }
        else if(i+1<n && arr[i+1][j]=='.')
        {
            sum++;
            DFS(n,m,i+1,j);
        }
        else if(j-1>=0 && arr[i][j-1]=='.')
        {
            sum++;
            DFS(n,m,i,j-1);
        }
        else if(j+1<m && arr[i][j+1]=='.')
        {
            sum++;
            DFS(n,m,i,j+1);
        }
    }
    return ;
}
int main()
{
    int t,i,j,k,l,q,m,n;
    char x,y;
    cin>>t;
    for(q=1;q<=t;q++)
    {
        sum=1;
        int indn,indm;
        cin>>m>>n;
     //   char arr[n][m];
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>arr[i][j];
                if(arr[i][j]=='@') {indn=i;indm=j;}
            }
        }
        DFS(n,m,indn,indm);
        cout<<"Case "<<q<<": "<<sum<<endl;
    }
}
