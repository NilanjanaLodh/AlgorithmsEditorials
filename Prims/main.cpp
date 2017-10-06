#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int source;
    int dest;
    int w;
    edge(int s,int d, int wt)
    {
        source = s;
        dest = d;
        w = wt;
    }
};

bool operator>(const edge &e1 , const edge &e2)
{
    return e1.w > e2.w;
}

/**
Returns the spanning tree edges
n : vertices
m : edges
O(mlog m) time
O(n + m) auxiliary space
**/
vector<edge>  prim_spanning_tree(vector<vector<pair<int,int>> > &graph)
{
    int n = graph.size();
    priority_queue<edge, vector<edge> , greater<edge>> cut_edges;
    cut_edges.push(edge(0,0,0));
    vector<bool> intree(n,false);

    int treesize = 0;

    vector<edge> spanning_tree;
    while(treesize<n)
    {
        edge e = cut_edges.top();
        cut_edges.pop();
        if(intree[e.dest])
            continue;

        intree[e.dest] = true;
        treesize++;
        if(e.dest != e.source)
            spanning_tree.push_back(e);

        int &v = e.dest;
        for(pair<int,int> neighbour : graph[v])
        {
            int &u = neighbour.first;
            int &w = neighbour.second;
            if(!intree[u])
            {
                cut_edges.push(edge(v,u,w));
            }
        }
    }

    return spanning_tree;
}
int main()
{
    int n;
    int e;
    ifstream cin("weighted_graph.in");
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
     * each edge: ui -- vi , weight = wi
     */
    cin>>n>>e;
    vector<vector<pair<int,int>> > graph(n);
    while(e--)
    {
        int x,y,w;
        cin>>x>>y>>w;
        graph[x].push_back(make_pair(y,w));
        graph[y].push_back(make_pair(x,w)); // comment it out for directed graph
    }

    vector<edge> mst = prim_spanning_tree(graph);
    cout<<"The spanning tree edges are : "<<endl;
    for(edge e:mst)
    {
        cout<<e.source<<"-->"<<e.dest<<endl;
    }
}
