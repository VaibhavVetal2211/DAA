#include<bits/stdc++.h>
using namespace std;

int main()
{
    int V,E;
    cout<<"Enter the number of vertices"<<endl;
    cin>>V;
    cout<<"Enter the number of edges"<<endl;
    cin>>E;
    vector<vector<int>> edges(E, vector<int>(3));

    for(int i=0;i<E;i++)
    {
        int u,v,wt;

        cout<<"Enter the u and v for edge (u->v) "<<endl;
        cin>>u>>v;
      
        cout<<"Enter the weight of edge (u->v) "<<endl;
        cin>>wt;

        edges[i][0]=u;
        edges[i][1]=v;
        edges[i][2]=wt;
    }


    int s,d;
    cout<<"Enter source:"<<endl;
    cin>>s;
    cout<<"Enter destination"<<endl;
    cin>>d;

    vector<int>dist(V,1e8);   //initalize with 1e8  used to simulate infinity 

    dist[s]=0;  //initalize the source to 0


    // Bellmanford algo
    for(int i=0;i< V-1 ;i++)
    {

        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt =it[2];

            if(dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt ;
            }

        }
    }
    
    for(auto it : edges)    // oen more iteration for checking the negative cycle
        {
            int u = it[0];
            int v = it[1];
            int wt =it[2];

            if(dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                cout<<"Graph have negative cycle"<<endl;
                return 0;
            }

        }

    cout<<"Shortest path from"<<s<<"->"<<d<<"is: "<<dist[d]<<endl;


    cout<<"Following are the shortest path from source to all vertices:"<<endl;
    for(int i=0;i<dist.size();i++)
    {
        cout<<"Distance"<<s<<"->"<<i<<" : "<<dist[i]<<endl;
    }


return 0;




}