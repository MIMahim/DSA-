///Graph representation
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,node,edges,choice,u,v;
    cin>>node>>edges;

    int adj[node+1][node+1];
    for(i=1; i<=node; i++)
        for(j=1; j<=node; j++) adj[i][j] = 0;

    cout<<"1 : Undirected graph"<<endl<<"2 : Directed graph"<<endl;
    cout<<"Enter your choice ";
    cin>>choice;   //if you choose any number other than 1,2 then it will count as 2

    int Max_edge;
    if(choice == 1) Max_edge = (node*(node-1))/2;
    else Max_edge = node*(node-1);

    edges = min(Max_edge,edges);

    for(i=1; i<=edges; i++)
    {
        cin>>u>>v;
        if(u<1 || v<1 || u>node || v>node)
        {
            cout<<"Invalid edges"<<endl;
            i--;
            continue;
        }

        adj[u][v] = 1;
        if(choice == 1) adj[v][u] = 1;
    }

    for(i=1; i<=node; i++)
    {
        for(j=1; j<=node; j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

