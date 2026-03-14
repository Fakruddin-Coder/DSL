#include <iostream>
using namespace std;

void mst(int V,string city[])
{
    int Graph[V][V]={0};

    for(int i=0;i<V;i++)
    {
        for(int j=i+1;j<V;j++)
        {
            cout<<"Enter Dist From: "<<city[i]<<" to "<<city[j]<<endl;
            cin>>Graph[i][j];

            Graph[j][i]=Graph[i][j];
        }
    }
    
    int key[V],parent[V];
    bool visit[V];

    for(int i=0;i<V;i++)
    {
        key[i]=999;
        parent[i]=-1;
        visit[i]=false;
    }

   key[0]=0;

    for(int i=0;i<V-1;i++)
    {
        int u,min=999;

        for(int j=0;j<V;j++)
        {
            if(!visit[j] && key[j]<min)
            {
                min=key[j];
                u=j;
            }
        }

        visit[u]=true;

        for(int v=0;v<V;v++)
        {
            if(!visit[v] && Graph[u][v]!=0 && Graph[u][v]<key[v])
            {
                key[v]=Graph[u][v];
                parent[v]=u;
            }
        }
    }

    int total=0;

    cout<<"MST Graph Connection\n\n";
    for(int i=1;i<V;i++)
    {
        cout<<city[parent[i]]<<" -> "<<city[i]<<" Cost: "<<key[i]<<endl;
        total=total+key[i];   
    }

    cout<<"\nTotal Cost(Km): "<<total;


}

int main()
{
    int V;

    cout<<"Enter The Number of City: ";
    cin>>V;

    string city[V];

     cout<<"Enter The Cities Name: ";
    for(int i=0;i<V;i++)
    {
        cin>>city[i];
    }

    mst(V,city);

}

//================= OUTPUT PART =================


// Enter The Number of City: 4
// Enter The Cities Name: Mumbai
// Pune
// Shirdi
// Aurangabad
// Enter Dist From: Mumbai to Pune
// 150
// Enter Dist From: Mumbai to Shirdi
// 250
// Enter Dist From: Mumbai to Aurangabad
// 300
// Enter Dist From: Pune to Shirdi
// 100
// Enter Dist From: Pune to Aurangabad
// 200
// Enter Dist From: Shirdi to Aurangabad
// 150
// MST Graph Connection

// Mumbai -> Pune Cost: 150
// Pune -> Shirdi Cost: 100
// Shirdi -> Aurangabad Cost: 150

// Total Cost(Km): 400