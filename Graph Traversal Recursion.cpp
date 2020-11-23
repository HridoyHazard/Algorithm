#include<bits/stdc++.h>
using namespace std;

vector<int> adj[123456];
bool vis[123456]; //2D vector

/*
    Shahadat Hossain
    191-115-098
*/
void dfs(int u)
{
    vis[u]=true;  // Making U is visited
    cout<<u<<" ";  //printing U

    for(int i=0;i<(int)adj[u].size();i++) //loop will iterate according to how many nodes are connected to U
    {
        int v=adj[u][i]; //connected node is assigned to v
        if(vis[v]==false) //if v is not visited then this condition will work
        {
            dfs(v);  //recursion.it will iterate according to loop.after loop the recursion will stop.it will assign the V value in U [upper]
        }
    }
}

int main()
{
    int n,m,i; //variables
    while(scanf("%d%d",&n,&m)!=EOF) //EOF
    {
        memset(adj,0,sizeof(adj)); //making whole adj vector value 0

        for(i=0; i<m; i++)
        {
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
                                    //scanning like matrix (x,y) =(1,2),(1,3)
            adj[y].push_back(x);
        }
        memset(vis,false,sizeof(vis)); //making whole vis value false

        int source;
        cin>>source; //scanning source

        dfs(source); //calling dfs function

        cout<<"\n";  //newline
        cout<<"\n"; //newline
    }

    return 0;
}
