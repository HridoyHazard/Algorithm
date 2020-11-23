#include<bits/stdc++.h>
using namespace std;

/*
        Shahadat Hossain
        191-115-098
*/

int parent[123456];

void sssp_dijkstra(int src, int tot, vector<pair<int , int > >adj[])
{
    vector<int>dist(tot+1, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;

    pq.push(make_pair(0, src));
    parent[src]=-1;
    dist[src]=0;

    while(!pq.empty())
    {
        pair<int,int>curnode= pq.top();
        pq.pop();

        int u=curnode.second;
        int n_du=curnode.first;
        if(n_du>dist[u])
        {
            continue;
        }
        int sz=adj[u].size();
        for(int i=0; i<sz; i++)
        {
            int v=adj[u][i].first;
            int w_uv=adj[u][i].second;

            if(dist[u]+w_uv<dist[v])
            {
                dist[v]=dist[u]+w_uv;
                parent[v]=u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    for(int i=1; i<=tot; i++)
    {
        if(dist[i]!=0)
        {
            cout<<i<<" "<<dist[i]<<endl;
        }
    }
    cout<<endl;
}

void printpath(int source,int node)
{

    if(node==source)
    {
        cout<<node<<" ";
        return ;
    }
    printpath(source,parent[node]);
    cout<<node<<" ";
}

vector<pair<int, int> >adjlistwted[123456];

int main ()
{
    int n, m, source, target;
    while(cin>>n>>m)
    {

        memset(adjlistwted,0,sizeof(adjlistwted));

        for(int i=0; i<m; i++)
        {
            int u, v, w;
            cin>>u>>v>>w;
            adjlistwted[u].push_back(make_pair(v, w));
        }
        cin>>source>>target;
        cout<<"Minimum distances from Source"<<" "<<source<<" "<<"to other nodes"<<endl;
        sssp_dijkstra(source, n, adjlistwted);
        cout<<"Path to the target node"<<": "<<target<<endl;
        cout<<"Path taken"<<": ";
        printpath(source, target);
        cout<<endl;
    }
    return 0;
}
