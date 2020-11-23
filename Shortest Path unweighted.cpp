#include<bits/stdc++.h>
using namespace std;
#define ll long long


/*

    Shahadat Hossain
    191-115-098

*/

vector<ll>D(123456);
int P[123456];

void bfs(int src,int nodes,vector<int>adjlist[]) //bfs function
{
    P[src]=1;
    D[src]=0;
    vector<bool>vis(nodes+1,false); //making whole nodes false
    queue<int>q;  //queue
    q.push(src);  //pushing source value into queue
    vis[src]=true; // suppose source value is 0 so vis[0]=true; 0 nodes will be true means it's visited.
    while(!q.empty()) //while stack is not empty
    {
        int u=q.front();  //queue front value will assigned to u
        q.pop();  //popping queue it will remove front value from the queue
        for(int i=0; i<(int)adjlist[u].size(); i++)  ////loop will be iterate according to how many adjlist value are connected with node[u]
        {
            int v=adjlist[u][i];  //connected adj[u][i] will be assigned to v. like adj[0][1] is connected to each other therefore v=1
            if(!vis[v])  // if v is not visited then this condition will work.
            {
                D[v]=D[u]+1; //it's counting the next distanced nodes
                P[v]=u;        //u value is assigned to parents value's
                q.push(v);   //pushing v to queue
                vis[v]=true;  //v is assigned as true
            }
        }
    }
}

void print(int src,int n) //print function
{
    if(n==src)  //if node and source are same then this condition will work
    {
        cout<<n<<" ";  //printing nodes
        return ;
    }
    print(src,P[n]);  //recursion
    cout<<n<<" "; //printing nodes
}

vector<int>v[123456]; //2D vector

int main()
{
    int n,m;
    while(cin>>n>>m) //eof scanning nodes and edges
    {
        memset(v,0,sizeof(v)); //whole v vector filled with 0
        while(m--)
        {
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
                                //scanning like matrix (x,y) =(1,2),(1,3)
            v[y].push_back(x);
        }
        int source;
        cin>>source;  //scanning source
        bfs(source,n,v); //calling bfs function

        cout<<"From The Source "<<source<<" : \n"; //printing source
        cout<<"________________\n";

        for(int i=0; i<n; i++)
        {
            if(D[i]!=0)  //if D[i] isn't equal to 0 which means d[i] was already visited nodes path
            {
                cout<<"Minimum "<<D[i]<<" edges needed to reach "<<i<<endl; //it will print minimum edges to reach destination
                cout<<"Path Taken ";
                print(source,i); //calling print function to print path's
                cout<<endl;
                cout<<endl;
            }
            else //if any d[i] is equal to 0 that means this node didn't visited path because none of it's edges has connected
            {
                if(i!=0 && (source==i)!=1) //if source value is not equal to i then this condition will work
                {
                    cout<<i<<" is not reachable.\n"; //it will print not reachable
                    cout<<endl;
                }
            }
        }

    }

    return 0;
}
