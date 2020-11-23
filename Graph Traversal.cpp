#include<bits/stdc++.h>
using namespace std;

vector<int> adj[123456]; 

/*
    Shahadat Hossain
    191-115-098
*/
int main()
{
    int n,m,i;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(adj,0,sizeof(adj));
        for(i=0; i<m; i++)
        {
            int x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<bool>visited(n+1,false); 

        int source;
        cin>>source; 

        stack<int> st;  

        st.push(source); 

        visited[source]=true; 

        while(!st.empty())  
        {
            int u=st.top();  
            st.pop();      

            cout<<u<<" ";  

            for(i=0; i<(int)adj[u].size(); i++) 
            {
                int v=adj[u][i];  
                if(!visited[v])  
                {
                    st.push(v); 
                    visited[v]=true;
                }
            }
        }
        cout<<"\n";  
        cout<<"\n"; 
    }

    return 0;
}
