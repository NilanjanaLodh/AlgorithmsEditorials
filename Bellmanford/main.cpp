#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
const int INF = INT_MAX/2;

/**
Returns a new graph where the edges are all flipped
u --> v becomes v --> u
**/
vector< vector<pair<int,int>> > reverse_graph(const vector< vector<pair<int,int>> > &graph)
{
    int n = graph.size();
    vector< vector<pair<int,int>> > reversed_graph(n);

    for(int u=0;u<n;u++)
    {
        for(pair<int,int> neighbour : graph[u])
        {
            int &v = neighbour.first;
            int &w = neighbour.second;

            reversed_graph[v].push_back(make_pair(u,w));
        }
    }

    return reversed_graph;
}

/**
Returns the shortest distances of each of the vertices from the source vertex
using the bellman ford algorithm
O(m + n) space
O(mn) time
**/
vector<int> bellman_ford(const vector< vector<pair<int,int>> > &graph , int source = 0)
{
    int n = graph.size();
    vector< vector<pair<int,int>> > revgraph = reverse_graph(graph);

    vector<int> shortest_distance_so_far(n,INF);
    shortest_distance_so_far[source] = 0;

    for(int pathlen = 1; pathlen<n ;pathlen++)
    {
        vi new_dist = shortest_distance_so_far;
        for(int v = 0;v<n;v++)
        {
            for(pair<int,int> neighbour : revgraph[v])
            {
                int &u = neighbour.first;
                int &w = neighbour.second;
                new_dist[v] = min(new_dist[v] , shortest_distance_so_far[u]+w);
            }
        }
        shortest_distance_so_far = new_dist;
    }

    return shortest_distance_so_far;
}

int main()
{
    int n;
    int e;
    ifstream cin("neg_weighted_graph.in");
    /**
     * Input format:
     * n e
     * u1 v1 w1
     * u2 v2 w2
     * .
     * .
     * un vn wn
     * 
     * n : number of vertices
     * e : number of edges
     * each edge: ui -- > vi , weight = wi 
     */
    cin>>n>>e;
    vector<vector<pair<int,int>> > graph(n);
    while(e--)
    {
        int x,y,w;
        cin>>x>>y>>w;
        graph[x].push_back(make_pair(y,w));
    }

    vector<int> shortest_distances = bellman_ford(graph);
    for(int d : shortest_distances)
    {
        cout<<d<<" ";
    }
    cout<<endl;
}
