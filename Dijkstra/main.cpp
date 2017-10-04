#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
const int INF = INT_MAX;
/**
Returns the shortest distances of each of the vertices from the source vertex
**/
vector<int> dijkstra(const vector< vector<pair<int,int>> > &graph , int source = 0)
{
    int n = graph.size();
    vector<int> shortest_distance(n,INF);
    shortest_distance[source] = 0;

    //min-priority-queue of the vertices to be considered next
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > alarms;
    alarms.push(make_pair(0,source));

    while(!alarms.empty())
    {
        pair<int,int> p = alarms.top();
        alarms.pop();
        int v = p.second;
        int t = p.first;

        if(t > shortest_distance[v]) //this is an outdated alarm, thus should be skipped
            continue;

        for(pair<int,int> neighbour : graph[v])
        {
            int u = neighbour.first;
            int w = neighbour.second;
            if((t+w) < shortest_distance[u])
            {
                alarms.push(make_pair(t+w, u));
                shortest_distance[u] = t+w;
            }
        }
    }

    return shortest_distance;
}

int main()
{
    int n;
    int e;
    ifstream cin("weighted_graph.in");
    cin>>n>>e;
    vector<vector<pair<int,int>> > graph(n);
    while(e--)
    {
        int x,y,w;
        cin>>x>>y>>w;
        graph[x].push_back(make_pair(y,w));
        //graph[y].push_back(make_pair(x,w));//uncomment for undirected graph
    }

    vi shortest_distances = dijkstra(graph);
    for(int d : shortest_distances)
    {
        cout<<d<<" ";
    }
    cout<<endl;
}
