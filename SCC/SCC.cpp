#include<bits/stdc++.h>
using namespace std;
//vector < vector < int > > g,gr;
//vector < vector < int > > gr;
vector < int > *g;
vector < int > *gr;
vector < int > visited,order,component;
void dfs1(int v)
{
    visited[v]=1;
    for(size_t i=0;i< g[v].size();i++)
    {
        if(visited[g[v][i]]==0) dfs1(g[v][i]);
    }
    order.push_back(v);
   // cout<<"v "<<v<<endl;
}
void dfs2(int v)
{
    visited[v]=1;
    component.push_back(v);
    for(size_t i=0;i< gr[v].size();i++)
    {
        if(visited[gr[v][i]]==0) dfs2(gr[v][i]);
    }
}
int main()
{
    int n,x,y,m;
    cin>>n>>m;
    g=new vector < int > [n];
    gr=new vector < int > [n];
  // g.resize(n,vector < int >)
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        g[x].push_back(y);
        gr[y].push_back(x);
    }
    visited.assign(n,0);
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0) dfs1(i);
    }
    visited.assign(n,0);
    for(int i=0;i<n;i++)
    {
        int v=order[n-1-i];
      //  cout<<"v "<<v<<endl;
        if(visited[v]==0)
        {
            dfs2(v);

           for(size_t j=0;j<component.size();j++)
            {
                cout<<component[j]<<" ";
            }
            cout<<endl;
            component.clear();
        }
    }
}
