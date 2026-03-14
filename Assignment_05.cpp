#include <iostream>
#include <vector>
using namespace std;

void SSSP(int V, string city[])
{
    int Graph[V][V] = {0};

    // Input distances between home and marriage halls
    for (int i = 0; i < V; i++)
    {
        for (int j = i + 1; j < V; j++)
        {
            cout << "Enter Distance From: " << city[i] << " to " << city[j] << endl;
            cin >> Graph[i][j];
            Graph[j][i] = Graph[i][j];
        }
    }

    int key[V];        // Shortest distance from source
    int parent[V];     // Previous node in path
    bool visit[V];     // Visited nodes

    for (int i = 0; i < V; i++)
    {
        key[i] = 99999; // Infinity
        parent[i] = -1;
        visit[i] = false;
    }

    key[0] = 0; // Source is home

    // Dijkstra's algorithm
    for (int i = 0; i < V; i++)
    {
        int u = -1;
        int minDist = 99999;

        for (int j = 0; j < V; j++)
        {
            if (!visit[j] && key[j] < minDist)
            {
                minDist = key[j];
                u = j;
            }
        }

        if (u == -1) break;
        visit[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!visit[v] && Graph[u][v] != 0)
            {
                if (key[u] + Graph[u][v] < key[v])
                {
                    key[v] = key[u] + Graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    // Shortest paths from Home
    cout << "\nShortest paths from " << city[0] << " (Home):\n";
    for (int i = 1; i < V; i++)
    {
        vector<int> path;
        int j = i;
        while (j != -1)
        {
            path.push_back(j);
            j = parent[j];
        }

        for (int k = path.size() - 1; k >= 0; k--)
        {
            cout << city[path[k]];
            if (k != 0) cout << " -> ";
        }

        cout << "  Cost: " << key[i] << endl;
    }

    // Step-by-step routes from Home
    cout << "\nRoute From " << city[0] << " (Home):\n";
    for (int i = 1; i < V; i++)
    {
        vector<int> path;
        int j = i;
        while (j != -1)
        {
            path.push_back(j);
            j = parent[j];
        }

        for (int k = path.size() - 1; k >= 0; k--)
        {
            cout << city[path[k]];
            if (k != 0) cout << " -> ";
        }
        cout << endl;
    }
}

int main()
{
    int V;
    cout << "Enter The Number of Locations (Home + Marriage Halls): ";
    cin >> V;

    string city[V];
    cout << "Enter Your Home First, Then Marriage Hall Names:\n";
    for (int i = 0; i < V; i++)
    {
        cin >> city[i];
    }

    SSSP(V, city); // Single Source Shortest Path
}


//================= OUTPUT PART ==================

// Enter The Number of Locations (Home + Marriage Halls): 3
// Enter Your Home First, Then Marriage Hall Names:
// Home M1 M2

// Enter Distance From: Home to M1
// 5
// Enter Distance From: Home to M2
// 10
// Enter Distance From: M1 to M2
// 3


// Shortest paths from Home (Home):
// Home -> M1  Cost: 5
// Home -> M2  Cost: 8

// Route From Home (Home):
// Home -> M1
// Home -> M1 -> M2


// ✅ Explanation:

// Distance from Home → M2 directly is 10.

// But Home → M1 → M2 is shorter: 5 + 3 = 8.

// Dijkstra automatically chooses the shortest path.

// The route shows you the step-by-step path.
